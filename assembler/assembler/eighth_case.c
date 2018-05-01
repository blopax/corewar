#include "asm.h"
#include "ft_printf.h"
#include "op.h"

/*
*	16 aff : RG
*/

int		*get_eighth_ocp()
{
	int		*ret;

	ret = (int*)ft_memalloc(sizeof(int) * 3);
	ret[2] = 4;
	size_and_ocp(ret, 1, 6, 2);
	return (ret);
}

int		eighth_case(char *line, char **split, int op, t_label *act)
{
	int		len;
	char	*tmp;

	if ((len = check_param(split[0], 1, &tmp)))
	{
		if ((*tmp == COMMENT_CHAR
			|| (!*tmp && !split[1])) && !nb_letter(line, SEPARATOR_CHAR))
			return (add_op(split, op, act, get_eighth_ocp()));
	}
	return (0);
}