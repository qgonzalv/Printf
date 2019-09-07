/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:04:44 by qgonzalv          #+#    #+#             */
/*   Updated: 2017/11/28 12:55:42 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *src)
{
	int		range;
	char	*final;
	int		i;

	i = 0;
	range = ft_strlen(src);
	final = (char*)malloc(sizeof(*final) * (range + 1));
	if (final == 0)
		return (NULL);
	while (src[i] != '\0')
	{
		final[i] = src[i];
		i++;
	}
	final[i] = '\0';
	return (final);
}
