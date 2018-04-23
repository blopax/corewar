# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atourner <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 10:42:44 by atourner          #+#    #+#              #
#    Updated: 2018/04/20 14:49:59 by atourner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

FLAGS = -Wall -Werror -Wextra

SRC_PATH = assembler/

COMP_PATH = obj/

SRC_ASSEMBLY = \
			my_ass.c\
			check_file.c\
			printf_file.c\
			is_file_valid.c\
			name_comment.c\
			get_label.c\
			get_opt.c\

SRC = $(addprefix $(SRC_PATH), $(SRC_ASSEMBLY))

COMP_NAME = $(SRC:.c=.o)

all : LIB $(NAME)

LIB:
	@make -C ft_printf

%.o : %.c
	@gcc $(FLAGS) -o $@ -c $< -Ift_printf/includes -Iincludes

$(NAME) : $(COMP_NAME)
	@gcc -o $(NAME) $(COMP_NAME) ft_printf/libftprintf.a
	@echo "\033[0;35mCompilation de la l'assembleur fini\033[0m"

clean :
	@echo "\033[0;31mPiou piou partially erased zone\033[0m"
	@rm -f $(COMP_NAME)
	@make clean -C ft_printf

fclean : clean
	@echo "\033[0;31mPiou piou sector clear\033[0m"
	@rm -f $(NAME)
	@make fclean -C ft_printf

re : recompil fclean all

recompil :
	@echo "\033[0;33mRecompilation de l'assembleur\033[0m"
