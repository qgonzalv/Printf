/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nonchrseti.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 23:11:59 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/08/30 23:12:04 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_nonchrseti(const char *str, const char *chrset)
{
	int				i;
	unsigned int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (chrset[j])
		{
			if (str[i] == chrset[j])
				break ;
			j++;
		}
		if (j == ft_strlen(chrset))
			return (i + 1);
		i++;
	}
	return (0);
}
