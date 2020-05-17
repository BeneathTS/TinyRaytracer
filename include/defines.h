/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bts <bts@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 22:50:11 by bts               #+#    #+#             */
/*   Updated: 2020/05/16 22:50:17 by bts              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define WIDTH 1280
# define HEIGHT 720

# define DEPTH 100000000.0f
# define MIRROR_LIM 30

# define SCENE_NAME "scenes/scene1"
# define PROG_NAME "Ray Tracer"

# define KB_ESC 53

# define ARR_RGHT 124
# define ARR_LFT 123

# define KB_SPACE 49
# define KB_CTRL 256
# define KB_A 0
# define KB_D 2

typedef enum	e_coords
{
	x,
	y
}				t_coords;

typedef enum	e_shadow_status
{
	yes,
	no
}				t_shadow_status;

typedef enum	e_light_types
{
	point,
	directional,
	ambient
}				t_light_types;

typedef enum	e_type_objects
{
	cylinder,
	sphere,
	plane,
	cone,
	cam,
	light
}				t_type_objects;

typedef enum	e_read_status
{
	error = -1,
	done,
	reading
}				t_read_status;

typedef enum	e_d_type
{
	empty = -1,
	position,
	direction,
	radius,
	color,
	intensity,
	light_type,
	specular,
	reflective
}				t_d_type;

#endif
