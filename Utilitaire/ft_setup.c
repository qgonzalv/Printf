/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 14:04:26 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/05/10 15:48:58 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#define FT_BASE_CHARSET "0123456789abcdefghijklmnopqrstuvwxz"

char	*ft_uitoab(unsigned long long n, char b, char *out)
{
	char		cnt;

	cnt = ft_ucntb(n, b);
	if (out == NULL || b < 2 || b > 16)
		return (NULL);
	out[cnt + 0] = 0;
	while (--cnt)
	{
		out[cnt + 0] = FT_BASE_CHARSET[n % b];
		n = n / b;
	}
	out[cnt + 0] = FT_BASE_CHARSET[n % b];
	return (out);
}

char	ft_cntb(long long n, char b)
{
	int ret;

	ret = 1;
	n = n > 0 ? -n : n;
	while (n <= (long long)(-b))
	{
		n = n / b;
		ret++;
	}
	return (ret);
}

char	ft_ucntb(t_ull n, char b)
{
	int ret;

	ret = 1;
	while (n >= (t_ull)b)
	{
		n = n / b;
		ret++;
	}
	return (ret);
}

int		ft_fill(char *s, char *s2, int len)
{
	static int	i = 0;

	if (len > 0)
	{
		len = len + i;
		while (i < len)
		{
			s[i] = s2[0];
			i++;
		}
	}
	else if (s2 != NULL)
	{
		ft_strcpy(&s[i], s2);
		i = i + ft_strlen(s2);
	}
	else
	{
		s[i] = 0;
		i = 0;
	}
	return (0);
}

size_t	ft_strclen(char const *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i] != 0 && str[i] != c)
		i++;
	return (i);
}

// {char	ft_define_fd(char const *s, int *i, va_list va, t_arg *arg)
// 	if (ft_strnequ(&s[*i], "[fd", 3) == 1)
// 	{
// 		*i = *i + 4;
// 		if (s[*i - 1] == '*')
// 		{
// 			(*i)++;
// 			arg->fd = va_arg(va, int);
// 		}
// 		else
// 		{
// 			arg->fd = ft_atoi(&s[*i - 1]);
// 			while (ft_isdigit(s[*i - 1]) == 1)
// 				(*i)++;
// 		}
// 	}
// 	else if (ft_strnequ(&s[*i], "[\fd]", 4) == 1)
// 	{
// 		arg->fd = 1;
// 		*i = *i + 5;
// 	}
// 	return (0);
// }
