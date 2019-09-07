/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:56:29 by qgonzalv          #+#    #+#             */
/*   Updated: 2017/12/05 18:45:12 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t		boolean;
	int			i;
	size_t		j;

	i = -1;
	if (to_find[0] == '\0')
		return ((char*)str);
	if (len == 0)
		return (NULL);
	while (str[++i] != '\0' && (size_t)i < len)
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			boolean = 1;
			while (to_find[++j] != '\0' && boolean)
			{
				if (str[(size_t)i + j] != to_find[j] || (size_t)i + j > len)
					boolean = 0;
			}
			if (boolean)
				return ((char*)&(str[i]));
		}
	}
	return (0);
}
