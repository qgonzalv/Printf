/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:27:01 by qgonzalv          #+#    #+#             */
/*   Updated: 2017/12/05 18:15:58 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*sptr;

	sptr = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (sptr[i] == (unsigned char)c)
			return (&sptr[i]);
		i++;
	}
	return (NULL);
}
