#include "asm.h"
#include "ft_printf.h"
#include "op.h"

int		add_op(char **split, int op, t_label *act)
{
	t_op	*act_op;
	int		i;

	i = 0;
	if (!act->op)
	{
		act->op = (t_op*)ft_memalloc(sizeof(t_op));
		act_op = act->op;
	}
	else
	{
		act_op = act->op;
		while (act_op->next)
			act_op = act_op->next;
		act_op->next = (t_op*)ft_memalloc(sizeof(t_op));
		act_op->next->relative_pos = act_op->relative_pos + act_op->size;
		act_op = act_op->next;
	}
	while (split[i])
	{
		act_op->par[i] = split[i];
		i++;
	}
	act_op->op = op;
	act_op->size = 1;
	return (1);
}