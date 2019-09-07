/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:37:59 by qgonzalv          #+#    #+#             */
/*   Updated: 2017/12/05 18:49:18 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char		*final;
	size_t		i;

	i = 0;
	if (!(final = malloc(sizeof(*final) * len + 1)))
		return (NULL);
	if (s == NULL || len == 0)
	{
		final[0] = '\0';
		return (final);
	}
	if (len > ft_strlen(s) || start > ft_strlen(s))
		return (NULL);
	while (i < len)
	{
		final[i] = s[i + start];
		i++;
	}
	final[i] = '\0';
	return (final);
}
