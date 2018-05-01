#include "asm.h"
#include "ft_printf.h"
#include "op.h"

/*
*	04 add et 05 sub OCP : RG, RG, RG
*/

int		*get_fourth_ocp()
{
	int		*ret;

	ret = (int*)ft_memalloc(sizeof(int) * 3);
	ret[2] = 4;
	size_and_ocp(ret, 1, 6, 3);
	size_and_ocp(ret, 1, 4, 1);
	size_and_ocp(ret, 1, 2, 1);
	return (ret);
}

int		fourth_case(char *line, char **split, int op, t_label *act)
{
	int		len;
	char	*tmp;

	if (split && split[0] && split[1] && split[2])
	{
		len = check_param(after_white_space(split[0]), 1, &tmp);
		if (!len || *tmp)
			return (0);
		len = check_param(after_white_space(split[1]), 1, &tmp);
		if (!len || *tmp)
			return (0);
		len = check_param(after_white_space(split[2]), 1, &tmp);
		if (len && (*tmp == COMMENT_CHAR
			|| (!*tmp && !split[3])) && nb_letter(line, SEPARATOR_CHAR) == 2)
			return (add_op(split, op, act, get_fourth_ocp()));
	}
	return (0);
}