/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:28:25 by qgonzalv          #+#    #+#             */
/*   Updated: 2017/12/05 18:16:23 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		final;

	final = 0;
	i = 0;
	if (s1 == NULL && s2 == NULL)
		return (final);
	while (i < n)
	{
		if (((unsigned char*)s1)[i] != ((unsigned char*)s2)[i])
		{
			final = ((unsigned char*)s1)[i] - ((unsigned char*)s2)[i];
			return (final);
		}
		i++;
	}
	return (final);
}
