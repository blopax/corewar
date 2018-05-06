/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 11:30:30 by atourner          #+#    #+#             */
/*   Updated: 2018/05/06 13:38:31 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "asm.h"
#include "op.h"

/*
**	Test de chaque op ,le retour sera si l'element
**	est valide ou non (fonction en cours checkx_x.c)
*/

int		right_follow(char c)
{
	if (c == '%' || ft_iswhitespace(c))
		return (1);
	return (0);
}

int		continu_op(char *line, t_label *act)
{
	if (!ft_strncmp(line, OP8, 3) && right_follow(line[3]))
		return (fifth_case(line, split_arg(&line[3]), 8, act));
	if (!ft_strncmp(line, OP9, 4) && right_follow(line[4]))
		return (first_case(line, split_arg(&line[4]), 9, act));
	if (!ft_strncmp(line, OP10, 3) && right_follow(line[3]))
		return (sixth_case(line, split_arg(&line[3]), 10, act));
	if (!ft_strncmp(line, OP11, 3) && right_follow(line[3]))
		return (seventh_case(line, split_arg(&line[3]), 11, act));
	if (!ft_strncmp(line, OP12, 4) && right_follow(line[4]))
		return (first_case(line, split_arg(&line[4]), 12, act));
	if (!ft_strncmp(line, OP13, 3) && right_follow(line[3]))
		return (second_case(line, split_arg(&line[3]), 13, act));
	if (!ft_strncmp(line, OP14, 4) && right_follow(line[4]))
		return (sixth_case(line, split_arg(&line[4]), 14, act));
	if (!ft_strncmp(line, OP15, 5) && right_follow(line[5]))
		return (first_case(line, split_arg(&line[5]), 15, act));
	if (!ft_strncmp(line, OP16, 3) && right_follow(line[3]))
		return (eighth_case(line, split_arg(&line[3]), 16, act));
	return (0);
}

int		all_op(char *line, t_label *act)
{
	if (!ft_strncmp(line, OP1, 4) && right_follow(line[4]))
		return (first_case(line, split_arg(&line[4]), 1, act));
	if (!ft_strncmp(line, OP2, 2) && right_follow(line[2]))
		return (second_case(line, split_arg(&line[2]), 2, act));
	if (!ft_strncmp(line, OP3, 2) && right_follow(line[2]))
		return (third_case(line, split_arg(&line[2]), 3, act));
	if (!ft_strncmp(line, OP4, 3) && right_follow(line[3]))
		return (fourth_case(line, split_arg(&line[3]), 4, act));
	if (!ft_strncmp(line, OP5, 3) && right_follow(line[3]))
		return (fourth_case(line, split_arg(&line[3]), 5, act));
	if (!ft_strncmp(line, OP6, 3) && right_follow(line[3]))
		return (fifth_case(line, split_arg(&line[3]), 6, act));
	if (!ft_strncmp(line, OP7, 2) && right_follow(line[2]))
		return (fifth_case(line, split_arg(&line[2]), 7, act));
	return (continu_op(line, act));
}

/*
**	On regarde qu'on ne croise pas un autre label ni une opération non valide
**	On skip les lignes vide ou commentaire
*/

int		get_act_opt(char **file, int *line, t_label *act)
{
	while (file[*line])
	{
		skip_comment_and_empty_line(file, line);
		if (!file[*line])
			return (0);
		if (label_name_valid(file[*line], NULL))
			return (1);
		if (!all_op(after_white_space(file[*line]), act))
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

int		get_opt(char **file, int *line, t_label *act)
{
	int		ret;

	ret = 0;
	while (file[*line] && !ret)
		ret = get_act_opt(file, line, act);
	return (ret);
}
