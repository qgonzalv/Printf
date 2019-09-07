/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:08:54 by qgonzalv          #+#    #+#             */
/*   Updated: 2017/12/05 14:06:56 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	int		i;
	char	*final;

	i = 0;
	if (s == NULL)
		return (NULL);
	final = (char*)malloc(sizeof(*final) * ft_strlen(s) + 1);
	if (final == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		final[i] = f(s[i]);
		i++;
	}
	final[i] = '\0';
	return (final);
}
