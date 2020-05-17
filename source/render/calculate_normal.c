/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_normal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bts <bts@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 22:15:59 by bts               #+#    #+#             */
/*   Updated: 2020/05/16 22:16:00 by bts              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_vector	sphere_normal(t_vector i_point, t_objects *object)
{
	return (vec_dir(i_point, object->position));
}

static t_vector	cone_n_cyl_normal(t_vector point, t_vector dir,
						t_trace_data *trace, t_objects *object)
{
	float		cone_param;
	t_vector	pnt_pos;
	t_vector	obj_point;

	pnt_pos = vec_sub(point, object->position);
	cone_param = trace->obj.param * vec_dot(dir, object->direction) +
					vec_dot(pnt_pos, object->direction);
	obj_point = vec_sum(object->position,
	vec_mult_num(object->direction, cone_param));
	return (vec_dir(trace->i_point, obj_point));
}

t_vector		calculate_normal(t_vector point, t_vector dir,
						t_trace_data *trace, t_objects *object)
{
	if (object->type == sphere)
		return (sphere_normal(trace->i_point, object));
	else if (object->type == plane)
		return (object->direction);
	else if (object->type == cylinder || object->type == cone)
		return (cone_n_cyl_normal(point, dir, trace, object));
	return ((t_vector){0.0f, 0.0f, 0.0f});
}
