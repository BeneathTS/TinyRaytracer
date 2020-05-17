/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bts <bts@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 00:41:53 by bts               #+#    #+#             */
/*   Updated: 2020/05/16 20:03:20 by bts              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static char	write_data(char **buffer, char obj_type, t_scene *scene)
{
	char data_type;

	data_type = get_data_type(buffer, obj_type);
	if (obj_type == cam)
		write_cam(data_type, *buffer, scene);
	else if (obj_type != light)
		write_object(data_type, *buffer, scene);
	else
		write_light(data_type, *buffer, scene);
	return (data_type);
}

static char	rd_data_from_buf(const int fd, t_scene *scene, const char obj_type)
{
	char	data_type;
	char	*buffer;
	int		read_status;

	if ((get_next_line(fd, &buffer)) != 1)
		exit(-1);
	if (*buffer != '{')
		exit(-1);
	data_type = empty;
	while (*buffer)
	{
		free(buffer);
		read_status = get_next_line(fd, &buffer);
		if (read_status == error)
			exit(-1);
		if (*buffer == '}')
		{
			if (data_type == empty)
				exit(-1);
			break ;
		}
		data_type = write_data(&buffer, obj_type, scene);
	}
	free(buffer);
	return (read_status);
}

void		read_scene(const char *scene_name, t_scene *scene)
{
	char	*buffer;
	char	status;
	int		fd;

	if ((fd = open(scene_name, O_RDONLY)) < 0)
		exit(-1);
	status = reading;
	while (status == reading)
	{
		status = rd_data_from_buf(fd, scene, get_obj_type(fd, scene));
		if (get_next_line(fd, &buffer) == 0)
			status = done;
		free(buffer);
	}
	if (!scene->cam)
		scene->cam = cam_init();
	close(fd);
}
