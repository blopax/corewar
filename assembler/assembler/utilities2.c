#include "asm.h"
#include "ft_printf.h"
#include "op.h"

void	size_and_ocp(int *ret, int type, int bitwise, int size)
{
	ret[0] += type << bitwise;
	ret[1] += size;
}

int			add_all_op_size(t_label *first)
{
	int		ret;
	t_label	*act;

	ret = 0;
	act = first;
	while (act)
	{
		ret += act->size;
		act = act->next;
	}
	return (ret);
}

char	**split_arg(char *str)
{
	return (ft_strsplit(after_white_space(str), SEPARATOR_CHAR));
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

int				add_act_op(unsigned char *ret, t_op *op ,t_label *first, int *i)
{
	int		bitwise;
	int		param;

	param = 0;
	bitwise = 6;
	if (first)
	ret[*i += 1] = op->op;
	if (op->op != 1 && op->op != 9 && op->op != 12 && op->op != 15 && op->op != 16)
		ret[*i += 1] = op->ocp;
	while (bitwise)
	{
		op->act = param;
		if (((op->ocp >> bitwise) & 3) == 1)
			add_reg(ret, i, op);
		if (((op->ocp >> bitwise) & 3) == 2)
			if (!(add_dir(ret, i, op, first)))
				return (0);
		if (((op->ocp >> bitwise) & 3) == 3)
			add_id(ret, i, op);
		bitwise -= 2;
		param += 1;
	}
	return (1);
}