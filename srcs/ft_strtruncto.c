/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtruncto.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 23:17:07 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/09/06 09:50:18 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtruncto(char *str, int preci)
{
	if (preci > 0)
		return (ft_strsub(str, 0, preci));
	else if (preci == 0)
		return (ft_strnew(1));
	return (ft_strdup(str));
}
