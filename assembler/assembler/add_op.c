#include "asm.h"
#include "ft_printf.h"
#include "op.h"

t_op	*add_last(t_label *act)
{
	t_op	*act_op;

	if (!act->op)
	{
		if (!(act->op = (t_op*)ft_memalloc(sizeof(t_op))))
			return (NULL);
		act_op = act->op;
	}
	else
	{
		act_op = act->op;
		while (act_op->next)
			act_op = act_op->next;
		if (!(act_op->next = (t_op*)ft_memalloc(sizeof(t_op))))
			return (NULL);
		act_op->next->relative_pos = act_op->relative_pos + act_op->size;
		act_op = act_op->next;
	}
	return (act_op);
}

int		add_op(char **split, int op, t_label *act, int *ocp)
{
	t_op	*act_op;
	int		i;

	i = 0;
	if (!(act_op = add_last(act)))
		return (0);
	act_op->ocp = ocp[0];
	act_op->size = ocp[1];
	act_op->dir_size = ocp[2];
	while (split[i])
	{
		act_op->par[i] = split[i];
		i++;
	}
	act_op->par[i] = NULL;
	act_op->op = op;
	act->size += act_op->size;
	return (1);
}