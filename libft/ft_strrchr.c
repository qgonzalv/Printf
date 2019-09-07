/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:31:07 by qgonzalv          #+#    #+#             */
/*   Updated: 2017/12/06 11:54:27 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		lens;

	lens = ft_strlen(s);
	if (c == '\0')
		return (&((char*)s)[lens]);
	while (s[lens] != (unsigned char)c && lens >= 0)
		lens--;
	if (s[lens] == (unsigned char)c)
		return (&((char*)s)[lens]);
	return (NULL);
}
