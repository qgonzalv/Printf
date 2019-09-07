/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:03:37 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/08/31 16:03:38 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"

char	*ft_strndup(const char *s1, size_t len)
{
	char *s2;

	if (!(s2 = ft_strnew(len)))
		return (NULL);
	return (ft_strcpy(s2, s1));
}
