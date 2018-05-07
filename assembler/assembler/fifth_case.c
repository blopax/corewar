/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fifth_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 17:40:37 by atourner          #+#    #+#             */
/*   Updated: 2018/05/07 17:52:20 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "ft_printf.h"
#include "op.h"

/*
** 06 and et 07 or et 08 xor OCP : RG/ID/D4, RG/ID/D4, RG
*/

static int		*get_fifth_ocp(char **split)
{
	char	*tmp;
	int		*ret;

	ret = (int*)ft_memalloc(sizeof(int) * 3);
	tmp = ft_skip_space(split[0]);
	ret[2] = 4;
	if (*tmp == 'r')
		ft_size_ocp(ret, 1, 6, 3);
	else if (*tmp == DIRECT_CHAR)
		ft_size_ocp(ret, 2, 6, 6);
	else
		ft_size_ocp(ret, 3, 6, 4);
	tmp = ft_skip_space(split[1]);
	if (*tmp == 'r')
		ft_size_ocp(ret, 1, 4, 1);
	else if (*tmp == DIRECT_CHAR)
		ft_size_ocp(ret, 2, 4, 4);
	else
		ft_size_ocp(ret, 3, 4, 2);
	ft_size_ocp(ret, 1, 2, 1);
	return (ret);
}

int				ft_case_5(char *line, char **split, int op, t_label *act)
{
	int		len;
	char	*tmp;

	if (split && split[0] && split[1] && split[2])
	{
		len = ft_check_param(ft_skip_space(split[0]), 7, &tmp);
		if (!len || *tmp)
			return (0);
		len = ft_check_param(ft_skip_space(split[1]), 7, &tmp);
		if (!len || *tmp)
			return (0);
		len = ft_check_param(ft_skip_space(split[2]), 1, &tmp);
		if (len && (*tmp == COMMENT_CHAR
			|| (!*tmp && !split[3])) && ft_nb_letter(line, SEPARATOR_CHAR) == 2)
			return (ft_add_op(split, op, act, get_fifth_ocp(split)));
	}
	return (0);
}
