/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bts <bts@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 00:43:10 by bts               #+#    #+#             */
/*   Updated: 2020/05/16 00:43:10 by bts              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static unsigned int	get_num(const char sym)
{
	int num;

	num = 0;
	if (sym >= 'A' && sym <= 'F')
		num = sym - 'A' + 10;
	else if (sym >= 'a' && sym <= 'f')
		num = sym - 'a' + 10;
	else if (sym >= '0' && sym <= '9')
		num = sym - '0';
	return (num);
}

static void			set_value(t_color *color, int ct, unsigned int value)
{
	if (ct == 2)
		color->r = value;
	else if (ct == 4)
		color->g = value;
	else
		color->b = value;
}

t_color				get_color(const char *color_data)
{
	int				ct;
	t_color			color;
	unsigned int	value;

	if (color_data[0] != '#' || !color_data[0])
		return ((t_color){0x0, 0x0, 0x0});
	ct = 0;
	while (color_data[++ct])
	{
		if (ct % 2)
			value = 0x0;
		if ((color_data[ct] >= 'A' && color_data[ct] <= 'F') ||
			(color_data[ct] >= 'a' && color_data[ct] <= 'f') ||
			(color_data[ct] >= '0' && color_data[ct] <= '9'))
			value |= get_num(color_data[ct]) << 4 * (ct % 2);
		else
			return ((t_color){0x0, 0x0, 0x0});
		if (ct == 2 || ct == 4 || ct == 6)
			set_value(&color, ct, value);
	}
	if (ct != 7)
		return ((t_color){0x0, 0x0, 0x0});
	return (color);
}
