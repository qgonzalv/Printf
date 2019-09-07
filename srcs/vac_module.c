/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vac_module.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 23:18:34 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/08/30 23:18:36 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*c_renderer(t_form **fm)
{
	char	*final;
	char	*tmp;
	int		wid;

	wid = (*fm)->arg.width;
	if (!(final = ft_strnew(1)))
		return (NULL);
	*final = (*fm)->va_holder.car;
	if (*final == '\0')
	{
		*final = '1';
		(*fm)->finfg = 1;
	}
	if ((*fm)->arg.width >= 2)
	{
		tmp = final;
		final = ((*fm)->arg.justi == '-')
			? ft_strcfill(final, ' ', 1, wid - 1)
			: ft_strcfill(final, ' ', 0, wid - 1);
		free(tmp);
	}
	return (final);
}
