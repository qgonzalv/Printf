/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcfill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:03:02 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/08/31 16:03:04 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strcfill(const char *str, char chr, long int index,
		long int len)
{
	char		*ret;
	long int	i;
	long int	size;

	i = 0;
	size = len + ft_strlen(str);
	if (!str || len < 0 || !(ret = ft_strnew(size)))
		return (NULL);
	while (i < size)
	{
		if (i == index && len != 0)
		{
			while (len > 0)
			{
				ret[index++] = chr;
				len--;
			}
			while (str[i] && index < size)
				ret[index++] = str[i++];
			return (ret);
		}
		ret[i] = str[i];
		i++;
	}
	return (ret);
}
