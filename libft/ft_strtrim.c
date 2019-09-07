/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 09:49:32 by qgonzalv          #+#    #+#             */
/*   Updated: 2017/12/05 18:00:55 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static int		isblank(char const *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		else
			return (0);
	}
	return (1);
}

char			*ft_strtrim(char const *s)
{
	char		*final;
	size_t		i;
	size_t		size;
	size_t		j;
	size_t		tmp;

	j = 0;
	size = 0;
	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	while (s[size - 1] == ' ' || s[size - 1] == '\n' || s[size - 1] == '\t')
		size--;
	if (isblank(s))
		return (ft_strnew(1));
	if (!(final = ((char*)malloc(sizeof(*final) * (size - i + 1)))))
		return (NULL);
	tmp = i;
	while (j != size - tmp)
		final[j++] = s[i++];
	final[j] = '\0';
	return (final);
}
