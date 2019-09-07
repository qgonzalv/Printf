/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percentmanager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 23:17:56 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/09/05 16:59:58 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		tmpfgset(t_args *fg, const char *p)
{
	int i;

	i = 0;
	while (!ft_isdigit(p[i]))
	{
		if (p[i] == '-')
			fg->justi = '-';
		if (p[i] == '.')
			return ;
		i++;
	}
	while (p[i] == '0')
		i++;
	if (p[i] != '0' && ft_isdigit(p[i]))
	{
		fg->width = ft_atoi(&p[i]);
		return ;
	}
}

static char		*percentrenderer(t_args fg)
{
	char *tmp;

	tmp = ft_strnew(2);
	*tmp = '%';
	if (fg.width > -1)
	{
		if (fg.justi == '-')
			tmp = clean_pad(tmp, ' ', 1, fg.width - 1);
		if (fg.justi != '-')
			tmp = clean_pad(tmp, ' ', 0, fg.width - 1);
	}
	return (tmp);
}

int				isprcnt(const char *p)
{
	int i;
	int len;

	i = 0;
	len = ft_nchrchck(&p[i], PRCNT, ft_strichr(&p[i + 1], '%') + 1);
	if (len >= 0 || p[1] == '%')
		return (1);
	return (0);
}

int				update(const char *p)
{
	int i;

	i = 0;
	if (p[i] == '%' && p[1] == '%')
		return (2);
	else if (ft_nchrchck(&p[i], PRCNT, ft_strichrset(&p[i], "%")) != -1)
		return (ft_strichr(&p[i + 1], '%') + 2);
	return (0);
}

int				prct(const char *p)
{
	int		i;
	int		len;
	char	*tmp;
	t_args	fg;

	i = 0;
	len = 0;
	if (p[i] == '%' && p[i + 1] == '%')
	{
		tmp = ft_strnew(1);
		*tmp = '%';
		return (print_flush(tmp));
	}
	else if (ft_nchrchck(&p[i], PRCNT, ft_strichrset(&p[i], "%")) != -1)
	{
		init_fg(&fg);
		tmpfgset(&fg, p);
		tmp = percentrenderer(fg);
		len = print_flush(tmp);
		return (len);
	}
	return (0);
}
