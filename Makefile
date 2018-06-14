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
