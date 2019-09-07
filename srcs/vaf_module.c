/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vaf_module.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 23:18:42 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/08/30 23:18:45 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*f_precirender(long double lng, t_form *fm, int preci)
{
	char	*fin;

	if (preci == -1 || preci == 6)
		fin = ft_ldbltoa(lng, 6, fm->negative);
	else
		fin = ft_ldbltoa(lng, preci, fm->negative);
	fin = (fm->arg.prefi == '#' && fm->arg.preci <= 0)
		? clean_pad(fin, '.', ft_strlen(fin), 1) : fin;
	return (fin);
}

char	*f_renderer(t_form **fm)
{
	char	*fin;
	int		len;

	fin = f_precirender((*fm)->va_holder.ldble, *fm, (*fm)->arg.preci);
	len = ((*fm)->negative == 1) ? ft_strlen(fin) - 1 : ft_strlen(fin);
	if ((*fm)->negative < 1 && (*fm)->arg.signs)
		fin = clean_pad(fin, *ft_strchr("+ ", (*fm)->arg.signs), 0, 1);
	if ((*fm)->arg.zfill == 1 || (*fm)->arg.width > 0)
		fin = padrenderer(fin, *fm, len);
	return (fin);
}
