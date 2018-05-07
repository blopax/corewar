/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:32:07 by atourner          #+#    #+#             */
/*   Updated: 2018/05/07 18:15:05 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "ft_printf.h"
#include "op.h"

static t_op		*add_last(t_label *act)
{
	t_op	*act_op;

	if (!act->op)
	{
		if (!(act->op = (t_op*)ft_memalloc(sizeof(t_op))))
			return (NULL);
		act_op = act->op;
		act_op->relative_pos = act->relative_pos;
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

int				ft_add_op(char **split, int op, t_label *act, int *ocp)
{
	t_op	*act_op;
	int		i;
	int		bitwise;

	i = 0;
	bitwise = 6;
	if (!(act_op = add_last(act)))
		return (ft_free_and_ret(split, ocp, 0));
	act_op->ocp = ocp[0];
	act_op->size = ocp[1];
	act_op->dir_size = ocp[2];
	while (bitwise && ((ocp[0] >> bitwise) & 3))
	{
		if (!(act_op->par[i] = ft_strdup(split[i])))
			return (ft_free_and_ret(split, ocp, 0));
		i++;
		bitwise -= 2;
	}
	act_op->par[i] = NULL;
	act_op->op = op;
	act->size += act_op->size;
	return (ft_free_and_ret(split, ocp, 1));
}
