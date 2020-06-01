/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_cam_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bts <bts@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 00:44:54 by bts               #+#    #+#             */
/*   Updated: 2020/05/16 22:13:29 by bts              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	write_data(const char data_type, const char **data, t_scene *scene)
{
	if (data_type == position)
	{
		scene->cam->position.x = get_float_value(data[0]);
		scene->cam->position.y = get_float_value(data[1]);
		scene->cam->position.z = get_float_value(data[2]);
	}
	else if (data_type == direction)
	{
		scene->cam->direction.x = -get_float_value(data[0]) * 0.0175f;
		scene->cam->direction.y = get_float_value(data[1]) * 0.0175f;
		scene->cam->direction.z = get_float_value(data[2]) * 0.0175f;
	}
}

void		write_cam(const char data_type, const char *buffer, t_scene *scene)
{
	char	**data;
	int		ct;

	data = ft_strsplit(buffer, ',');
	if (!scene->cam)
		scene->cam = cam_init();
	ct = -1;
	while (data[++ct])
		;
	if (ct != 3)
		exit(-1);
	write_data(data_type, (const char **)data, scene);
	ct = -1;
	while (data[++ct])
		free(data[ct]);
	free(data);
}
