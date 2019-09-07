/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits_and_freer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 23:17:37 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/09/07 13:44:36 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		init_form(t_form *form)
{
	form->negative = 0;
	form->fg_va_holder = -1;
	form->native_index = -1;
	form->native_form = NULL;
	form->final_form = NULL;
	form->finfg = -1;
	form->arg.prefi = '\0';
	form->arg.signs = '\0';
	form->arg.justi = '\0';
	form->arg.width = -1;
	form->arg.preci = -1;
	form->arg.zfill = -1;
	form->arg.fsize = NULL;
	form->arg.type = '\0';
	return (0);
}

void	init_gvars(void)
{
	unsigned int i;

	i = 0;
	g_buffi = 0;
	while (i < BUFFSIZE)
		g_buff[i++] = '\0';
}

int		init_fg(t_args *fg)
{
	fg->prefi = '0';
	fg->signs = '0';
	fg->justi = '0';
	fg->width = -1;
	fg->preci = -1;
	fg->zfill = -1;
	fg->fsize = NULL;
	fg->type = '0';
	return (0);
}

void	t_form_freer(t_form *form)
{
	if (form->native_form != NULL)
		ft_strdel(&(form)->native_form);
	if (form->final_form != NULL)
		ft_strdel(&(form)->final_form);
	if (form->arg.fsize != NULL)
		ft_strdel(&(form)->arg.fsize);
}
