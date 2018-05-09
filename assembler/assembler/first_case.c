/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:32:46 by atourner          #+#    #+#             */
/*   Updated: 2018/05/07 17:52:37 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "ft_printf.h"
#include "op.h"

/*
**	01 live : D4
**	09 zjmp : D2
**	12 fork : D2
**	15 lfork : D2
*/

static int		*get_first_ocp(int op)
{
	int		*ret;

	ret = (int*)ft_memalloc(sizeof(int) * 3);
	ret[2] = 4;
	if (op == 1)
		ft_size_ocp(ret, 2, 6, 5);
	else
	{
		ft_size_ocp(ret, 2, 6, 3);
		ret[2] = 2;
	}
	return (ret);
}

int				ft_case_1(char *line, char **split, int op, t_label *act)
{
	int		len;
	char	*tmp;

	if ((len = ft_check_param(split[0], 2, &tmp)))
		if ((*tmp == COMMENT_CHAR
			|| (!*tmp && !split[1])) && !ft_nb_letter(line, SEPARATOR_CHAR))
			return (ft_add_op(split, op, act, get_first_ocp(op)));
	return (0);
}
