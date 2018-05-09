/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_to_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 12:17:03 by atourner          #+#    #+#             */
/*   Updated: 2018/05/07 17:56:45 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "asm.h"
#include "op.h"

static int		search_label(t_label *first, t_op *op, char *tmp, int *num)
{
	t_label		*act;
	int			ret;
	size_t		len;

	act = first;
	ret = 1;
	while (act)
	{
		if (!ft_strncmp(act->name, &tmp[1], (len = ft_strlen(act->name)))
		&& (!tmp[len + 1] || ft_iswhitespace(tmp[len + 1])))
			break ;
		act = act->next;
	}
	if (!act)
	{
		ft_printf("Label %s doesn't exist\n", &tmp[1]);
		return (0);
	}
	*num = act->relative_pos - op->relative_pos;
	return (1);
}

void			ft_add_reg(unsigned char *ret, int *i, t_op *op)
{
	char	*tmp;

	tmp = ft_skip_space(op->par[op->act]);
	tmp++;
	ret[*i += 1] = ft_atoi(tmp);
}

int				ft_add_dir(unsigned char *ret, int *i, t_op *op, t_label *first)
{
	char	*tmp;
	int		num;

	tmp = ft_skip_space(op->par[op->act]);
	tmp++;
	if (*tmp != ':')
		num = ft_atoi(tmp);
	else if (!(search_label(first, op, tmp, &num)))
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

int				ft_add_id(unsigned char *ret, int *i, t_op *op, t_label *first)
{
	char	*tmp;
	int		num;

	tmp = ft_skip_space(op->par[op->act]);
	if (*tmp != ':')
		num = ft_atoi(tmp);
	else if (!(search_label(first, op, tmp, &num)))
		return (0);
	ret[*i += 1] = ((num >> 8) & 0xFF);
	ret[*i += 1] = ((num) & 0xFF);
	return (1);
}

int				ft_ft_add_op_str(unsigned char *ret, t_label *first, int *i)
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
			if (!(ft_add_act_op(ret, act_op, first, i)))
				return (0);
			act_op = act_op->next;
		}
		act = act->next;
	}
	return (1);
}
