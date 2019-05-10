/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 13:18:52 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/05/10 16:25:08 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#define M_DIEZE		0x01
#define M_NDIEZE 	0xfe
#define M_MINUS		0x02
#define M_NMINUS	0xfd
#define M_MORE		0x04
#define M_NMORE		0xfb
#define M_SPACE		0x08
#define M_NSPACE	0xf7
#define M_ZERO		0x10
#define M_NZERO		0xef
#define PF_LEN_NONE	0
#define PF_LEN_HH	1
#define PF_LEN_H	2
#define PF_LEN_Z	3
#define PF_LEN_T	4
#define PF_LEN_J	5
#define PF_LEN_L	6
#define PF_LEN_LL	7

static char	flag_founder(char const *s, int *i, t_arg *arg)
{
	while (s[*i] == ' ' || s[*i] == '+' || s[*i] == '-'
		|| s[*i] == '#' || s[*i] == '0')
	{
		if (s[*i] == ' ')
			arg->flags = (arg->flags | M_SPACE);
		else if (s[*i] == '+')
			arg->flags = (arg->flags | M_MORE);
		else if (s[*i] == '-')
			arg->flags = (arg->flags | M_MINUS);
		else if (s[*i] == '0')
			arg->flags = (arg->flags | M_ZERO);
		else
			arg->flags = (arg->flags | M_DIEZE);
		(*i)++;
	}
	return (arg->flags);
}

static int	get_with_n_accur(char const *s, int *i, va_list va)
{
	int	ret;

	ret = 0;
	while (s[(*i)] == '*' || ft_isdigit(s[*i]) == 1)
	{
		if (s[(*i)++] == '*')
			ret = va_arg(va, int);
		else
		{
			(*i)--;
			ret = ft_atoi(&s[*i]);
			while (ft_isdigit(s[*i]) != 1)
				(*i)++;
		}
	}
	return (ret);
}

void found_lenght(t_arg *arg, const char *s, int *i)
{
    while (s[*i] == 'h' || s[*i] == 'l' || s[*i] == 'j' || s[*i] == 'z'
		|| s[*i] == 't' || s[*i] == 'L')
	{
		(*i)++;
		if ((s[(*i) - 1] == 'l' && s[(*i)] == 'l') || s[(*i) - 1] == 'L')
			arg->len = PF_LEN_LL;
		else if (s[(*i) - 1] == 'l')
			arg->len = arg->len < PF_LEN_L ? PF_LEN_L : arg->len;
		else if (s[(*i) - 1] == 'j')
			arg->len = arg->len < PF_LEN_J ? PF_LEN_J : arg->len;
		else if (s[(*i) - 1] == 't')
			arg->len = arg->len < PF_LEN_T ? PF_LEN_T : arg->len;
		else if (s[(*i) - 1] == 'z')
			arg->len = arg->len < PF_LEN_Z ? PF_LEN_Z : arg->len;
		else if (s[(*i) - 1] == 'h' && s[*i] != 'h')
			arg->len = arg->len < PF_LEN_H ? PF_LEN_H : arg->len;
		else if (s[(*i) - 1] == 'h')
			arg->len = arg->len < PF_LEN_HH ? PF_LEN_HH : arg->len;
		if (s[*i] == 'h' || s[*i] == 'l')
			(*i)++;
	}
}

static void	ft_get_arg(char const *s, int *i, va_list va, t_arg *arg)
{
	while (s[*i] == ' ' || s[*i] == '+' || s[*i] == '-' || s[*i] == '#'
		|| s[*i] == '*' || s[*i] == '.' || s[*i] == 'h' || s[*i] == 'l'
			|| s[*i] == 'j' || s[*i] == 'z' || s[*i] == 't' || s[*i] == 'L'
				|| ft_isdigit(s[*i]) == 1)
	{
		arg->flags = flag_founder(s, i, arg);
		if (ft_isdigit(s[(*i)]) == 1 || s[(*i)] == '*')
			arg->wdth = get_with_n_accur(s, i, va);
		if (s[(*i)++] == '.')
			arg->acc = get_with_n_accur(s, i, va);
		else
			(*i)--;
		found_lenght(arg, s, i);
	}
}

void		ft_init_struct(char const *s, int *i, va_list va, t_arg *arg)
{
	arg->flags = 0;
	arg->wdth = 0;
	arg->acc = -1;
	arg->len = PF_LEN_NONE;
	ft_get_arg(s, i, va, arg);
	arg->spe = (s[(*i)++]);
	if (arg->spe == 0)
		(*i)--;
	if (arg->wdth < 0)
	{
		arg->wdth = -1 * (arg->wdth);
		arg->flags = (arg->flags | M_MINUS);
	}
	if ((arg->flags & M_MORE) == M_MORE)
		arg->flags = (arg->flags & M_NSPACE);
}

	//Voir si ca correspond a un flag : + - # 0 ' '
	//stocker flag dans la struct
	//width
	//Si '.' : faire atoi sur str
	//Stocker retours sur struct
	//Si ca tombe sur un char voir si il correspond a un specifier sinon c'est lenght
	// lenght :hh, h, l, ll
    //
