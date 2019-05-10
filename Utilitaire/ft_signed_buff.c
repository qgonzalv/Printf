/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signed_buff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 11:26:21 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/05/10 16:21:44 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_end_buff_deci(long long n, t_arg *arg, char *buff, char *out)
{
	if (arg->acc > 0)
		ft_fill(buff, "0", arg->acc);
	else if (arg->acc == 0)
		;
	else if ((arg->flags & M_ZERO) == M_ZERO && arg->wdth > 0)
		ft_fill(buff, "0", arg->wdth);
	ft_itoab(n, 10, out);
	if (n < 0)
		ft_fill(buff, &out[1], 0);
	else if (n != 0 || arg->acc != 0)
		ft_fill(buff, out, 0);
	if ((arg->wdth > 0 && (arg->flags & M_MINUS) == M_MINUS)
		&& ((arg->flags & M_ZERO) != M_ZERO || arg->acc > 0))
		ft_fill(buff, " ", arg->wdth);
	ft_fill(buff, NULL, 0);
	return (ft_putstr_fdbis(buff, arg->fd));
}

int			ft_buff_deci(long long n, t_arg *arg, char cnt, int len)
{
	char	buff[len + 1];
	char	out[cnt + 1];

	if (M_SPACE == (M_SPACE & arg->flags))
	{
		ft_fill(buff, " ", 1);
		(arg->wdth)--;
	}
	if ((arg->flags & M_MINUS) != M_MINUS && arg->wdth > 0
		&& (arg->acc >= 0 || (arg->flags & M_ZERO) != M_ZERO))
		ft_fill(buff, " ", arg->wdth);
	if (n < 0)
		ft_fill(buff, "-", 1);
	else if ((arg->flags & M_MORE) == M_MORE)
		ft_fill(buff, "+", 1);
	return (ft_end_buff_deci(n, arg, buff, out));
}
