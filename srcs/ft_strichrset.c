/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strichrset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 23:16:04 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/09/07 14:36:27 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strichrset(const char *temp, const char *charset)
{
	int i;
	int j;

	i = 0;
	while (temp[i])
	{
		j = 0;
		while (charset[j])
		{
			if (temp[i] == charset[j])
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}
