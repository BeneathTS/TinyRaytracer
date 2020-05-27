/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bts <bts@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 22:29:18 by bts               #+#    #+#             */
/*   Updated: 2020/05/16 22:29:19 by bts              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector		reflect_ray(t_vector dir, t_vector obj_normal)
{
	return (vec_sub(
		vec_mult_num(obj_normal, 2.0f * vec_dot(obj_normal, dir)),
		dir));
}

static float	diffusive_light(t_trace_data *trace, t_light *light_source)
{
	float	n_dot_l;
	float	cos_a;

	n_dot_l = vec_dot(trace->normal, trace->light_dir);
	if (n_dot_l <= 0.0f)
		return (0.0f);
	cos_a = n_dot_l / vec_length(trace->light_dir);
	return (light_source->intencity * cos_a);
}

static float	reflection_light(t_vector dir, t_trace_data *trace,
											t_light *light_source)
{
	t_vector	reflected_ray;
	float		r_dot_d;
	float		cos_a;

	if (trace->obj.close_obj->specular < 1)
		return (0);
	reflected_ray = reflect_ray(trace->light_dir, trace->normal);
	r_dot_d = vec_dot(reflected_ray, vec_mult_num(dir, -1.0f));
	if (r_dot_d <= 0.0f)
		return (0.0f);
	cos_a = r_dot_d / vec_length(reflected_ray);
	return (light_source->intencity *
			powf(cos_a, trace->obj.close_obj->specular));
}

static float	compute_intensity(t_vector dir, t_trace_data *trace,
								t_light *curr_light, t_scene *scene)
{
	float	intensity;
	t_lim	limits;

	intensity = 0.0f;
	limits = (t_lim){0.0001f, DEPTH, 0};
	if (curr_light->type == ambient)
		intensity += curr_light->intencity;
	else
	{
		if (curr_light->type == point)
		{
			trace->light_dir = vec_sub(curr_light->position, trace->i_point);
			limits.max = 1.0f;
		}
		else
			trace->light_dir = curr_light->direction;
		if (check_for_shadow(trace->i_point, trace->light_dir, scene, limits))
			return (intensity);
		intensity += diffusive_light(trace, curr_light);
		intensity += reflection_light(dir, trace, curr_light);
	}
	return (intensity);
}

float			compute_lighting(t_vector dir, t_trace_data *trace,
													t_scene *scene)
{
	float	intensity;
	t_light	*curr_light;

	curr_light = scene->lights;
	intensity = 0.0f;
	while (curr_light)
	{
		intensity += compute_intensity(dir, trace, curr_light, scene);
		curr_light = curr_light->prev;
	}
	intensity = (intensity > 1 ? 1 : intensity);
	return (intensity);
}
