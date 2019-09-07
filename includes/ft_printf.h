/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:19:50 by qgonzalv          #+#    #+#             */
/*   Updated: 2019/09/06 09:55:07 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BUFFSIZE 4096
# define OPT "#-+ 0123456789.hlLzcCsSpDdioUueEfFgGxX"
# define CONVTYPE "CcSspDdioUufFxX"
# define INTEGERS "dDiUuoxX"
# define PRCNT " #*-+0123456789%."
# define FLAG "#+- 0"
# define SIZE "hlLz"
# define PREC ".0123456789"
# define B_HEXL "0123456789abcdef"
# define B_HEXC "0123456789ABCDEF"
# define B_TENT "0123456789"
# define B_OCTA "01234567"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <wchar.h>
# include <sys/types.h>
# include "libft.h"

char	g_buff[BUFFSIZE];
int		g_buffi;

typedef union	u_varpkg {
	void			*vptr;
	char			car;
	wint_t			carc;
	char			*str;
	wchar_t			*strs;
	intmax_t		intmaxt;
	uintmax_t		uintmaxt;
	long double		ldble;
}				t_var;

typedef struct	s_args {
	char		prefi;
	char		signs;
	char		justi;
	int			width;
	int			preci;
	int			zfill;
	char		*fsize;
	char		type;
}				t_args;

typedef struct	s_formats {
	t_args		arg;
	t_var		va_holder;
	int			native_index;
	int			fg_va_holder;
	int			negative;
	char		*native_form;
	char		*final_form;
	int			finfg;
}				t_form;

int				ft_printf(const char *format, ...);
int				prct(const char *p);
int				update(const char *p);
int				isprcnt(const char *p);
int				init_form(t_form *form);
void			init_gvars(void);
int				init_fg(t_args *fg);
void			t_form_freer(t_form *form);
int				buff_print(void);
int				securebuffer(char c);
int				print_flush(char *form);
int				print_dispatch(t_form *fin);
int				check_set_form(const char *temp_form, va_list arg);
int				parse_set_fg_flags(t_form *form, char *nat);
int				parse_set_fg_pre(t_form **fg, char *format);
int				parse_set_fg_siz(t_form **fg, char *format);
int				parse_set_fg_pad(t_form **form, char *format);
int				parse_set_fg_wid(t_form **fg, char *format);
int				va_select(t_form *form, va_list arg);
int				cva(t_form **form, va_list arg);
int				sva(t_form **form, va_list arg);
int				diva(t_form **form, va_list arg);
int				uva(t_form **form, va_list arg);
int				fva(t_form **form, va_list arg);
int				tostrdispatch(t_form *form);
char			*str_renderer(t_form **fm);
char			*c_renderer(t_form **fm);
char			*p_renderer(t_form **fm);
char			*lc_renderer(t_form **fm);
char			*ls_renderer(t_form **fm);
char			*int_renderer(t_form **fm);
char			*f_renderer(t_form **fm);
char			*padrenderer(char *fin, t_form *fm, int len);
#endif
