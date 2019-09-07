/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 23:11:11 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/08/31 16:05:15 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	get_len(long n)
{
	int		neg;
	int		len;

	neg = 0;
	len = 1;
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	return (len + neg);
}

char		*ft_itoa(int n)
{
	int		len;
	long	nb;
	char	*num;

	nb = n;
	len = get_len(nb);
	if (!(num = ft_strnew(len)))
		return (NULL);
	if (nb < 0)
	{
		num[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		num[0] = '0';
	while (len-- >= 0 && nb != 0)
	{
		num[len] = nb % 10 + '0';
		nb /= 10;
	}
	return (num);
}
