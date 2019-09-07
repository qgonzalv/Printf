/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchrset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 23:16:29 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/08/30 23:16:33 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchrset(char *tosearch, char *charset)
{
	int i;
	int j;

	if (tosearch && charset)
	{
		i = ft_strlen(tosearch);
		while (i >= 0)
		{
			j = 0;
			while (charset[j])
			{
				if (tosearch[i] == charset[j])
					return (&tosearch[i]);
				j++;
			}
			i--;
		}
	}
	return (NULL);
}
