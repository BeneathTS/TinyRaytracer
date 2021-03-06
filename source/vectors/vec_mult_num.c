/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_mult_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bts <bts@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 23:18:46 by bts               #+#    #+#             */
/*   Updated: 2020/05/15 23:18:46 by bts              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vector	vec_mult_num(t_vector vec, float num)
{
	return ((t_vector){	vec.x * num,
						vec.y * num,
						vec.z * num});
}
