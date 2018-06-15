# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atourner <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 10:42:44 by atourner          #+#    #+#              #
#    Updated: 2018/06/15 13:43:26 by pclement         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

CFLAGS = -Wall -Werror -Wextra

SRC_PATH = src/

H = includes/asm.h includes/op.h

COMP_PATH = obj/

SRC_ASSEMBLY = \
			my_ass.c\
			check_file.c\
			printf_file.c\
			is_file_valid.c\
			name_comment.c\
			get_label.c\
			get_opt.c\
			basic_parameter.c\
			add_op.c\
			free_all.c\
			utilities.c\
			utilities2.c\
			utilities3.c\
			first_case.c\
			second_case.c\
			third_case.c\
			fourth_case.c\
			fifth_case.c\
			sixth_case.c\
			seventh_case.c\
			eighth_case.c\
			op_to_str.c\
			print_error.c\

SRC = $(addprefix $(SRC_PATH), $(SRC_ASSEMBLY))

COMP_NAME = $(SRC:.c=.o)

LIB_PATH = ft_printf

all : LIB $(NAME)

LIB:
	@make -C $(LIB_PATH)

%.o : %.c $(H) $(LIB_PATH)/libftprintf.a
	@gcc -o $@ $(CFLAGS) -c $< -I$(LIB_PATH)/includes -Iincludes

$(NAME) : $(COMP_NAME) Makefile
	@gcc -o $(NAME) $(COMP_NAME) $(LIB_PATH)/libftprintf.a
	@echo "\033[0;35mCompilation de la l'assembleur fini\033[0m"

clean :
	@echo "\033[0;31mPiou piou partially erased zone\033[0m"
	@rm -f $(COMP_NAME)
	@make clean -C $(LIB_PATH)

fclean : clean
	@echo "\033[0;31mPiou piou sector clear\033[0m"
	@rm -f $(NAME)
	@make fclean -C $(LIB_PATH)

re : recompil fclean all

recompil :
	@echo "\033[0;33mRecompilation de l'assembleur\033[0m"
