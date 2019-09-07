/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vap_module.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 23:19:07 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/08/30 23:19:12 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*precundefinedbehaviour(char *fin, t_form *fm, int len)
{
	char *mod;

	mod = fin;
	if (fm->arg.preci == 0 && fm->va_holder.vptr == 0)
	{
		free(fin);
		return (ft_strnew(1));
	}
	if (len - fm->arg.preci < 0)
		fin = ft_strcfill(mod, '0', 0, fm->arg.preci - len);
	else
		return (fin);
	ft_strdel(&mod);
	return (fin);
}

char			*p_renderer(t_form **fm)
{
	char	*final;
	char	*tmp;
	int		len;

	final = uintmaxt_itoa((uintptr_t)(*fm)->va_holder.vptr, 0);
	tmp = final;
	final = ft_convert_base(tmp, B_TENT, B_HEXL);
	ft_strdel(&tmp);
	tmp = final;
	if ((*fm)->arg.preci >= 0)
		final = precundefinedbehaviour(tmp, *fm, ft_strlen(tmp));
	tmp = final;
	final = ft_strsfill(tmp, "0x", 0);
	free(tmp);
	len = ft_strlen(final);
	if ((*fm)->arg.width > len)
	{
		tmp = final;
		final = ((*fm)->arg.justi == '-')
			? ft_strcfill(final, ' ', len, (*fm)->arg.width - len)
			: ft_strcfill(final, ' ', 0, (*fm)->arg.width - len);
		free(tmp);
	}
	return (final);
}
