/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 12:07:33 by atourner          #+#    #+#             */
/*   Updated: 2018/05/06 12:07:42 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "asm.h"
#include "op.h"

int		ft_free_and_ret(char **ar_str, int *tab, int ret)
{
	ft_free_ar((void**)ar_str);
	free(tab);
	return (ret);
}

int		ft_free_chain(t_label *first, int ret)
{
	t_label *next;
	t_label	*act;
	t_op	*act_op;
	t_op	*next_op;
	int		i;

	act = first;
	while (act)
	{
		act_op = act->op;
		while (act_op)
		{
			i = -1;
			while (act_op->par[++i])
				free(act_op->par[i]);
			next_op = act_op->next;
			free(act_op);
			act_op = next_op;
		}
		next = act->next;
		free(act->name);
		free(act);
		act = next;
	}
	return (ret);
}
