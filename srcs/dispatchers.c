/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatchers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 23:06:43 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/08/31 16:13:08 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		tostrdispatch(t_form *form)
{
	char	*(*dispatch[7])(t_form **);

	if (form->fg_va_holder == -1)
		return (-1);
	dispatch[0] = &p_renderer;
	dispatch[1] = &c_renderer;
	dispatch[3] = &str_renderer;
	dispatch[5] = &int_renderer;
	dispatch[6] = &f_renderer;
	form->final_form = dispatch[form->fg_va_holder](&form);
	return (print_dispatch(form));
}
