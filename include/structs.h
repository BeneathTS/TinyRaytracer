/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bts <bts@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 22:46:58 by bts               #+#    #+#             */
/*   Updated: 2020/05/16 22:47:06 by bts              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct			s_lim
{
	float				min;
	float				max;
	size_t				recursion;
}						t_lim;

typedef struct			s_root
{
	float				x1;
	float				x2;
}						t_root;

typedef struct			s_i_root
{
	float				a;
	float				b;
	float				c;
}						t_i_root;

typedef struct			s_color
{
	uint16_t			r;
	uint16_t			g;
	uint16_t			b;
}						t_color;

/*
** Структура, которая содержит все необходимые данные для
** работы с камерой.
** (Направления взгляда, расположение в пространстве
** и местоположение проекционной плоскости)
*/
typedef struct			s_camera
{
	t_vector			position;
	t_vector			viewport;
	t_vector			direction;
}						t_camera;

typedef struct			s_objects
{
	char				type;
	t_vector			position;
	t_vector			direction;
	t_color				color;
	float				radius;
	float				specular;
	float				reflective;
	float				angle;
	struct s_objects	*next;
	struct s_objects	*prev;
}						t_objects;

typedef struct			s_light
{
	char				type;
	float				intencity;
	t_vector			position;
	t_vector			direction;
	struct s_light		*next;
	struct s_light		*prev;
}						t_light;

/*
** Структура, содержащая данные о сцене.
** (Фигуры, их положение в пространстве, расположение камеры и т.п.)
*/
typedef struct			s_scene
{
	t_camera			*cam;
	t_objects			*objects;
	t_light				*lights;
}						t_scene;

typedef struct			s_close_obj_data
{
	t_objects			*close_obj;
	float				param;
}						t_close_obj_data;

typedef struct			s_trace_data
{
	t_close_obj_data	obj;
	t_vector			i_point;
	t_vector			normal;
	t_vector			light_dir;
}						t_trace_data;

/*
** Структура, содержащая все переменные, необходимые для инициализации окна
** и указателем на структуру, которая содержит указатели на все остальные
** структуры, необходимые для работы програмы.
*/
typedef struct			s_env
{
	void				*mlx;
	void				*win;
	void				*canv;
	char				*canv_data_addr;
	int					sz_ln;
	int					endian;
	int					bts_pr_pxl;
	char				mode;
	t_scene				*scene;
}						t_env;

#endif
