/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 23:16:40 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/08/30 23:16:44 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrev(char *str)
{
	unsigned int	i;
	unsigned int	lth;
	char			r;

	i = 0;
	lth = ft_strlen(str) - 1;
	if (!str)
		return (NULL);
	if (ft_strlen(str) == 1)
		return (str);
	while (lth >= i)
	{
		r = str[lth];
		str[lth] = str[i];
		str[i] = r;
		lth--;
		i++;
	}
	return (str);
}
