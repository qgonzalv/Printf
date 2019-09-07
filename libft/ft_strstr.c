/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:25:10 by qgonzalv          #+#    #+#             */
/*   Updated: 2017/11/28 16:55:44 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int boolean;
	int i;
	int j;

	i = -1;
	if (to_find[0] == '\0')
		return ((char*)str);
	while (str[++i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			boolean = 1;
			while (to_find[++j] != '\0' && boolean)
			{
				if (str[i + j] != to_find[j])
					boolean = 0;
			}
			if (boolean)
				return ((char *)&(str[i]));
		}
	}
	return (0);
}
