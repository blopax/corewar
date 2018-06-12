/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eighth_case.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:32:24 by atourner          #+#    #+#             */
/*   Updated: 2018/06/12 16:39:33 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "ft_printf.h"
#include "op.h"

/*
**	16 aff : RG
*/

static int		*get_eighth_ocp(void)
{
	int		*ret;

	ret = (int*)ft_memalloc(sizeof(int) * 3);
	ret[2] = 4;
	ft_size_ocp(ret, 1, 6, 3);
	return (ret);
}

int				ft_case_8(char *line, char **split, int op, t_label *act)
{
	int		len;
	char	*tmp;

	if ((len = ft_check_param(split[0], 1, &tmp)))
	{
		if ((*tmp == COMMENT_CHAR
			|| (!*tmp && !split[1])) && !ft_nb_letter(line, SEPARATOR_CHAR))
			return (ft_add_op(split, op, act, get_eighth_ocp()));
	}
	return (0);
}
