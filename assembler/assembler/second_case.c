#include "asm.h"
#include "ft_printf.h"
#include "op.h"

/*
*	02 ld		OCP : ID/D4, RG
*	13 lld		OCP : ID/D4, RG
*/

int		*get_second_ocp(char **split, int op)
{
	char	*tmp;
	int		*ret;

	op = 0;
	ret = (int*)ft_memalloc(sizeof(int) * 3);
	tmp = after_white_space(split[0]);
	ret[2] = 4;
	if (*tmp == DIRECT_CHAR)
			size_and_ocp(ret, 2, 6, 6);
	else
		size_and_ocp(ret, 3, 6, 4);
	size_and_ocp(ret, 1, 4, 1);
	return (ret);
}

int		second_case(char *line, char **split, int op, t_label *act)
{
	int		len;
	char	*tmp;

	if (split && split[0] && split[1])
	{
		len = check_param(after_white_space(split[0]), 6, &tmp);
		if (!len || *tmp)
			return (0);
		len = check_param(after_white_space(split[1]), 1, &tmp);
		if (len && (*tmp == COMMENT_CHAR
			|| (!*tmp && !split[2])) && nb_letter(line, SEPARATOR_CHAR) == 1)
			return (add_op(split, op, act, get_second_ocp(split, op)));
	}
	return (0);
}