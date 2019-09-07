/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_argset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 23:18:23 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/08/30 23:18:27 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				va_select(t_form *form, va_list arg)
{
	if (form->arg.type == 'p')
	{
		form->va_holder.vptr = va_arg(arg, void *);
		return (0);
	}
	else if (ft_strchr("dDi", form->arg.type))
		return (diva(&form, arg));
	else if (ft_strchr("sS", form->arg.type))
		return (sva(&form, arg));
	else if (ft_strchr("cC", form->arg.type))
		return (cva(&form, arg));
	else if (ft_strchr("UuoOxX", form->arg.type))
		return (uva(&form, arg));
	else if (ft_strchr("eEfFgG", form->arg.type))
		return (fva(&form, arg));
	return (-1);
}
