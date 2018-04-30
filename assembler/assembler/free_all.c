#include "ft_printf.h"
#include "asm.h"
#include "op.h"

int		free_and_ret(char **ar_str, int *tab, int ret)
{
	ft_free_ar((void**)ar_str);
	free(tab);
	return (ret);
}