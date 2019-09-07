/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrsetc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 23:15:11 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/08/30 23:15:13 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	ft_strchrsetc(char *tosearch, char *charset)
{
	int i;
	int j;

	i = 0;
	while (tosearch[i])
	{
		j = 0;
		while (charset[j])
		{
			if (tosearch[i] == charset[j])
				return (charset[j]);
			j++;
		}
		i++;
	}
	return ('0');
}
