/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 23:07:40 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/08/31 16:07:50 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

static void		rec_conv(char *nb, char *nativebase, int base, intmax_t *ret)
{
	int i;

	i = 0;
	if (*nb != '\0' && ft_isdigit(*nb))
	{
		while (nativebase[i] != *nb)
			i++;
		*ret = (*ret * base) + i;
		rec_conv(nb + 1, nativebase, base, ret);
	}
	return ;
}

intmax_t		ft_atoll_base(char *nb, char *nativebase)
{
	intmax_t	ret;
	int			base;
	int			neg;

	neg = 1;
	ret = 0;
	base = ft_strlen(nativebase);
	if (!nb || *nb == '\0')
		return (0);
	while ((*nb >= 9 && *nb <= 13) || *nb == 32)
		nb++;
	if (*nb == '-')
	{
		neg = -neg;
		nb += 1;
	}
	if (ft_strchr("+-", *nb) || ft_isdigit(*nb))
		ft_isdigit(*nb) ? rec_conv(nb, nativebase, base, &ret)
			: rec_conv(nb + 1, nativebase, base, &ret);
	return (ret * neg);
}
