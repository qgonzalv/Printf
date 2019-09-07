/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 23:12:09 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/09/07 13:39:57 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		formatcheck(const char *p)
{
	return (ft_nchrchck(p + 1, OPT, ft_strichrset(p, CONVTYPE)));
}

static int		buff_feeder(const char *p, size_t size, va_list arg)
{
	int		len;
	int		no;
	size_t	i;

	i = 0;
	no = 0;
	while (p[i] && i < size)
	{
		while (p[i] && p[i] == '%' && isprcnt(&p[i]) == 1
				&& (no += prct(&p[i])) >= 0)
			i += update(&p[i]);
		while (p[i] && p[i] == '%')
		{
			len = formatcheck(&p[i]);
			i += (len == -1) ? ft_nonchrseti(&p[i + 1], OPT) : 0;
			if (len == -1 || len == 0)
				break ;
			no += check_set_form(&p[i], arg);
			i += len + 1;
		}
		no += securebuffer(p[i++]);
	}
	no += *g_buff ? buff_print() : 0;
	return (no);
}

int				ft_printf(const char *template, ...)
{
	va_list			arg;
	int				no;
	size_t			len;

	va_start(arg, template);
	init_gvars();
	if (template == NULL)
		return (-1);
	len = ft_strlen(template);
	if ((no = buff_feeder(template, len, arg)) == -1)
		return (-1);
	va_end(arg);
	return (no);
}
