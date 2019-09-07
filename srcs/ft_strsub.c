/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 23:16:57 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/08/30 23:17:02 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strsub(char const *s1, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (s1 == NULL || !(sub = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (i < len && s1)
		sub[i++] = s1[start++];
	sub[i] = '\0';
	return (sub);
}
