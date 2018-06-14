/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:32:46 by atourner          #+#    #+#             */
/*   Updated: 2018/06/11 15:45:36 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "ft_printf.h"
#include "op.h"

/*
**	01 live : D4
**	09 zjmp : D2
**	12 fork : ID
**	15 lfork : ID
*/

static int		*get_first_ocp(int op, char **split)
{
	int		*ret;
	char	*tmp;

	ret = (int*)ft_memalloc(sizeof(int) * 3);
	ret[2] = 4;
	tmp = ft_skip_space(split[0]);
	if (op == 1)
		ft_size_ocp(ret, 2, 6, 5);
	else if (op == 9)
	{
		ft_size_ocp(ret, 2, 6, 3);
		ret[2] = 2;
	}
	else
	{
		if (*tmp == '%')
			ft_size_ocp(ret, 2, 6, 3);
		else
			ft_size_ocp(ret, 3, 6, 3);
		ret[2] = 2;
	}
	return (ret);
}

int				ft_case_1(char *line, char **split, int op, t_label *act)
{
	int		len;
	char	*tmp;

	if (op == 1 || op == 9)
	{
		if ((len = ft_check_param(split[0], 2, &tmp)))
			if ((*tmp == COMMENT_CHAR
			|| (!*tmp && !split[1])) && !ft_nb_letter(line, SEPARATOR_CHAR))
				return (ft_add_op(split, op, act, get_first_ocp(op, split)));
	}
	else
	{
		if ((len = ft_check_param(split[0], 6, &tmp)))
			if ((*tmp == COMMENT_CHAR
			|| (!*tmp && !split[1])) && !ft_nb_letter(line, SEPARATOR_CHAR))
				return (ft_add_op(split, op, act, get_first_ocp(op, split)));
	}
	return (0);
}
