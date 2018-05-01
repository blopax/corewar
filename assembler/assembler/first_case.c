#include "asm.h"
#include "ft_printf.h"
#include "op.h"

/*
*	01 live : D4
*	09 zjmp : D2
*	12 fork : D2
*	15 lfork : D2
*/

int		*get_first_ocp(int op)
{
	int		*ret;

	ret = (int*)ft_memalloc(sizeof(int) * 3);
	ret[2] = 4;
	if (op == 1)
		size_and_ocp(ret, 2, 6, 5);
	else
	{
		size_and_ocp(ret, 2, 6, 3);
		ret[2] = 2;
	}
	return (ret);
}

int		first_case(char *line, char **split, int op, t_label *act)
{
	int		len;
	char	*tmp;

	if ((len = check_param(split[0], 2, &tmp)))
		if ((*tmp == COMMENT_CHAR
			|| (!*tmp && !split[1])) && !nb_letter(line, SEPARATOR_CHAR))
			return (add_op(split, op, act, get_first_ocp(op)));
	return (0);
}