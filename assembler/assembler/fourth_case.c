/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fourth_case.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:33:13 by atourner          #+#    #+#             */
/*   Updated: 2018/05/07 17:52:59 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "ft_printf.h"
#include "op.h"

/*
**	04 add et 05 sub OCP : RG, RG, RG
*/

static int		*get_fourth_ocp(void)
{
	int		*ret;

	ret = (int*)ft_memalloc(sizeof(int) * 3);
	ret[2] = 4;
	ft_size_ocp(ret, 1, 6, 3);
	ft_size_ocp(ret, 1, 4, 1);
	ft_size_ocp(ret, 1, 2, 1);
	return (ret);
}

int				ft_case_4(char *line, char **split, int op, t_label *act)
{
	int		len;
	char	*tmp;

	if (split && split[0] && split[1] && split[2])
	{
		len = ft_check_param(ft_skip_space(split[0]), 1, &tmp);
		if (!len || *tmp)
			return (0);
		len = ft_check_param(ft_skip_space(split[1]), 1, &tmp);
		if (!len || *tmp)
			return (0);
		len = ft_check_param(ft_skip_space(split[2]), 1, &tmp);
		if (len && (*tmp == COMMENT_CHAR
			|| (!*tmp && !split[3])) && ft_nb_letter(line, SEPARATOR_CHAR) == 2)
			return (ft_add_op(split, op, act, get_fourth_ocp()));
	}
	return (0);
}
