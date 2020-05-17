/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bts <bts@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 22:40:08 by bts               #+#    #+#             */
/*   Updated: 2020/05/16 23:02:09 by bts              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		ft_exit(const char *msg)
{
	ft_putendl(msg);
	exit(1);
}

static char	check_arg(int argc, char **argv)
{
	int fd;

	if (argc != 2)
		exit(-1);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		exit(-1);
	close(fd);
	return (0);
}

int			main(int argc, char **argv)
{
	t_env *env;

	check_arg(argc, argv);
	env = env_init(argv[1]);
	renderer(env);
	hooks(env);
	mlx_loop(env->mlx);
	return (0);
}
