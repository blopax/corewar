#include "ft_printf.h"
#include "asm.h"
#include "op.h"

/*
*	10 ldi		OCP : RG/ID/D2, RG/D2, RG
*	14 lldi		OCP : RG/ID/D2, RG/D2, RG
*/

int		seventh_case(char *line, char **split, int op, t_label *act)
{
	int		len;
	char	*tmp;

	if (split && split[0] && split[1] && split[2])
	{
		len = check_param(after_white_space(split[0]), 7, &tmp);
		if (!len || *tmp)
			return (0);
		len = check_param(after_white_space(split[1]), 3, &tmp);
		if (!len || *tmp)
			return (0);
		len = check_param(after_white_space(split[2]), 1, &tmp);
		if (len && (*tmp == COMMENT_CHAR
			|| (!*tmp && !split[3])) && nb_letter(line, SEPARATOR_CHAR) == 2)
			return (add_op(split, op, act, get_seventh_ocp(split)));
	}
	return (0);
}

/*
*	11 sti OCP : RG, RG/ID/D2, D2/RG
*/

int		eighth_case(char *line, char **split, int op, t_label *act)
{
	int		len;
	char	*tmp;

	if (split && split[0] && split[1] && split[2])
	{
		len = check_param(after_white_space(split[0]), 1, &tmp);
		if (!len || *tmp)
			return (0);
		len = check_param(after_white_space(split[1]), 7, &tmp);
		if (!len || *tmp)
			return (0);
		len = check_param(after_white_space(split[2]), 3, &tmp);
		if (len && (*tmp == COMMENT_CHAR
			|| (!*tmp && !split[3])) && nb_letter(line, SEPARATOR_CHAR) == 2)
			return (add_op(split, op, act, get_eighth_ocp(split)));
	}
	return (0);
}

/*
*	16 aff : RG
*/

int		nineth_case(char *line, char **split, int op, t_label *act)
{
	int		len;
	char	*tmp;

	if ((len = check_param(split[0], 1, &tmp)))
	{
		if ((*tmp == COMMENT_CHAR
			|| (!*tmp && !split[1])) && !nb_letter(line, SEPARATOR_CHAR))
			return (add_op(split, op, act, get_nineth_ocp()));
	}
	return (0);
}