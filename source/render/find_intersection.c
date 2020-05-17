/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bts <bts@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 22:26:31 by bts               #+#    #+#             */
/*   Updated: 2020/05/16 22:26:32 by bts              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
** Данная функция нужна для того, чтобы найти параметры,
** при которых луч попадает в сферу.
** (Если таковые имеются)
**
** Все что нам нужно знать для его нахождения:
**
** |Int_point - Sph_center| = Radius
** Int_point = Vec_pos + param * Vec_dir
*/

t_root	sphere_intersection(t_vector point, t_vector dir, t_objects *object)
{
	float		a;
	float		b;
	float		c;
	float		discriminant;
	t_vector	pnt_pos;

	pnt_pos = vec_sub(point, object->position);
	a = vec_dot(dir, dir);
	b = vec_dot(pnt_pos, dir);
	c = vec_dot(pnt_pos, pnt_pos) - powf(object->radius, 2.0f);
	discriminant = powf(b, 2.0f) - a * c;
	if (discriminant < 0.0f)
		return ((t_root){-1.0f, -1.0f});
	discriminant = sqrtf(discriminant);
	return ((t_root){
		(-b - discriminant) / a,
		(-b + discriminant) / a
	});
}

/*
** Данная функция нужна для того, чтобы найти параметры,
** при которых луч попадает в плоскость.
** (Если таковые имеются)
**
** Все что нам нужно знать для его нахождения:
**
** <I_point - Plane_pos, Normal> = 0 //
** угол между нормалью и нашей точкой должен быть равен 90
** I_point = Vec_pos + param * Vec_dir
*/

t_root	plane_intersection(t_vector point, t_vector dir, t_objects *object)
{
	t_vector	plane_vec;
	float		param;

	plane_vec = vec_sub(point, object->position);
	param = -1 * vec_dot(plane_vec, object->direction) /
	vec_dot(dir, object->direction);
	return ((t_root){param, -1.0f});
}

/*
** Данная функция нужна для того, чтобы найти параметры,
** при которых луч попадает в бесконечный цилиндр.
** (Если таковые имеются)
**
** Все что нам нужно знать для его нахождения:
**
** С_dot = cyl_top_poitn + cyl_dir * param1 //
** точка, которая образует вектор, коллинеарный основаниям цилиндра
** <I_point - С_dot, cyl_dir> = 0
** I_point = Vec_pos + param2 * Vec_dir
** |I_point - C_dot| = Radius
*/

t_root	cylinder_intersection(t_vector point, t_vector dir, t_objects *object)
{
	float		a;
	float		b;
	float		c;
	float		discriminant;
	t_vector	pnt_pos;

	pnt_pos = vec_sub(point, object->position);
	a = vec_dot(dir, dir) - powf(vec_dot(dir, object->direction), 2.0f);
	b = vec_dot(dir, pnt_pos) - vec_dot(dir, object->direction) *
	vec_dot(pnt_pos, object->direction);
	c = vec_dot(pnt_pos, pnt_pos) - powf(vec_dot(pnt_pos,
	object->direction), 2.0f) - powf(object->radius, 2.0f);
	discriminant = powf(b, 2.0f) - a * c;
	if (discriminant < 0.0f)
		return ((t_root){-1.0f, -1.0f});
	discriminant = sqrtf(discriminant);
	return ((t_root){
		(-b - discriminant) / a,
		(-b + discriminant) / a});
}

/*
** Данная функция нужна для того, чтобы найти параметры,
** при которых луч попадает в бесконечный конус.
** (Если таковые имеются)
** (Похожа на конус, только длина радиуса зависит от значения param1)
**
** Все что нам нужно знать для его нахождения:
**
** С_dot = cone_top_poitn + cone_dir * param1
** <I_point - С_dot, cone_dir> = 0
** I_point = Vec_pos + param2 * Vec_dir
** |I_point - C_dot| / m = k; (k - тангенс)
*/

t_root	cone_intersection(t_vector point, t_vector dir, t_objects *object)
{
	float		tan;
	float		discriminant;
	t_i_root	coef;
	t_vector	pnt_pos;

	pnt_pos = vec_sub(point, object->position);
	tan = object->radius / 2.0f;
	tan = 1 + powf(tan, 2.0f);
	coef.a = vec_dot(dir, dir) - tan *
	powf(vec_dot(dir, object->direction), 2.0f);
	coef.b = vec_dot(dir, pnt_pos) - tan *
	vec_dot(dir, object->direction) * vec_dot(pnt_pos, object->direction);
	coef.c = vec_dot(pnt_pos, pnt_pos) - tan *
	powf(vec_dot(pnt_pos, object->direction), 2.0f);
	discriminant = powf(coef.b, 2.0f) - coef.a * coef.c;
	if (discriminant < 0.0f)
		return ((t_root){-1.0f, -1.0f});
	discriminant = sqrtf(discriminant);
	return ((t_root){
		(-coef.b - discriminant) / coef.a,
		(-coef.b + discriminant) / coef.a});
}
