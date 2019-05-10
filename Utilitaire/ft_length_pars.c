/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_pars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 11:25:03 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/05/10 15:54:14 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_more_unsigned_cnt(t_ull n, char cnt, t_arg *arg)
{
	int		len;

	arg->wdth = arg->acc > 0 ? arg->wdth - cnt - arg->acc : arg->wdth - cnt;
	arg->wdth = arg->wdth > 0 ? arg->wdth : 0;
	len = arg->acc > 0 ? arg->wdth + cnt + arg->acc : arg->wdth + cnt;
	if (arg->base == 16)
		return (ft_buff_hexa(n, arg, cnt, len));
	else if (arg->base == 10)
		return (ft_buff_udeci(n, arg, cnt, len));
	else if (arg->base == 8)
		return (ft_buff_octa(n, arg, cnt, len));
	else if (arg->base == 2)
		return (ft_buff_bin(n, arg, cnt, len));
	return (0);
}

static int	ft_unsigned_cnt(t_ull n, t_arg *arg)
{
	char	cnt;

	if (arg->spe == 'p' || arg->spe == 'x' || arg->spe == 'X')
		arg->base = 16;
	else if (arg->spe == 'o')
		arg->base = 8;
	else if (arg->spe == 'u')
		arg->base = 10;
	else if (arg->spe == 'b')
		arg->base = 2;
	cnt = (n == 0 && arg->acc == 0) ? 0 : ft_ucntb(n, arg->base);
	if (arg->acc != 0)
		arg->acc = arg->acc > cnt ? arg->acc - cnt : -1;
	if ((arg->base == 16 || arg->base == 8 || arg->base == 2)
			&& ((M_DIEZE & arg->flags) == M_DIEZE) && (n != 0 || arg->spe == 'p'))
		cnt = arg->base == 8 ? cnt + 1 : cnt + 2;
	return (ft_more_unsigned_cnt(n, cnt, arg));
}

int			ft_unsigned_pars(va_list va, t_arg *arg)
{
	if ((arg->flags & M_MINUS) == M_MINUS || (arg->acc > -1))
		arg->flags = (arg->flags & M_NZERO);
	arg->flags = (arg->flags & M_NMORE);
	if (arg->spe == 'p')
	{
		arg->flags = (arg->flags | M_DIEZE);
		return (ft_unsigned_cnt((long long)va_arg(va, void*), arg));
	}
	else if (arg->len == PF_LEN_LL)
		return (ft_unsigned_cnt(va_arg(va, t_ull), arg));
	else if (arg->len == PF_LEN_L || arg->spe == 'O' || arg->spe == 'U')
		return (ft_unsigned_cnt(va_arg(va, unsigned long), arg));
	else if (arg->len == PF_LEN_H)
		return (ft_unsigned_cnt((unsigned short)va_arg(va, int), arg));
	else if (arg->len == PF_LEN_HH)
		return (ft_unsigned_cnt((unsigned char)va_arg(va, int), arg));
	// else if (arg->len == PF_LEN_J)
	// 	return (ft_unsigned_cnt(va_arg(va, uintmax_t), arg));
	// else if (arg->len == PF_LEN_Z)
	// 	return (ft_unsigned_cnt(va_arg(va, size_t), arg));
	// else if (arg->len == PF_LEN_T)
	// 	return (ft_unsigned_cnt(va_arg(va, ptrdiff_t), arg));
	return (ft_unsigned_cnt(va_arg(va, unsigned int), arg));
}

static int	ft_signed_cnt(long long n, t_arg *arg)
{
	char	cnt;
	int		len;

	arg->base = 10;
	cnt = (n == 0 && arg->acc == 0) ? 0 : ft_cntb(n, arg->base);
	if (arg->acc != 0)
		arg->acc = arg->acc > cnt ? arg->acc - cnt : -1;
	if (n < 0)
	{
		cnt++;
		arg->flags = (M_NSPACE & arg->flags);
	}
	else if ((arg->flags & M_MORE) == M_MORE)
		cnt++;
	arg->wdth = arg->acc > 0 ? arg->wdth - cnt - arg->acc : arg->wdth - cnt;
	arg->wdth = arg->wdth < 1 && (M_SPACE & arg->flags) == M_SPACE ? 1 : arg->wdth;
	len = arg->acc > 0 ? arg->wdth + cnt + arg->acc : arg->wdth + cnt;
	return (ft_buff_deci(n, arg, cnt, len));
}

int			ft_signed_pars(va_list va, t_arg *arg)
{
	if ((arg->flags & M_MINUS) == M_MINUS || (arg->acc > -1))
		arg->flags = (arg->flags & M_NZERO);
	if (arg->len == PF_LEN_LL)
		return (ft_signed_cnt(va_arg(va, long long), arg));
	else if (arg->len == PF_LEN_L || arg->spe == 'D')
		return (ft_signed_cnt(va_arg(va, long), arg));
	else if (arg->len == PF_LEN_H)
		return (ft_signed_cnt((short)va_arg(va, int), arg));
	else if (arg->len == PF_LEN_HH)
		return (ft_signed_cnt((signed char)va_arg(va, int), arg));
	else if (arg->len == PF_LEN_J)
		return (ft_signed_cnt(va_arg(va, intmax_t), arg));
	else if (arg->len == PF_LEN_Z)
		return (ft_signed_cnt(va_arg(va, size_t), arg));
	else if (arg->len == PF_LEN_T)
		return (ft_signed_cnt(va_arg(va, ptrdiff_t), arg));
	return (ft_signed_cnt(va_arg(va, int), arg));
}

size_t	ft_putstr_fdbis(char const *s, int fd)
{
	if (s == NULL)
		return (0);
	return (write(fd, s, ft_strlen(s)));
}
