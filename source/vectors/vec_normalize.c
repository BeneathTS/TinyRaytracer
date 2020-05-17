/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_normalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bts <bts@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 23:17:03 by bts               #+#    #+#             */
/*   Updated: 2020/05/15 23:17:22 by bts              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vector	vec_normalize(t_vector vec_a)
{
	float inv_lenght;

	inv_lenght = 1.0f / vec_length(vec_a);
	return (vec_mult_num(vec_a, inv_lenght));
}
