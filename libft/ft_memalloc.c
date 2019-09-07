/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:17:09 by qgonzalv          #+#    #+#             */
/*   Updated: 2018/05/12 17:38:08 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char			*final;

	if (!size)
		return (NULL);
	final = (char*)malloc(size);
	if (!final)
		return (0);
	ft_bzero(final, size);
	return ((char*)final);
}
