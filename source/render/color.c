/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bts <bts@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 22:16:50 by bts               #+#    #+#             */
/*   Updated: 2020/05/16 22:16:51 by bts              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color			reflection_color(t_color basic_color, t_color reflected_color)
{
	t_color res;

	res.r = basic_color.r + reflected_color.r;
	if (res.r > 255)
		res.r = 255;
	res.g = basic_color.g + reflected_color.g;
	if (res.g > 255)
		res.g = 255;
	res.b = basic_color.b + reflected_color.b;
	if (res.b > 255)
		res.b = 255;
	return (res);
}

t_color			color_mult_num(t_color color, float num)
{
	t_color res;

	res.r = color.r * num;
	if (res.r > 255)
		res.r = 255;
	res.g = color.g * num;
	if (res.g > 255)
		res.g = 255;
	res.b = color.b * num;
	if (res.b > 255)
		res.b = 255;
	return (res);
}

unsigned int	convert_color_chanels(t_color color)
{
	return ((color.r << 16) | (color.g << 8) | color.b);
}
