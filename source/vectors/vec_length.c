/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bts <bts@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 23:17:37 by bts               #+#    #+#             */
/*   Updated: 2020/05/15 23:17:37 by bts              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

float	vec_length(t_vector vec)
{
	return (sqrtf(pow(vec.x, 2.0f) + pow(vec.y, 2.0f) + pow(vec.z, 2.0f)));
}
