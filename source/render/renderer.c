/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bts <bts@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 22:33:45 by bts               #+#    #+#             */
/*   Updated: 2020/05/16 22:36:04 by bts              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_vector	get_viewport_coord(t_scene *scene, int canv_x, int canv_y)
{
	t_vector viewport_coord;

	viewport_coord.x = canv_x * scene->cam->viewport.x / WIDTH;
	viewport_coord.y = canv_y * scene->cam->viewport.y / HEIGHT;
	viewport_coord.z = scene->cam->viewport.z;
	viewport_coord = vec_normalize(vec_rotate(viewport_coord,
										scene->cam->direction));
	return (viewport_coord);
}

void			renderer(t_env *env)
{
	int				canvas[2];
	t_vector		ray_dir;
	unsigned int	color;

	mlx_clear_window(env->mlx, env->win);
	canvas[y] = -(HEIGHT >> 1) - 1;
	while (++canvas[y] < (HEIGHT >> 1))
	{
		canvas[x] = -(WIDTH >> 1) - 1;
		while (++canvas[x] < (WIDTH >> 1))
		{
			ray_dir = get_viewport_coord(env->scene, canvas[x], canvas[y]);
			color = convert_color_chanels(
				trace_ray(env->scene->cam->position, ray_dir, env->scene,
										(t_lim){1.0, DEPTH, MIRROR_LIM}));
			((int *)env->canv_data_addr)[(canvas[x] + (WIDTH >> 1)) +
							(canvas[y] + (HEIGHT >> 1)) * WIDTH] = color;
		}
	}
	mlx_put_image_to_window(env->mlx, env->win, env->canv, 0, 0);
}
