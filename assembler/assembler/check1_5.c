#include "asm.h"
#include "ft_printf.h"
#include "op.h"


int		nb_letter(char *line, char c)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (line[i] && line[i] != COMMENT_CHAR)
		if (line[i] == c)
		{
			nb++;
			i++;
		}
		else
			i++;
	return (nb);
}

char	*after_white_space(char *str)
{
	while (ft_iswhitespace(*str))
		str++;
	return (str);
}

int		check_param(char *str, int test, char **ret)
{
	int		len;
	char	*tmp;

	if ((test & 1) && (len = is_rg(str)))
	{
		tmp = after_white_space(&str[len]);
			if (len && (!*tmp || *tmp == COMMENT_CHAR) && (*ret = tmp))
				return (len);
	}
	if ((test & 2))
	{
		len = is_d2(str);
		if (!len)
			len = is_d4(str);
		tmp = after_white_space(&str[len]);
		if (len && (!*tmp || *tmp == COMMENT_CHAR) && (*ret = tmp))
			return (len);
	}
	if ((test & 4) && (len = is_id(str)))
	{
		tmp = after_white_space(&str[len]);
		if (len && (!*tmp || *tmp == COMMENT_CHAR) && (*ret = tmp))
			return (len);
	}
	return (0);
}

/*
*	01 live : D4
*	09 zjmp : D2
*	12 fork : D2
*	15 lfork : D2
*/

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

/*
*	02 ld		OCP : ID/D4, RG
*	13 lld		OCP : ID/D4, RG
*/

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

/*
*	03 st OCP : RG, RG/ID
*/

int		third_case(char *line, char **split, int op, t_label *act)
{
	int		len;
	char	*tmp;

	if (split && split[0] && split[1])
	{
		len = check_param(after_white_space(split[0]), 1, &tmp);
		if (!len || *tmp)
			return (0);
		len = check_param(after_white_space(split[1]), 5, &tmp);
		if (len && (*tmp == COMMENT_CHAR
			|| (!*tmp && !split[2])) && nb_letter(line, SEPARATOR_CHAR) == 1)
			return (add_op(split, op, act, get_third_ocp(split)));
	}
	return (0);
}

/*
*	04 add et 05 sub OCP : RG, RG, RG
*/

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

/*
* 06 and et 07 or et 08 xor OCP : RG/ID/D4, RG/ID/D4, RG
*/

int		fifth_case(char *line, char **split, int op, t_label *act)
{
	int		len;
	char	*tmp;

	if (split && split[0] && split[1] && split[2])
	{
		len = check_param(after_white_space(split[0]), 7, &tmp);
		if (!len || *tmp)
			return (0);
		len = check_param(after_white_space(split[1]), 7, &tmp);
		if (!len || *tmp)
			return (0);
		len = check_param(after_white_space(split[2]), 1, &tmp);
		if (len && (*tmp == COMMENT_CHAR
			|| (!*tmp && !split[3])) && nb_letter(line, SEPARATOR_CHAR) == 2)
			return (add_op(split, op, act, get_fifth_ocp(split)));
	}
	return (0);
}