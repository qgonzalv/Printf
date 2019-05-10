/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 16:12:02 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/05/10 16:25:28 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
#include <wchar.h>
#include "../../LibFT/libft.h"
# define FT_PRINTF_H
# define M_DIEZE		0x01	//00000001
# define M_NDIEZE 	0xfe	//11111110
# define M_MINUS		0x02	//00000010
# define M_NMINUS	0xfd	//11111101
# define M_MORE		0x04	//00000100
# define M_NMORE		0xfb	//11111011
# define M_SPACE		0x08	//00001000
# define M_NSPACE	0xf7	//11110111
# define M_ZERO		0x10	//00010000
# define M_NZERO		0xef	//11101111
# define PF_LEN_NONE	0
# define PF_LEN_HH	1
# define PF_LEN_H	2
# define PF_LEN_Z	3
# define PF_LEN_T	4
# define PF_LEN_J	5
# define PF_LEN_L	6
# define PF_LEN_LL	7

typedef unsigned long long t_ull;

typedef struct s_arg
{
   	char		flags;
    int         fd;
    int         wdth;
    int         acc;
    char        len;
    char        spe;
    char        base;
}               t_arg;

typedef struct  s_spe
{
    int      (*ptrfonct)(va_list ap,t_arg *arg);
    char        key;
}               t_spe;

int         spe_founder(t_arg *arg, const char *c, va_list ap, int i);
int			ft_printf(char const *s, ...);
void        found_lenght(t_arg *arg, const char *s, int *i);

int			ft_unsigned_pars(va_list va, t_arg *arg);
int			ft_signed_pars(va_list va, t_arg *arg);
int			ft_str_pars(va_list va, t_arg *arg);
int			ft_letter_pars(va_list va, t_arg *arg);

static int	ft_signed_cnt(long long n, t_arg *arg);
static int	ft_unsigned_cnt(t_ull n, t_arg *arg);
static int	ft_more_unsigned_cnt(t_ull n, char cnt, t_arg *arg);

static int	ft_letter_buff(char *s, t_arg *arg, int len);

void		ft_init_arg(char const *s, int *i, va_list va, t_arg *arg);
static void	ft_get_arg(char const *s, int *i, va_list va, t_arg *arg);
static void	ft_get_length(char const *s, int *i, t_arg *arg);
static char	ft_get_flag(char const *s, int *i, t_arg *arg);
static int	ft_get_with_n_accur(char const *s, int *i, va_list va);

int	        ft_buff_hexa(t_ull n, t_arg *arg, char cnt, int len);
int     	ft_buff_octa(t_ull n, t_arg *arg, char cnt, int len);
int     	ft_buff_udeci(t_ull n, t_arg *arg, char cnt, int len);
int     	ft_buff_bin(t_ull n, t_arg *arg, char cnt, int len);

int		    ft_fill(char *s, char *s2, int len);
char    	ft_cntb(long long n, char b);
char	    *ft_strupper(char *s);
size_t  	ft_putstr_fdbis(char const *s, int fd);
char	    ft_ucntb(t_ull n, char b);
char	    *ft_itoab(long long n, char b, char *out);
size_t	    ft_strnlen(const char *s, size_t maxlen);
char	    *ft_uitoab(unsigned long long n, char b, char *out);
size_t	    ft_strclen(char const *str, int c);
// char	ft_define_fd(char const *s, int *i, va_list va, t_arg *arg);

int			ft_buff_deci(long long n, t_arg *arg, char cnt, int len);


t_spe g_tab[] =
{
    {&ft_unsigned_pars, 'x'},
    {&ft_unsigned_pars, 'u'},
    {&ft_unsigned_pars, 'o'},
    {&ft_unsigned_pars, 'X'},
    {&ft_signed_pars, 'd'},
    {&ft_signed_pars, 'i'},
    {&ft_str_pars, 's'},
    {&ft_letter_pars, 'c'},
    //{&flag_x, 'x'},
    // {&spe_X, 'X'},
    // {&spe_porcent, '%'},
     {NULL, -1}
};

#endif
