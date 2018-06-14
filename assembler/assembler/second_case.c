/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_case.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:35:04 by atourner          #+#    #+#             */
/*   Updated: 2018/05/07 17:57:30 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "ft_printf.h"
#include "op.h"

/*
**	02 ld		OCP : ID/D4, RG
**	13 lld		OCP : ID/D4, RG
*/

static int		*get_second_ocp(char **split, int op)
{
	char	*tmp;
	int		*ret;

	op = 0;
	ret = (int*)ft_memalloc(sizeof(int) * 3);
	tmp = ft_skip_space(split[0]);
	ret[2] = 4;
	if (*tmp == DIRECT_CHAR)
		ft_size_ocp(ret, 2, 6, 6);
	else
		ft_size_ocp(ret, 3, 6, 4);
	ft_size_ocp(ret, 1, 4, 1);
	return (ret);
}

int				ft_case_2(char *line, char **split, int op, t_label *act)
{
	int		len;
	char	*tmp;

	if (split && split[0] && split[1])
	{
		len = ft_check_param(ft_skip_space(split[0]), 6, &tmp);
		if (!len || *tmp)
			return (0);
		len = ft_check_param(ft_skip_space(split[1]), 1, &tmp);
		if (len && (*tmp == COMMENT_CHAR
			|| (!*tmp && !split[2])) && ft_nb_letter(line, SEPARATOR_CHAR) == 1)
			return (ft_add_op(split, op, act, get_second_ocp(split, op)));
	}
	return (0);
}
