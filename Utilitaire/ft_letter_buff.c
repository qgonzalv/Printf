/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_letter_buff.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:45:49 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/05/10 15:50:21 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#define M_DIEZE		0x01
#define M_NDIEZE 	0xfe
#define M_MINUS		0x02
#define M_NMINUS	0xfd
#define M_MORE		0x04
#define M_NMORE		0xfb
#define M_SPACE		0x08
#define M_NSPACE	0xf7
#define M_ZERO		0x10
#define M_NZERO		0xef

static int	ft_letter_buff(char *s, t_arg *arg, int len)
{
	char	buff[len + 1];

	if ((arg->flags & M_MINUS) != M_MINUS && arg->wdth > 0)
	{
		if ((arg->flags & M_ZERO) != M_ZERO)
			ft_fill(buff, " ", arg->wdth);
		else
			ft_fill(buff, "0", arg->wdth);
	}
	if (s[0] == 0 && arg->spe == 'c')
		ft_fill(buff, "\0", 1);
	else
		ft_fill(buff, s, 0);
	if ((arg->flags & M_MINUS) == M_MINUS && arg->wdth > 0)
		ft_fill(buff, " ", arg->wdth);
	ft_fill(buff, NULL, 0);
	return (write(arg->fd, buff, len));
}

int			ft_str_pars(va_list va, t_arg *arg)
{
	int		cnt;
	char	cpy[ft_strlen(va_arg(va, char*)) + 1];
	char	nullstr[7];

	if (va_arg(va, char*) == NULL)
	{
		ft_strcpy(nullstr, "(null)");
		cnt = arg->acc < 0 ? 6 : ft_strnlen(nullstr, arg->acc);
		nullstr[cnt] = 0;
	}
	else
	{
		if (arg->acc < 0 || arg->spe == 'C' || arg->spe == 'c')
			cnt = ft_strlen(va_arg(va, char*));
		else
			cnt = ft_strnlen(va_arg(va, char*), arg->acc);
		ft_strncpy(cpy, va_arg(va, char*), cnt);
	}
	arg->wdth = arg->wdth - cnt;
	arg->wdth = arg->wdth < 0 ? 0 : arg->wdth;
	if (va_arg(va, char*) == NULL)
		return (ft_letter_buff(nullstr, arg, (cnt + arg->wdth)));
	return (ft_letter_buff(cpy, arg, (cnt + arg->wdth)));
}

int			ft_letter_pars(va_list va, t_arg *arg)
{
	char	s[2];

	s[0] = va_arg(va, char*)[0] + 0;
	s[1] = 0;
	arg->wdth = arg->wdth - 1;
	arg->wdth = arg->wdth < 0 ? 0 : arg->wdth;
	return (ft_letter_buff(s, arg, 1 + arg->wdth));
}
