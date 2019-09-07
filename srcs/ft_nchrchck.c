/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nchrchck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 23:11:48 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/09/07 13:39:50 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_nchrchck(const char *str, char *chrset, int len)
{
	int				i;
	unsigned int	j;

	i = 0;
	if (len < 0)
		return (-1);
	while (i < len)
	{
		j = 0;
		while (chrset[j])
		{
			if (str[i] == chrset[j])
				break ;
			else
				j++;
		}
		if (!chrset[j] && str[i] != chrset[j])
			return (-1);
		i++;
	}
	return (i);
}
