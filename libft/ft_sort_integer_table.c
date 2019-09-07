/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 17:04:35 by qgonzalv          #+#    #+#             */
/*   Updated: 2017/12/15 13:04:54 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_integer_table(int *tab, size_t size)
{
	size_t i;
	size_t temp;
	size_t compteur;

	compteur = 1;
	temp = 0;
	i = 0;
	while (compteur == 1)
	{
		compteur = 0;
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
				compteur = 1;
			}
			i++;
		}
	}
}
