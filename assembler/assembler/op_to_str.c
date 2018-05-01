#include "ft_printf.h"
#include "asm.h"
#include "op.h"

int				search_label(t_label *first, t_op *op, char *tmp, int *num)
{
	t_label		*act;
	int			ret;

	act = first;
	ret = 1;
	while (act && strcmp(act->name, &tmp[1]))
		act = act->next;
	if (!act)
		return (0);
	*num = act->relative_pos - op->relative_pos;
	return (1);
}

void				add_reg(unsigned char *ret, int *i, t_op *op)
{
	char	*tmp;

	tmp = after_white_space(op->par[op->act]);
	tmp++;
	ret[*i += 1] = ft_atoi(tmp);
}

int				add_dir(unsigned char *ret, int *i, t_op *op, t_label *first)
{
	char	*tmp;
	int		num;

	tmp = after_white_space(op->par[op->act]);
	tmp++;
	if (*tmp != ':')
		num = ft_atoi(tmp);
	else
		if (!(search_label(first, op, tmp, &num)))
			return (0);
	if (op->dir_size == 2)
	{
		ret[*i += 1] = ((num >> 8) & 0xFF);
		ret[*i += 1] = ((num) & 0xFF);
	}
	if (op->dir_size == 4)
	{
		ret[*i += 1] = ((num >> 24) & 0xFF);
		ret[*i += 1] = ((num >> 16) & 0xFF);
		ret[*i += 1] = ((num >> 8) & 0xFF);
		ret[*i += 1] = ((num) & 0xFF);
	}
	return (1);
}

void				add_id(unsigned char *ret, int *i, t_op *op)
{
	char	*tmp;
	int		num;

	tmp = after_white_space(op->par[op->act]);
	num = ft_atoi(tmp);
	ret[*i += 1] = ((num >> 8) & 0xFF);
	ret[*i += 1] = ((num) & 0xFF);
}

int				add_op_str(unsigned char *ret, t_label *first, int *i)
{
	t_label		*act;
	t_op		*act_op;

	*i = PROG_NAME_LENGTH + COMMENT_LENGTH + 15;
	act = first;
	while (act)
	{
		act_op = act->op;
		while (act_op)
		{
			if (!(add_act_op(ret, act_op,first, i)))
				return (0);
			act_op = act_op->next;
		}
		act = act->next;
	}
	return (1);
}