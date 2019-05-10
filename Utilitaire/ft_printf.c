/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 11:25:54 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/05/10 15:11:41 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int        spe_founder(t_arg *arg, const char *str, va_list ap, int i)
{
    int j;

    j = 0;
    while (g_tab[j].key != -1)
    {
        if (g_tab[j].key == str[i]) // c correspond a str[j]
            return (g_tab[j].ptrfonct(ap, arg));
        j++;
    }
	return (0);
}

static int	ft_pars_type(char const *s,int *i, va_list va, t_arg *arg)
{
	(*i)++;

	ft_init_arg(s, i, va, arg);
	return (spe_founder(arg, s, va, *i));

}

int			ft_printf(char const *s, ...)
{
	va_list	va;
	t_arg	arg;
	int		i;
	int		len;

	if (s == NULL)
		return (-1);
	len = 0;
	va_start(va, s);
	arg.fd = 1;

	while (s[0] != 0)
	{
		i = ft_strclen(s, '%');
		// len = len + ft_putstrn_fd(s, arg.fd, i);
		if (s[i] == '%')
			len = len + ft_pars_type(s, &i, va, &arg);
		if (i == -42)
			break ;
		s = s + i;
		i = 0;
	}

	len = len < 0 ? -1 : len;
	va_end(va);
	return (i == -42 ? -1 : len);
}

// static int	ft_pars_type(char const *s, int len, va_list va, t_arg *arg)
// {}// if (s[*i] == '[')
	// 	return (ft_define_fd(s, i, va, arg));
	// ft_init_arg(s,i,va,arg);
	// if (arg->spe == 'x' || arg->spe == 'X' || arg->spe == 'p'
	// 	|| arg->spe == 'u' || arg->spe == 'o'
	// 		|| arg->spe == 'b' || arg->spe == 'B')
	// 	return (ft_unsigned_pars(va, arg));
	// else if (arg->spe == 'd' || arg->spe == 'i')
	// 	return (ft_signed_pars(va, arg));
	// if ((arg->spe == 'c' || arg->spe == 's'))
	// 	return (arg->spe != 'c' ? ft_str_pars(va_arg(va, char*), arg)
	// 		: ft_letter_pars(va_arg(va, int), arg));
	// else if (arg->spe == 0)
	// 	return (0);
	// else
	// 	return (ft_letter_pars(arg->spe, arg));
