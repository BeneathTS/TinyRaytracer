/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bts <bts@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 22:11:42 by bts               #+#    #+#             */
/*   Updated: 2020/05/16 22:11:52 by bts              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vector	vec_rotate(t_vector vec, t_vector angles)
{
	t_vector result;

	result = vec;
	if (angles.x)
	{
		result.y = vec.y * cos(angles.x) + vec.z * sin(angles.x);
		result.z = -vec.y * sin(angles.x) + vec.z * cos(angles.x);
	}
	if (angles.y)
	{
		result.x = vec.x * cos(angles.y) + vec.z * sin(angles.y);
		result.z = -vec.x * sin(angles.y) + vec.z * cos(angles.y);
	}
	if (angles.z)
	{
		result.x = vec.x * cos(angles.z) - vec.y * sin(angles.z);
		result.y = vec.x * sin(angles.z) + vec.y * cos(angles.z);
	}
	return (result);
}
