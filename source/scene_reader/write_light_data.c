/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_light_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bts <bts@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 00:43:37 by bts               #+#    #+#             */
/*   Updated: 2020/05/16 00:43:54 by bts              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	pos_n_dir(char data_type, const char *buffer, t_scene *scene)
{
	char	**data;
	int		ct;

	data = ft_strsplit(buffer, ',');
	if (data_type == position)
	{
		scene->lights->position.x = get_float_value(data[0]);
		scene->lights->position.y = get_float_value(data[1]);
		scene->lights->position.z = get_float_value(data[2]);
	}
	else if (data_type == direction)
	{
		scene->lights->direction.x = get_float_value(data[0]);
		scene->lights->direction.y = get_float_value(data[1]);
		scene->lights->direction.z = get_float_value(data[2]);
	}
	ct = -1;
	while (data[++ct])
		free(data[ct]);
	free(data);
}

static void	write_light_type(const char *buffer, t_scene *scene)
{
	if (ft_strequ(buffer, "point"))
		scene->lights->type = point;
	else if (ft_strequ(buffer, "directional"))
		scene->lights->type = directional;
	else if (ft_strequ(buffer, "ambient"))
		scene->lights->type = ambient;
}

void		write_light(char data_type, const char *buffer, t_scene *scene)
{
	if (data_type == position || data_type == direction)
		pos_n_dir(data_type, buffer, scene);
	else if (data_type == light_type)
		write_light_type(buffer, scene);
	else if (data_type == intensity)
		scene->lights->intencity = get_float_value(buffer);
}
