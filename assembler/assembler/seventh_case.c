/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seventh_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 12:27:40 by atourner          #+#    #+#             */
/*   Updated: 2018/05/06 13:42:34 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "asm.h"
#include "op.h"

/*
**	11 sti OCP : RG, RG/ID/D2, D2/RG
*/

int		*get_seventh_ocp(char **split)
{
	char	*tmp;
	int		*ret;

	ret = (int*)ft_memalloc(sizeof(int) * 3);
	ret[2] = 2;
	size_and_ocp(ret, 1, 6, 3);
	tmp = after_white_space(split[1]);
	if (*tmp == 'r')
		size_and_ocp(ret, 1, 4, 1);
	else if (*tmp == DIRECT_CHAR)
		size_and_ocp(ret, 2, 4, 2);
	else
		size_and_ocp(ret, 3, 4, 2);
	tmp = after_white_space(split[2]);
	if (*tmp == DIRECT_CHAR)
		size_and_ocp(ret, 2, 2, 2);
	else
		size_and_ocp(ret, 1, 2, 1);
	return (ret);
}

int		seventh_case(char *line, char **split, int op, t_label *act)
{
	int		len;
	char	*tmp;

	if (split && split[0] && split[1] && split[2])
	{
		len = check_param(after_white_space(split[0]), 1, &tmp);
		if (!len || *tmp)
			return (0);
		len = check_param(after_white_space(split[1]), 7, &tmp);
		if (!len || *tmp)
			return (0);
		len = check_param(after_white_space(split[2]), 3, &tmp);
		if (len && (*tmp == COMMENT_CHAR
			|| (!*tmp && !split[3])) && nb_letter(line, SEPARATOR_CHAR) == 2)
			return (add_op(split, op, act, get_seventh_ocp(split)));
	}
	return (0);
}
