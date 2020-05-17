/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bts <bts@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 22:36:48 by bts               #+#    #+#             */
/*   Updated: 2020/05/16 22:37:16 by bts              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	*check_for_shadow(t_vector point, t_vector light_dir, t_scene *scene,
																	t_lim lim)
{
	t_objects	*curr_obj;
	t_objects	*close_obj;
	float		close_param;
	t_root		root;

	curr_obj = scene->objects;
	close_obj = NULL;
	close_param = DEPTH;
	while (curr_obj)
	{
		root = find_intersection(point, light_dir, curr_obj);
		if (root.x1 > lim.min && root.x1 < lim.max && root.x1 < close_param)
		{
			close_param = root.x1;
			close_obj = curr_obj;
		}
		if (root.x2 > lim.min && root.x2 < lim.max && root.x2 < close_param)
		{
			close_param = root.x2;
			close_obj = curr_obj;
		}
		curr_obj = curr_obj->prev;
	}
	return (close_obj);
}
