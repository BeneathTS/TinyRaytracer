/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bts <bts@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 22:41:16 by bts               #+#    #+#             */
/*   Updated: 2020/05/16 22:45:42 by bts              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include <string.h>

# include "mlx.h"
# include "libft.h"
# include "vectors.h"
# include "structs.h"
# include "defines.h"

t_env			*env_init();
t_camera		*cam_init(void);

void			hooks(t_env *env);

void			renderer(t_env *env);
char			get_launch_mode(int argc, char **argv);
void			read_scene(const char *scene_name, t_scene *scene);

void			write_cam(const char data_type, const char *buffer,
t_scene *scene);

char			get_data_type(char **buffer, const char obj_type);
char			get_obj_type(const int fd, t_scene *scene);

void			write_object(char data_type, const char *buffer,
t_scene *scene);

t_objects		*object_init(const char obj_type, t_objects *prev);

t_light			*light_init(t_light *prev);
void			write_light(char data_type, const char *buffer,
t_scene *scene);

float			get_float_value(const char *num);
t_color			get_color(const char *color_data);
unsigned int	convert_color_chanels(t_color color);

t_color			color_mult_num(t_color color, float num);
t_color			reflection_color(t_color basic_color,
t_color reflected_color);

t_color			trace_ray(t_vector point, t_vector dir,
t_scene *scene, t_lim lim);

t_root			find_intersection(t_vector point, t_vector dir,
t_objects *object);
t_root			sphere_intersection(t_vector point, t_vector dir,
t_objects *object);
t_root			plane_intersection(t_vector point, t_vector dir,
t_objects *object);
t_root			cone_intersection(t_vector point, t_vector dir,
t_objects *object);
t_root			cylinder_intersection(t_vector point, t_vector dir,
t_objects *object);

float			compute_lighting(t_vector dir, t_trace_data *trace,
t_scene *scene);
t_vector		calculate_normal(t_vector point, t_vector dir,
t_trace_data *trace,
t_objects *object);

void			*check_for_shadow(t_vector point, t_vector light_dir,
t_scene *scene, t_lim lim);
t_vector		reflect_ray(t_vector dir, t_vector obj_normal);
#endif
