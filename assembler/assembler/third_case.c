/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 12:28:05 by atourner          #+#    #+#             */
/*   Updated: 2018/05/06 12:28:06 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "ft_printf.h"
#include "op.h"

/*
**	03 st OCP : RG, RG/ID
*/

int		*get_third_ocp(char **split)
{
	char	*tmp;
	int		*ret;

	ret = (int*)ft_memalloc(sizeof(int) * 3);
	ret[2] = 2;
	size_and_ocp(ret, 1, 6, 3);
	tmp = after_white_space(split[1]);
	if (*tmp == 'r')
		size_and_ocp(ret, 1, 4, 1);
	else
		size_and_ocp(ret, 3, 4, 2);
	return (ret);
}

int		third_case(char *line, char **split, int op, t_label *act)
{
	int		len;
	char	*tmp;

	if (split && split[0] && split[1])
	{
		len = check_param(after_white_space(split[0]), 1, &tmp);
		if (!len || *tmp)
			return (0);
		len = check_param(after_white_space(split[1]), 5, &tmp);
		if (len && (*tmp == COMMENT_CHAR
			|| (!*tmp && !split[2])) && nb_letter(line, SEPARATOR_CHAR) == 1)
			return (add_op(split, op, act, get_third_ocp(split)));
	}
	return (0);
}
