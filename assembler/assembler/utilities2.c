/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 12:35:22 by atourner          #+#    #+#             */
/*   Updated: 2018/05/07 17:41:05 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "ft_printf.h"
#include "op.h"

void			ft_size_ocp(int *ret, int type, int bitwise, int size)
{
	ret[0] += type << bitwise;
	ret[1] += size;
}

int				ft_add_all_op_size(t_label *first)
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

char			**ft_split_arg(char *str)
{
	return (ft_strsplit(ft_skip_space(str), SEPARATOR_CHAR));
}

int				ft_check_param(char *str, int test, char **ret)
{
	int		len;
	char	*tmp;

	if ((test & 1) && (len = ft_is_rg(str)))
	{
		tmp = ft_skip_space(&str[len]);
		if (len && (!*tmp || *tmp == COMMENT_CHAR) && (*ret = tmp))
			return (len);
	}
	if ((test & 2))
	{
		len = ft_is_d2(str);
		if (!len)
			len = ft_is_d4(str);
		tmp = ft_skip_space(&str[len]);
		if (len && (!*tmp || *tmp == COMMENT_CHAR) && (*ret = tmp))
			return (len);
	}
	if ((test & 4) && (len = ft_is_id(str)))
	{
		tmp = ft_skip_space(&str[len]);
		if (len && (!*tmp || *tmp == COMMENT_CHAR) && (*ret = tmp))
			return (len);
	}
	return (0);
}

int				ft_add_act_op(unsigned char *ret, t_op *op,
		t_label *first, int *i)
{
	int		bitwise;
	int		param;

	param = 0;
	bitwise = 6;
	if (first)
		ret[*i += 1] = op->op;
	if (op->op != 1 && op->op != 9 && op->op != 12
			&& op->op != 15 && op->op != 16)
		ret[*i += 1] = op->ocp;
	while (bitwise)
	{
		op->act = param;
		if (((op->ocp >> bitwise) & 3) == 1)
			ft_add_reg(ret, i, op);
		if (((op->ocp >> bitwise) & 3) == 2)
			if (!(ft_add_dir(ret, i, op, first)))
				return (0);
		if (((op->ocp >> bitwise) & 3) == 3)
			if (!(ft_add_id(ret, i, op, first)))
				return (0);
		bitwise -= 2;
		param += 1;
	}
	return (1);
}
