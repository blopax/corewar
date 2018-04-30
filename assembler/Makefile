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
			check1_5.c\
			check6_10.c\
			basic_parameter.c\
			add_op.c\
			get_ocp.c\
			free_all.c\

SRC = $(addprefix $(SRC_PATH), $(SRC_ASSEMBLY))

COMP_NAME = $(SRC:.c=.o)

LIB_PATH = ft_printf

all : LIB $(NAME)

LIB:
	@make -C $(LIB_PATH)

%.o : %.c
	@gcc $(FLAGS) -o $@ -c $< -I$(LIB_PATH)/includes -Iincludes

$(NAME) : $(COMP_NAME)
	@gcc $(FLAGS) -o $(NAME) $(COMP_NAME) $(LIB_PATH)/libftprintf.a
	@echo "\033[0;35mCompilation de la l'assembleur fini\033[0m"

leaks:
	@~/Applications/clang/bin/clang $(FLAGS) -g -fsanitize=leak -o $(NAME) $(COMP_NAME) $(LIB_PATH)/libftprintf.a

address:
	@~/Applications/clang/bin/clang $(FLAGS) -g -fsanitize=address -fno-omit-frame-pointer -o $(NAME) $(COMP_NAME) $(LIB_PATH)/libftprintf.a

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
