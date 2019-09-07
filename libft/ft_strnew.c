/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:04:04 by qgonzalv          #+#    #+#             */
/*   Updated: 2018/05/12 17:38:16 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t		i;
	char		*final;

	i = 0;
	if (!(final = (char*)malloc(sizeof(*final) * size + 1)))
		return (NULL);
	if (size == 0)
	{
		final[0] = '\0';
		return (final);
	}
	while (i <= size)
	{
		final[i] = '\0';
		i++;
	}
	return (final);
}
