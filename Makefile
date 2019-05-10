# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/03 14:08:59 by qgonzalv          #+#    #+#              #
#    Updated: 2019/05/10 16:39:30 by qgonzalv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = clang
CC := gcc
NAME = libftprintf.a
FLAGS = -Wall -Wextra
LIBFT = ../LibFT
DIR_S = ./sources
DIR_U = ./Utilitaire
DIR_O = ./temporary
HEADER = ./includes
UTIL = ft_init_arg.c ft_lenght_pars.c ft_letter_buff.c libftUtil.c \
		ft_setup.c ft_signed_buff.c ft_unsigned_buff.c ft_full_struct.c\
		main.c ft_printf.c

all: $(NAME)
$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@echo "\033[31;1m	 OK1\033[0m"
	@cp $(LIBFT)/libft.a ./$(NAME)
	@echo "\033[31;1m	 OK2\033[0m"
	@mkdir -p temporary
	@echo "\033[31;1m	 OK3\033[0m"
	@gcc ./Utilitaire/*.c -c
	@echo "\033[31;1m	 OK4\033[0m"
	@mv *.o $(DIR_O)
	@echo "\033[31;1m	 OK5\033[0m"
	@ar rc $(NAME) $(DIR_O)/*
	@echo "\033[31;1m	 OK6\033[0m"
	@ranlib $(NAME)
%.o: %.c
	@mkdir -p temporary
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<
norme:
	norminette ./libft/
	@echo
	norminette ./$(HEADER)/
	@echo
	norminette ./$(DIR_S)/
	@echo "\033[31;1m	NORME OK\033[0m"
clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)
	@echo "\033[31;1m	CLEANING DONE\033[0m"
fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)
	@echo "\033[36m	LIBFTPRINTF.A\033[33m ====\033[1m> \033[31;1mDELETED\033[0m"
re: fclean all
