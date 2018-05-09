/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:35:36 by atourner          #+#    #+#             */
/*   Updated: 2018/05/07 17:58:20 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "ft_printf.h"
#include "op.h"

/*
**	03 st OCP : RG, RG/ID
*/

static int		*get_third_ocp(char **split)
{
	char	*tmp;
	int		*ret;

	ret = (int*)ft_memalloc(sizeof(int) * 3);
	ret[2] = 2;
	ft_size_ocp(ret, 1, 6, 3);
	tmp = ft_skip_space(split[1]);
	if (*tmp == 'r')
		ft_size_ocp(ret, 1, 4, 1);
	else
		ft_size_ocp(ret, 3, 4, 2);
	return (ret);
}

int				ft_case_3(char *line, char **split, int op, t_label *act)
{
	int		len;
	char	*tmp;

	if (split && split[0] && split[1])
	{
		len = ft_check_param(ft_skip_space(split[0]), 1, &tmp);
		if (!len || *tmp)
			return (0);
		len = ft_check_param(ft_skip_space(split[1]), 5, &tmp);
		if (len && (*tmp == COMMENT_CHAR
			|| (!*tmp && !split[2])) && ft_nb_letter(line, SEPARATOR_CHAR) == 1)
			return (ft_add_op(split, op, act, get_third_ocp(split)));
	}
	return (0);
}
