/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vastr_module.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 23:19:18 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/09/06 09:50:03 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*str_renderer(t_form **fm)
{
	char	*final;
	char	*tmp;
	int		len;
	int		wid;

	if ((*fm)->va_holder.str == NULL)
		final = ft_strtruncto("(null)", (*fm)->arg.preci);
	else
		final = ft_strtruncto((*fm)->va_holder.str, (*fm)->arg.preci);
	wid = (*fm)->arg.width;
	len = ft_strlen(final);
	if (wid > len)
	{
		tmp = final;
		final = ((*fm)->arg.justi == '-')
			? ft_strcfill(final, ' ', len, wid - len)
			: ft_strcfill(final, ' ', 0, wid - len);
		free(tmp);
	}
	return (final);
}
