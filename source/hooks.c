/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bts <bts@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 22:39:47 by bts               #+#    #+#             */
/*   Updated: 2020/05/16 22:39:48 by bts              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	x_close(t_env *env)
{
	(void)env;
	exit(0);
}

static int	key_controls(int key, t_env *env)
{
	if (key == KB_ESC)
		x_close(env);
	return (0);
}

void		hooks(t_env *env)
{
	mlx_hook(env->win, 17, 0, x_close, env);
	mlx_hook(env->win, 2, 0, key_controls, env);
}
