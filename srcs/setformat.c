/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setformat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 23:18:12 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/09/07 14:45:01 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

static int		fg_checker(t_form *fg)
{
	if (fg->arg.prefi == '#' && fg->arg.preci == -1
			&& ft_strchr("aAeEfFgG", fg->arg.type))
		fg->arg.preci = 0;
	if ((fg->arg.signs == '+' || fg->arg.signs == ' ')
			&& ft_strchr("oOxXcsp", fg->arg.type))
		fg->arg.signs = '\0';
	if (fg->arg.zfill == 1
			&& (fg->arg.justi == '-' || fg->arg.preci != -1)
			&& ft_strchr("iuxXOodD", fg->arg.type))
		fg->arg.zfill = -1;
	if (fg->arg.zfill == 1 && ft_strchr("csp", fg->arg.type))
		fg->arg.zfill = -1;
	return (1);
}

static int		format_extract(t_form form, va_list arg)
{
	form.fg_va_holder = va_select(&form, arg);
	return (tostrdispatch(&form));
}

int				check_set_form(const char *ptr, va_list arg)
{
	int		len;
	t_form	form;

	init_form(&form);
	len = ft_strichrset(ptr + 1, CONVTYPE);
	form.native_index = g_buffi;
	form.native_form = ft_strsub(ptr, 0, len + 2);
	parse_set_fg_flags(&form, form.native_form);
	if (fg_checker(&form) == 1)
	{
		len = format_extract(form, arg);
		if (len == -1)
		{
			t_form_freer(&form);
			return (0);
		}
		t_form_freer(&form);
		return (len);
	}
	return (0);
}
