/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bts <bts@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 00:05:17 by bts               #+#    #+#             */
/*   Updated: 2020/05/16 22:06:44 by bts              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static char	*cut_buffer(char *buffer)
{
	char	*new_buffer;
	int		ct;

	ct = 0;
	while (buffer[ct] != ':')
		++ct;
	ct += 2;
	new_buffer = ft_strchrdup(&buffer[ct], ';');
	free(buffer);
	return (new_buffer);
}

static char	check_data_type(char *buf, const char obj_type)
{
	if (ft_strequ(buf, "\tposition:"))
		return (position);
	else if (ft_strequ(buf, "\tdirection:"))
		return (direction);
	else if (obj_type != light && obj_type != cam)
	{
		if (ft_strequ(buf, "\tradius:"))
			return (radius);
		else if (ft_strequ(buf, "\tcolor:"))
			return (color);
		else if (ft_strequ(buf, "\tspecular:"))
			return (specular);
		else if (ft_strequ(buf, "\treflective:"))
			return (reflective);
	}
	else if (obj_type == light && ft_strequ(buf, "\tintensity:"))
		return (intensity);
	else if (obj_type == light && ft_strequ(buf, "\ttype:"))
		return (light_type);
	return (error);
}

char		get_data_type(char **buffer, const char obj_type)
{
	char	**split;
	char	type;
	int		ct;

	ct = -1;
	if (!(split = ft_strsplit(*buffer, ' ')))
		exit(-1);
	if ((type = check_data_type(split[0], obj_type)) == error)
		exit(-1);
	while (split[++ct])
		free(split[ct]);
	free(split);
	*buffer = cut_buffer(*buffer);
	return (type);
}

static void	check_obj_type(int fd, char *type, t_scene *scene)
{
	char	*buffer;
	int		status;

	status = get_next_line(fd, &buffer);
	if (status == error || status == done)
		exit(-1);
	if (ft_strequ(buffer, "cam:") && !scene->cam)
		*type = cam;
	else if (ft_strequ(buffer, "sphere:"))
		*type = sphere;
	else if (ft_strequ(buffer, "cone:"))
		*type = cone;
	else if (ft_strequ(buffer, "plane:"))
		*type = plane;
	else if (ft_strequ(buffer, "cylinder:"))
		*type = cylinder;
	else if (ft_strequ(buffer, "light:"))
		*type = light;
	else
		exit(-1);
	free(buffer);
}

char		get_obj_type(const int fd, t_scene *scene)
{
	char type;

	check_obj_type(fd, &type, scene);
	if (!scene->objects && type != light && type != cam)
		scene->objects = object_init(type, NULL);
	else if (scene->objects && type != light && type != cam)
	{
		scene->objects->next = object_init(type, scene->objects);
		scene->objects = scene->objects->next;
	}
	if (!scene->lights && type == light)
		scene->lights = light_init(NULL);
	else if (scene->lights && type == light)
	{
		scene->lights->next = light_init(scene->lights);
		scene->lights = scene->lights->next;
	}
	return (type);
}
