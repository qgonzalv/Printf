/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoull_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:02:13 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/08/31 16:05:12 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		rec_conv(char *nb, char *nativebase, int base, uintmax_t *ret)
{
	int i;

	i = 0;
	if (*nb != '\0')
	{
		while (nativebase[i] != *nb)
			i++;
		*ret = (*ret * base) + i;
		rec_conv(nb + 1, nativebase, base, ret);
	}
	return ;
}

uintmax_t		ft_atoull_base(char *nb, char *nativebase)
{
	uintmax_t	ret;
	int			base;

	ret = 0;
	base = ft_strlen(nativebase);
	if (!nb || !*nb)
		return (0);
	while ((*nb >= 9 && *nb <= 13) || *nb == 32)
		nb++;
	if (ft_isdigit(*nb))
		rec_conv(nb, nativebase, base, &ret);
	return (ret);
}
