/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:05:36 by qgonzalv          #+#    #+#             */
/*   Updated: 2017/12/05 18:15:04 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		isnegative(int c)
{
	if (c < 0)
		return (1);
	else
		return (0);
}

static char		*put_nbr(char *final, int c, int len)
{
	if (c <= 2147483647 && c >= -2147483648)
	{
		while (len--)
		{
			final[len] = (c % 10) + '0';
			c = c / 10;
		}
	}
	return (final);
}

static int		count_int(int c)
{
	int		len;
	int		x;

	x = 0;
	len = 0;
	if (isnegative(c))
	{
		x = -c;
		len++;
	}
	else
		x = c;
	while (x > 0)
	{
		len++;
		x = x / 10;
	}
	return (len);
}

char			*ft_itoa(int c)
{
	int		len;
	char	*final;
	int		tmp;

	tmp = 0;
	len = count_int(c);
	if (isnegative(c))
		tmp = -c;
	else
		tmp = c;
	if (c == -2147483648)
		return (ft_strdup("-2147483648"));
	if (c == 0)
		return (ft_strdup("0"));
	if (!(final = (char*)malloc(sizeof(*final) * len + 1)))
		return (NULL);
	if (tmp <= 2147483647 && tmp >= -2147483648)
	{
		final = put_nbr(final, tmp, len);
	}
	if (isnegative(c))
		final[0] = '-';
	final[len] = '\0';
	return (final);
}
