/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 21:54:49 by qgonzalv          #+#    #+#             */
/*   Updated: 2017/12/15 13:39:09 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_recursive_factorial(int nb)
{
	if (nb == 0)
	{
		return (1);
	}
	if (nb >= 0 && nb < 13)
	{
		if (nb - 1 != 1)
		{
			nb = nb * ft_recursive_factorial(nb - 1);
		}
	}
	else
		nb = 0;
	return (nb);
}
