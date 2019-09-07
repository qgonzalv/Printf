# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/31 14:34:13 by qgonzalv          #+#    #+#              #
#    Updated: 2019/09/06 15:26:20 by qgonzalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


GCC = gcc
GCCC = $(CC) -c
DEBUG = $(CC) -g -c
PATHSRCS = srcs/
WWW = -Wall -Wextra -Werror

SRCS_PRINTF = 	buff_print.c \
				checkform.c\
				dispatchers.c\
				fieldpad.c\
				ft_printf.c\
				inits_and_freer.c\
				percentmanager.c\
				setformat.c\
				va_argset.c\
				valist_fetch.c\
				vac_module.c\
				vaint_module.c\
				vaf_module.c\
				vastr_module.c\
				vap_module.c




SRCS_CHCK = ft_recursive_power.c\
			ft_isdigit.c\
			ft_nchrchck.c

SRCS_MEM = ft_strdel.c\
			 ft_memset.c

SRCS_PRINT = ft_putstr.c

SRCS_STR = ft_nonchrseti.c\
			ft_clean_pad.c\
			ft_bzero.c\
			ft_strchr.c\
			ft_strcmp.c\
			ft_strdup.c\
			ft_strjoin.c\
			ft_strlen.c\
			ft_strnew.c\
			ft_strrchr.c\
			ft_strsub.c\
			ft_strichr.c\
			ft_strrev.c\
			ft_strichrset.c\
			ft_strndup.c\
			ft_strchrsetc.c\
			ft_strchrset.c\
			ft_strrchrset.c\
			ft_strcfill.c\
			ft_strsfill.c\
			ft_strtruncto.c\
			ft_strcpy.c

SRCS_CONV 	= 	ft_itoa.c \
			 	ft_atoi.c\
			 	ft_base_check_and_strlen.c\
			 	ft_atoi_base.c\
				ft_itoa_base.c\
				ft_umaxt_itoa.c\
				ft_atoull_base.c\
				ft_atoll_base.c\
				ft_convert_base.c\
				ft_lgdbl_toa.c

SRCS = $(addprefix $(PATHSRCS), $(SRCS_PRINTF) $(SRCS_MEM) $(SRCS_STR) $(SRCS_CONV) $(SRCS_PRINT) $(SRCS_CHCK))

BJCOM		=	$(notdir $(SRCCOM:.c=.o))

OBJ			=	$(notdir $(SRCS:.c=.o))

OBJDIR		=	tmpdir/

LIB_DIR 	=	./libft/

LIBFT 		=	./libft/libft.a

PRINTF 	=	libftprintf.a

OBJS = tmp

MAIN = /Users/qgonzalv/main_printf.c

NO_COLOR    = \033[m

BLACK       = \033[0;30m

ERROR_COLOR = \033[0;31m

OK_COLOR    = \033[0;32m

WARN_COLOR  = \033[0;33m

COM_COLOR   = \033[0;34m

PURPLE      = \033[0;35m

OBJ_COLOR   = \033[0;36m

WHITE       = \033[0;37m

all :
			@$(MAKE) -C $(LIB_DIR)
			@mkdir -p $(OBJDIR)
			@$(GCCC) $(SRCS)
			@mv $(OBJ) $(OBJDIR)
			@ar rc $(PRINTF) $(addprefix $(OBJDIR), $(OBJ))
			@echo "\033[36m	PRINTF\033[33m ====\033[1m> \033[32;1mREADY TO USE\033[0m"

comp :	fclean all
			@gcc -Wall -Wextra -Werror $(MAIN) $(PRINTF)
			@./a.out
clean :
			@$(MAKE) clean -C $(LIB_DIR)
			@rm -rf $(OBJDIR)
			@echo "\033[31;1m	CLEANING DONE\033[0m"

fclean : clean
			@$(MAKE) fclean -C $(LIB_DIR)
			@rm -rf $(OBJDIR)
			@echo "$(PURPLE)LIB     $(OK_COLOR)DELETED$(WHITE)"
			@echo "$(PURPLE)OBJS    $(OK_COLOR)DELETED$(WHITE)"

re : fclean all
