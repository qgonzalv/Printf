/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftUtil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:20:00 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/05/10 16:23:39 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <limits.h>

char	*ft_itoab(long long n, char b, char *out)
{
	if (out == NULL || b < 2 || b > 16)
		return (NULL);
	if (n == LLONG_MIN)
	{
		out[0] = '-';
		ft_uitoab(9, b, &out[1]);
		ft_uitoab(223372036854775808, b, &out[ft_cntb(9, b) + 1]);
	}
	else if (b == 10 && n < 0)
	{
		out[0] = '-';
		ft_uitoab((n * -1), b, &out[1]);
	}
	else
		ft_uitoab(n, b, out);
	return (out);
}

size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t	tmp;

	tmp = ft_strlen(s);
	if (tmp <= maxlen)
		return (tmp);
	return (maxlen);
}

char	*ft_strupper(char *s)
{
	size_t i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != 0)
	{
		s[i] = ft_toupper(s[i]);
		i++;
	}
	return (s);
}
