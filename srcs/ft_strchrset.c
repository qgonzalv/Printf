/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 23:13:57 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/08/30 23:14:09 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strchrset(char *tosearch, char *charset)
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
				return (&charset[j]);
			j++;
		}
		i++;
	}
	return (NULL);
}
