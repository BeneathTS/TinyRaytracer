/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bts <bts@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 23:21:59 by bts               #+#    #+#             */
/*   Updated: 2020/05/16 22:51:05 by bts              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

# include <math.h>

/*
** Так как я не пользуюсь сторониими библиотеками, чтобы лучше понять
** некоторые вещи, эта структура нужна просто, чтобы использовать ее как
** вектор в 3D пространстве.
*/
typedef struct	s_vector
{
	float		x;
	float		y;
	float		z;
}				t_vector;

float			vec_dot(t_vector vec_a, t_vector vec_b);

/*
** Функция для нахождения длины вектора
*/
float			vec_length(t_vector vec);

/*
** Функция которая находит новый вектор путем сложения координат 2 векторов.
*/
t_vector		vec_sum(t_vector vec_a, t_vector vec_b);

/*
** Функция которая находит новый вектор путем вычитания
** координат вектора b из вектора a.
*/
t_vector		vec_sub(t_vector vec_a, t_vector vec_b);

/*
** Функция которая находит новый вектор путем вычитания
** константы из координат вектора а.
*/
t_vector		vec_sub_num(t_vector vec_a, float num);

/*
** Перемножение 2 векторов.
*/
t_vector		vec_mult(t_vector vec_a, t_vector vec_b);

/*
** Умножение координат вектора на скаляр / изменение длины вектора.
*/
t_vector		vec_mult_num(t_vector vec, float num);

/*
** Деление вектора на скаляр.
*/
t_vector		vec_div_num(t_vector vec, float num);

/*
** Нормализация вектора.
** Функция, которая делает длину вектора равной 1.
*/
t_vector		vec_normalize(t_vector vec_a);

/*
** Функция для упрощения создания направлений.
** Находит вектор по двум точкам и нормализует его.
*/
t_vector		vec_dir(t_vector vec_a, t_vector vec_b);

t_vector		vec_rotate(t_vector vec, t_vector angles);

#endif
