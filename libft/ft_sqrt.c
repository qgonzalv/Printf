/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 22:28:22 by qgonzalv          #+#    #+#             */
/*   Updated: 2017/12/15 13:00:43 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int i;
	int retour;

	i = 0;
	retour = 1;
	while (1 > 0)
	{
		retour = i * i;
		if (retour == nb)
		{
			return (i);
		}
		else
		{
			if (retour < nb)
			{
				i++;
			}
			else
				return (0);
		}
	}
	return (0);
}
