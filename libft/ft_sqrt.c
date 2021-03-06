/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahiroko <ahiroko@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:55:17 by ahiroko           #+#    #+#             */
/*   Updated: 2019/04/21 18:01:46 by ahiroko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int nb)
{
	int ct;
	int i;

	i = 0;
	ct = i;
	if (nb == 0)
		return (0);
	while (i != nb)
	{
		if (ct > nb)
			return (0);
		i = ct * ct;
		ct++;
	}
	return (ct - 1);
}
