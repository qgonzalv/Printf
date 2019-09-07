/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsfill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 23:16:49 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/08/30 23:16:53 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char*ft_strsfill(const char *str, const char *s, long int index)
{
	char		*ret;
	long int	i;
	long int	j;
	long int	size;

	i = 0;
	j = 0;
	size = ft_strlen(str) + ft_strlen(s);
	ret = ft_strnew(size);
	while (i < size)
	{
		if (i == index)
		{
			while (s[j])
				ret[index++] = s[j++];
			while (str[i])
				ret[index++] = str[i++];
			return (ret);
		}
		ret[i] = str[i];
		i++;
	}
	return (ret);
}
