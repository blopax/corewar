# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pclement <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/19 16:32:58 by pclement          #+#    #+#              #
#    Updated: 2018/06/19 16:33:04 by pclement         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#deps
DEPENDENCIES = Makefile vm/Makefile assembler/Makefile

.SUFFIXES:
.PHONY: clean fclean all re

all: $(DEPENDENCIES)
	@$(MAKE) -C vm/
	@$(MAKE) -C assembler/

clean:
	@$(MAKE) -C vm/ clean
	@$(MAKE) -C assembler/ clean

fclean: clean
	@$(MAKE) -C vm/ fclean
	@$(MAKE) -C assembler/ fclean

re:
	@echo "Recompiling"
	@$(MAKE) fclean
	@$(MAKE) all
