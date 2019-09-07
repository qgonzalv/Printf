/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:30:04 by qgonzalv          #+#    #+#             */
/*   Updated: 2017/12/04 14:54:31 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	size_t	lendst;
	size_t	lensrc;
	int		len;

	len = size - ft_strlen(dst);
	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	i = 0;
	while (len > 1 && src[i] != '\0' && len--)
	{
		dst[lendst + i] = ((char*)src)[i];
		i++;
	}
	dst[lendst + i] = '\0';
	if (len > 0)
		return (lendst + lensrc);
	else
		return (size + lensrc);
}
