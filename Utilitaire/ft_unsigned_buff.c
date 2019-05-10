/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_buff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:25:16 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/05/10 15:55:32 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_buff_hexa(t_ull n, t_arg *arg, char cnt, int len)
{
	char	buff[len + 1];
	char	out[cnt + 1];

	if ((arg->flags & M_MINUS) != M_MINUS && arg->wdth > 0
		&& (arg->acc >= 0 || (arg->flags & M_ZERO) != M_ZERO))
		ft_fill(buff, " ", arg->wdth);
	if (((arg->flags & M_DIEZE) == M_DIEZE && n != 0) || arg->spe == 'p')
		ft_fill(buff, "0x", 0);
	if (arg->acc > 0)
		ft_fill(buff, "0", arg->acc);
	else if (arg->acc == 0)
		;
	else if ((arg->flags & M_ZERO) == M_ZERO && arg->wdth > 0)
		ft_fill(buff, "0", arg->wdth);
	if (n != 0 | arg->acc != 0)
		ft_fill(buff, ft_uitoab(n, 16, out), 0);
	if ((arg->wdth > 0 && (arg->flags & M_MINUS) == M_MINUS)
		&& ((arg->flags & M_ZERO) != M_ZERO || arg->acc > 0))
		ft_fill(buff, " ", arg->wdth);
	ft_fill(buff, NULL, 0);
	if (arg->spe != 'X')
		return (ft_putstr_fdbis(buff, arg->fd));
	else
		return (ft_putstr_fdbis(ft_strupper(buff), arg->fd));
}

int	ft_buff_octa(t_ull n, t_arg *arg, char cnt, int len)
{
	char	buff[len + 1];
	char	out[cnt + 1];

	if (M_DIEZE == (M_DIEZE & arg->flags) && n != 0)
		(arg->acc)--;
	if ((arg->flags & M_MINUS) != M_MINUS && arg->wdth > 0
		&& (arg->acc >= 0 || (arg->flags & M_ZERO) != M_ZERO))
		ft_fill(buff, " ", arg->wdth);
	if ((arg->flags & M_DIEZE) == M_DIEZE && (n != 0 || arg->acc == 0))
		ft_fill(buff, "0", 1);
	if (arg->acc > 0)
		ft_fill(buff, "0", arg->acc);
	else if (arg->acc == 0)
		;
	else if ((arg->flags & M_ZERO) == M_ZERO && arg->wdth > 0)
		ft_fill(buff, "0", arg->wdth);
	if (n != 0 | arg->acc != 0)
		ft_fill(buff, ft_uitoab(n, 8, out), 0);
	if ((arg->wdth > 0 && (arg->flags & M_MINUS) == M_MINUS)
		&& ((arg->flags & M_ZERO) != M_ZERO || arg->acc > 0))
		ft_fill(buff, " ", arg->wdth);
	ft_fill(buff, NULL, 0);
	return (ft_putstr_fdbis(buff, arg->fd));
}

int	ft_buff_udeci(t_ull n, t_arg *arg, char cnt, int len)
{
	char	buff[len + 1];
	char	out[cnt + 1];

	if ((arg->flags & M_MINUS) != M_MINUS && arg->wdth > 0
		&& (arg->acc >= 0 || (arg->flags & M_ZERO) != M_ZERO))
		ft_fill(buff, " ", arg->wdth);
	if (arg->acc > 0)
		ft_fill(buff, "0", arg->acc);
	else if (arg->acc == 0)
		;
	else if ((arg->flags & M_ZERO) == M_ZERO && arg->wdth > 0)
		ft_fill(buff, "0", arg->wdth);
	if (n != 0 | arg->acc != 0)
		ft_fill(buff, ft_uitoab(n, 10, out), 0);
	if ((arg->wdth > 0 && (arg->flags & M_MINUS) == M_MINUS)
		&& ((arg->flags & M_ZERO) != M_ZERO || arg->acc > 0))
		ft_fill(buff, " ", arg->wdth);
	ft_fill(buff, NULL, 0);
	return (ft_putstr_fdbis(buff, arg->fd));
}

int	ft_buff_bin(t_ull n, t_arg *arg, char cnt, int len)
{
	char	buff[len + 1];
	char	out[cnt + 1];

	if ((arg->flags & M_MINUS) != M_MINUS && arg->wdth > 0
		&& (arg->acc >= 0 || (arg->flags & M_ZERO) != M_ZERO))
		ft_fill(buff, " ", arg->wdth);
	if ((arg->flags & M_DIEZE) == M_DIEZE && n != 0)
		ft_fill(buff, "0b", 0);
	if (arg->acc > 0)
		ft_fill(buff, "0", arg->acc);
	else if (arg->acc == 0)
		;
	else if ((arg->flags & M_ZERO) == M_ZERO && arg->wdth > 0)
		ft_fill(buff, "0", arg->wdth);
	if (n != 0 | arg->acc != 0)
		ft_fill(buff, ft_uitoab(n, 2, out), 0);
	if ((arg->wdth > 0 && (arg->flags & M_MINUS) == M_MINUS)
		&& ((arg->flags & M_ZERO) != M_ZERO || arg->acc > 0))
		ft_fill(buff, " ", arg->wdth);
	ft_fill(buff, NULL, 0);
	if (arg->spe == 'b')
		return (ft_putstr_fdbis(buff, arg->fd));
	else
		return (ft_putstr_fdbis(ft_strupper(buff), arg->fd));
}
