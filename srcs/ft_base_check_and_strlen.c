/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_check_and_strlen.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 23:07:55 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/08/30 23:08:06 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_base_check_and_strlen(char *base)
{
	int i;
	int length;

	length = 0;
	while (base[length] != '\0')
	{
		if (base[length] == '+' || base[length] == '-')
			return (0);
		i = length;
		while (i-- >= 0)
			if (base[i] == base[length])
				return (0);
		length++;
	}
	return (length);
}
