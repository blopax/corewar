/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:34:22 by atourner          #+#    #+#             */
/*   Updated: 2018/05/07 17:54:19 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "asm.h"
#include "op.h"

/*
**	Test de chaque op ,le retour sera si l'element
**	est valide ou non (fonction en cours checkx_x.c)
*/

static int		right_follow(char c)
{
	if (c == '%' || ft_iswhitespace(c))
		return (1);
	return (0);
}

static int		continu_op(char *line, t_label *act)
{
	if (!ft_strncmp(line, OP8, 3) && right_follow(line[3]))
		return (ft_case_5(line, ft_split_arg(&line[3]), 8, act));
	if (!ft_strncmp(line, OP9, 4) && right_follow(line[4]))
		return (ft_case_1(line, ft_split_arg(&line[4]), 9, act));
	if (!ft_strncmp(line, OP10, 3) && right_follow(line[3]))
		return (ft_case_6(line, ft_split_arg(&line[3]), 10, act));
	if (!ft_strncmp(line, OP11, 3) && right_follow(line[3]))
		return (ft_case_7(line, ft_split_arg(&line[3]), 11, act));
	if (!ft_strncmp(line, OP12, 4) && right_follow(line[4]))
		return (ft_case_1(line, ft_split_arg(&line[4]), 12, act));
	if (!ft_strncmp(line, OP13, 3) && right_follow(line[3]))
		return (ft_case_2(line, ft_split_arg(&line[3]), 13, act));
	if (!ft_strncmp(line, OP14, 4) && right_follow(line[4]))
		return (ft_case_6(line, ft_split_arg(&line[4]), 14, act));
	if (!ft_strncmp(line, OP15, 5) && right_follow(line[5]))
		return (ft_case_1(line, ft_split_arg(&line[5]), 15, act));
	if (!ft_strncmp(line, OP16, 3) && right_follow(line[3]))
		return (ft_case_8(line, ft_split_arg(&line[3]), 16, act));
	return (0);
}

static int		all_op(char *line, t_label *act)
{
	if (!ft_strncmp(line, OP1, 4) && right_follow(line[4]))
		return (ft_case_1(line, ft_split_arg(&line[4]), 1, act));
	if (!ft_strncmp(line, OP2, 2) && right_follow(line[2]))
		return (ft_case_2(line, ft_split_arg(&line[2]), 2, act));
	if (!ft_strncmp(line, OP3, 2) && right_follow(line[2]))
		return (ft_case_3(line, ft_split_arg(&line[2]), 3, act));
	if (!ft_strncmp(line, OP4, 3) && right_follow(line[3]))
		return (ft_case_4(line, ft_split_arg(&line[3]), 4, act));
	if (!ft_strncmp(line, OP5, 3) && right_follow(line[3]))
		return (ft_case_4(line, ft_split_arg(&line[3]), 5, act));
	if (!ft_strncmp(line, OP6, 3) && right_follow(line[3]))
		return (ft_case_5(line, ft_split_arg(&line[3]), 6, act));
	if (!ft_strncmp(line, OP7, 2) && right_follow(line[2]))
		return (ft_case_5(line, ft_split_arg(&line[2]), 7, act));
	return (continu_op(line, act));
}

/*
**	On regarde qu'on ne croise pas un autre label ni une opération non valide
**	On skip les lignes vide ou commentaire
*/

static int		get_act_opt(char **file, int *line, t_label *act)
{
	while (file[*line])
	{
		ft_skip_empty(file, line);
		if (!file[*line])
			return (0);
		if (ft_val_lab(file[*line], NULL))
			return (1);
		if (!all_op(ft_skip_space(file[*line]), act))
			return (-1);
		if (file[*line])
			*line += 1;
	}
	return (0);
}

/*
**	On rajoute les opérations pour le label en cours,
**	jusqu'à ce qu'une opération ne soit pas valide
**	qu'on croise un autre label
*/

int				ft_get_opt(char **file, int *line, t_label *act)
{
	int		ret;

	ret = 0;
	while (file[*line] && !ret)
		ret = get_act_opt(file, line, act);
	return (ret);
}
