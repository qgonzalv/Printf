/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fieldpad.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 16:12:02 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/08/31 16:13:08 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*spacer(char *fin, t_form *fm, unsigned int i, int len)
{
	i = (fm->arg.justi == '-') ? ft_strlen(fin) : i;
	fin = clean_pad(fin, ' ', i, len);
	return (fin);
}

static char		*zfiller(char *fin, t_form *fm, unsigned int i, int len)
{
	i = (*fin == '-' || *fin == '+' || *fin == ' '
			|| (fm->arg.type == 'o' && fm->arg.prefi == '#')) ? 1 : 0;
	i = (ft_strchr("Xx", fm->arg.type) && fm->arg.prefi == '#') ?
		2 : i;
	fin = clean_pad(fin, '0', i, len);
	return (fin);
}

static char		*fieldpad(char *fin, t_form *fm)
{
	int				len;

	len = fm->arg.width - ft_strlen(fin);
	if (len > 0)
	{
		if (ft_strchr("duiofUD", fm->arg.type)
				|| (ft_strchr("xX", fm->arg.type)
					&& fm->arg.prefi != '#'))
		{
			if (fm->arg.zfill == 1)
				fin = zfiller(fin, fm, 0, len);
			else
				fin = spacer(fin, fm, 0, len);
		}
		else if (ft_strchr("xX", fm->arg.type)
				&& fm->arg.prefi == '#')
		{
			if (fm->arg.zfill == 1)
				fin = clean_pad(fin, '0', 2, len);
			else
				fin = spacer(fin, fm, 0, len);
		}
	}
	return (fin);
}

char			*padrenderer(char *fin, t_form *fm, int len)
{
	char	*swp;

	swp = fin;
	len = fm->arg.width - ft_strlen(fin);
	if (len > 0)
		fin = fieldpad(fin, fm);
	return (fin);
}
