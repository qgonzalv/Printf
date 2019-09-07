/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vaint_module.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 23:18:51 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/08/30 23:18:54 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*xosharper(t_form *fm, char *nb, char xo)
{
	char	*hexoct;

	hexoct = nb;
	ft_strdel(&hexoct);
	nb = ft_strnew(1);
	if (fm->va_holder.uintmaxt == 0 && fm->arg.preci == 0 && xo == 'o'
			&& ft_strchr(fm->native_form, '#'))
		*nb = '0';
	if (fm->va_holder.uintmaxt == 0 && fm->arg.preci == 0
			&& (xo == 'x' || xo == 'X' || xo == 'o'))
		return (nb);
	return (nb);
}

static char		*prefixrenderer(char *nb, char xo)
{
	char	*swp;

	swp = nb;
	if (xo == 'x' || xo == 'X')
	{
		if (xo == 'x')
			nb = ft_strsfill(swp, "0x", 0);
		else
			nb = ft_strsfill(swp, "0X", 0);
	}
	if (xo == 'o' || xo == 'O')
		nb = ft_strsfill(swp, "0", 0);
	ft_strdel(&swp);
	return (nb);
}

static char		*hexoct_conv(char *nb, char xo, t_form *fm)
{
	char	*hexoct;

	hexoct = nb;
	if (xo == 'x' || xo == 'X')
	{
		if (fm->va_holder.uintmaxt == 0 && fm->arg.preci == 0)
			return (xosharper(fm, nb, xo));
		else if (xo == 'x')
			nb = ft_convert_base(nb, B_TENT, B_HEXL);
		else
			nb = ft_convert_base(nb, B_TENT, B_HEXC);
	}
	if (xo == 'o' || xo == 'O')
	{
		if (fm->va_holder.uintmaxt == 0 && fm->arg.preci == 0)
			return (xosharper(fm, nb, xo));
		else if (xo == 'o')
			nb = ft_convert_base(nb, B_TENT, B_OCTA);
		ft_strdel(&hexoct);
		return (nb);
	}
	ft_strdel(&hexoct);
	return (nb);
}

static char		*precirender(char *fin, t_form *fm, int len)
{
	char	*mod;

	mod = fin;
	if (fm->negative != 1)
		if (len - fm->arg.preci < 0)
			fin = ft_strcfill(fin, '0', 0, fm->arg.preci - len);
	if (fm->negative == 1)
		if (len - fm->arg.preci < 0)
			fin = ft_strcfill(fin, '0', 1, fm->arg.preci - len);
	ft_strdel(&mod);
	return (fin);
}

char			*int_renderer(t_form **fm)
{
	char	*fin;
	int		len;

	fin = ((*fm)->va_holder.uintmaxt == 0 && (*fm)->arg.preci == 0)
		? ft_strnew(1)
		: uintmaxt_itoa((*fm)->va_holder.uintmaxt, (*fm)->negative);
	if ((ft_strchr("oOxX", (*fm)->arg.type) && (*fm)->va_holder.uintmaxt == 0
				&& (*fm)->arg.prefi == '#'))
		(*fm)->arg.prefi = '\0';
	if (ft_strchr("xXoO", (*fm)->arg.type))
		fin = hexoct_conv(fin, (*fm)->arg.type, *fm);
	len = ((*fm)->negative == 1) ? ft_strlen(fin) - 1 : ft_strlen(fin);
	if ((*fm)->arg.prefi == '#' && (*fm)->va_holder.uintmaxt != 0
			&& (*fm)->arg.type == 'o' && len < (*fm)->arg.preci)
		(*fm)->arg.preci--;
	if ((*fm)->arg.preci > 0 && len < (*fm)->arg.preci)
		fin = precirender(fin, *fm, len);
	if ((*fm)->negative < 1 && ft_strchr("dDi", (*fm)->arg.type)
			&& (*fm)->arg.signs)
		fin = clean_pad(fin, *ft_strchr("+ ", (*fm)->arg.signs), 0, 1);
	if ((*fm)->arg.prefi == '#' && ft_strchr("xXoO", (*fm)->arg.type))
		fin = prefixrenderer(fin, (*fm)->arg.type);
	if ((*fm)->arg.zfill == 1 || (*fm)->arg.width > 0)
		fin = padrenderer(fin, *fm, len);
	return (fin);
}
