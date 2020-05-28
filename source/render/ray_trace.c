/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bts <bts@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 22:32:09 by bts               #+#    #+#             */
/*   Updated: 2020/05/16 22:32:55 by bts              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_root				find_intersection(t_vector point, t_vector dir,
														t_objects *object)
{
	if (object->type == sphere)
		return (sphere_intersection(point, dir, object));
	else if (object->type == plane)
		return (plane_intersection(point, dir, object));
	else if (object->type == cylinder)
		return (cylinder_intersection(point, dir, object));
	else if (object->type == cone)
		return (cone_intersection(point, dir, object));
	return ((t_root){-1.0, -1.0});
}

t_close_obj_data	search_close_object(t_vector point, t_vector dir,
													t_scene *scene, t_lim *lim)
{
	t_objects	*curr_obj;
	t_objects	*close_obj;
	float		close_param;
	t_root		root;

	curr_obj = scene->objects;
	close_obj = NULL;
	close_param = lim->max;
	while (curr_obj)
	{
		root = find_intersection(point, dir, curr_obj);
		if (root.x1 > lim->min && root.x1 < lim->max && root.x1 < close_param)
		{
			close_param = root.x1;
			close_obj = curr_obj;
		}
		if (root.x2 > lim->min && root.x2 < lim->max && root.x2 < close_param)
		{
			close_param = root.x2;
			close_obj = curr_obj;
		}
		curr_obj = curr_obj->prev;
	}
	return ((t_close_obj_data){close_obj, close_param});
}

t_color				trace_ray(t_vector point, t_vector dir, t_scene *scene,
																t_lim lim)
{
	t_trace_data	trace;
	t_vector		reflected_ray;
	t_color			basic_color;
	t_color			reflected_color;
	float			color_intencity;

	trace.obj = search_close_object(point, dir, scene, &lim);
	if (!trace.obj.close_obj)
		return ((t_color){0x0, 0x0, 0x0});
	trace.i_point = vec_sum(point, vec_mult_num(dir, trace.obj.param));
	trace.normal = calculate_normal(point, dir, &trace, trace.obj.close_obj);
	trace.i_point = vec_sum(trace.i_point, vec_mult_num(trace.normal, 0.1f));
	color_intencity = compute_lighting(dir, &trace, scene);
	basic_color = color_mult_num(trace.obj.close_obj->color, color_intencity);
	if (lim.recursion <= 0 || trace.obj.close_obj->reflective <= 0)
		return (basic_color);
	reflected_ray = reflect_ray(vec_mult_num(dir, -1.0f), trace.normal);
	reflected_color = trace_ray(trace.i_point, reflected_ray, scene,
	(t_lim){0.001f, DEPTH, lim.recursion - 1});
	return (reflection_color(color_mult_num(basic_color, 1.0 -
	trace.obj.close_obj->reflective), color_mult_num(reflected_color,
	trace.obj.close_obj->reflective)));
}
