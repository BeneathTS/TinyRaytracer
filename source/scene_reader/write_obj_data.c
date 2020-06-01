/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_obj_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bts <bts@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 00:42:59 by bts               #+#    #+#             */
/*   Updated: 2020/05/16 00:43:00 by bts              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	check_num_n_space_skip(const char *num)
{
	int		ct;
	int		ct2;
	char	dot_num;
	char	sign_num;

	ct = 0;
	dot_num = 0;
	sign_num = 0;
	ft_ss(&ct, num);
	ct2 = ct;
	while (num[ct])
	{
		if (num[ct] == '.')
			++dot_num;
		else if (num[ct] == '-' || num[ct] == '+')
			++sign_num;
		else if (num[ct] < '0' || num[ct] > '9' ||
		dot_num >= 2 || sign_num >= 2)
			exit(-1);
		++ct;
	}
	return (ct2);
}

float		get_float_value(const char *num)
{
	int		ct;
	char	znk;
	float	res;
	float	f_part;

	res = 0.0;
	f_part = 0.0;
	znk = 1;
	ct = check_num_n_space_skip(num);
	if (num[ct] == '-' || num[ct] == '+')
		if (num[ct++] == '-')
			znk = -1;
	while (num[ct] >= '0' && num[ct] <= '9' && num[ct] != '.')
		res = (res * 10) + (num[ct++] - '0');
	if (!num[ct] || (num[ct] != '.' && 
	(num[ct] <= '0' || num[ct] >= '9')))
		return (res * znk);
	ct = ft_strlen(num);
	while (num[--ct] != '.' && ct > 0)
		f_part = (f_part * 0.10) + (num[ct] - '0') * 0.10;
	return ((res + f_part) * znk);
}

static void	write_data(char data_type, const char **data, t_scene *scene)
{
	if (data_type == position)
	{
		scene->objects->position.x = get_float_value(data[0]);
		scene->objects->position.y = get_float_value(data[1]);
		scene->objects->position.z = get_float_value(data[2]);
	}
	else if (data_type == direction)
	{
		scene->objects->direction.x = get_float_value(data[0]);
		scene->objects->direction.y = get_float_value(data[1]);
		scene->objects->direction.z = get_float_value(data[2]);
		scene->objects->direction = vec_normalize(scene->objects->direction);
	}
}

static void	pos_n_dir(char data_type, const char *buffer, t_scene *scene)
{
	char	**data;
	int		ct;

	data = ft_strsplit(buffer, ',');
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

void		write_object(char data_type, const char *buf, t_scene *scene)
{
	if (data_type == position || data_type == direction)
		pos_n_dir(data_type, buf, scene);
	else if (data_type == color)
		scene->objects->color = get_color(buf);
	else if (data_type == radius)
		scene->objects->radius = get_float_value(buf);
	else if (data_type == specular)
		scene->objects->specular = get_float_value(buf);
	else if (data_type == reflective)
		scene->objects->reflective = get_float_value(buf);
}
