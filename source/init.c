/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bts <bts@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 22:37:45 by bts               #+#    #+#             */
/*   Updated: 2020/05/16 22:58:54 by bts              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_objects	*object_init(const char obj_type, t_objects *prev)
{
	t_objects *obj;

	if (!(obj = (t_objects *)malloc(sizeof(t_objects))))
		exit(-1);
	obj->type = obj_type;
	obj->radius = 0;
	obj->position = (t_vector){0, 0, 0};
	obj->direction = (t_vector){0, 0, 0};
	obj->reflective = -1;
	obj->specular = -1;
	obj->prev = prev;
	obj->next = NULL;
	return (obj);
}

/*
** Функция, которая инициализирует камеру и задает начальные данные.
** (Кординаты, POV и положение проекционной плоскости)
*/

t_camera	*cam_init(void)
{
	t_camera *cam;

	if (!(cam = (t_camera *)malloc(sizeof(t_camera))))
		exit(-1);
	cam->position = (t_vector){0, 0, 0};
	cam->direction = (t_vector){0, 0, 0};
	cam->viewport.x = (float)WIDTH / HEIGHT;
	cam->viewport.y = 1;
	cam->viewport.z = 1;
	return (cam);
}

t_light		*light_init(t_light *prev)
{
	t_light *light;

	if (!(light = (t_light*)malloc(sizeof(t_light))))
		exit(-1);
	light->position = (t_vector){0, 0, 0};
	light->direction = (t_vector){0, 0, 0};
	light->intencity = 0;
	light->next = NULL;
	light->prev = prev;
	return (light);
}

t_scene		*scene_init(const char *scene_name)
{
	t_scene *scene;

	if (!(scene = (t_scene *)malloc(sizeof(t_scene))))
		exit(-1);
	scene->cam = NULL;
	scene->objects = NULL;
	scene->lights = NULL;
	read_scene(scene_name, scene);
	return (scene);
}

/*
** Функция, которая отвечает за инициализацию окна.
*/

t_env		*env_init(const char *scene_name)
{
	t_env *env;

	if (!(env = (t_env*)malloc(sizeof(t_env))))
		exit(-1);
	env->scene = scene_init(scene_name);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT, PROG_NAME);
	env->canv = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->canv_data_addr = mlx_get_data_addr(env->canv,
	&env->bts_pr_pxl, &env->sz_ln, &env->endian);
	return (env);
}
