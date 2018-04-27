/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 11:30:30 by atourner          #+#    #+#             */
/*   Updated: 2018/04/20 17:13:22 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "asm.h"
#include "op.h"

/*
*	Test de chaque op ,le retour sera si l'element est valide ou non (fonction en cours checkx_x.c)
*/

int		right_follow(char c)
{
	if (c == '%' || ft_iswhitespace(c))
		return (1);
	return (0);

}

int		all_op(char *line)
{
	if (!ft_strncmp(line, OP1, 4) && right_follow(line[4]))
		return (first_case(line, 4));
	if (!ft_strncmp(line, OP2, 2) && right_follow(line[2]))
		return (second_case(line, 2));
	if (!ft_strncmp(line, OP3, 2) && right_follow(line[2]))
		return (third_case(line, 2));
	if (!ft_strncmp(line, OP4, 3) && right_follow(line[3]))
		return (fourth_case(line, 3));
	if (!ft_strncmp(line, OP5, 3) && right_follow(line[3]))
		return (fourth_case(line, 3));
	if (!ft_strncmp(line, OP6, 3) && right_follow(line[3]))
		return (fifth_case(line, 3));
	if (!ft_strncmp(line, OP7, 2) && right_follow(line[2]))
		return (fifth_case(line, 2));
	if (!ft_strncmp(line, OP8, 3) && right_follow(line[3]))
		return (fifth_case(line, 3));
	if (!ft_strncmp(line, OP9, 4) && right_follow(line[4]))
		return (first_case(line, 4));
	if (!ft_strncmp(line, OP10, 3) && right_follow(line[3]))
		return (seventh_case(line, 3));
	if (!ft_strncmp(line, OP11, 3) && right_follow(line[3]))
		return (eighth_case(line, 3));
	if (!ft_strncmp(line, OP12, 4) && right_follow(line[4]))
		return (first_case(line, 4));
	if (!ft_strncmp(line, OP13, 3) && right_follow(line[3]))
		return (second_case(line, 3));
	if (!ft_strncmp(line, OP14, 4) && right_follow(line[4]))
		return (seventh_case(line, 4));
	if (!ft_strncmp(line, OP15, 5) && right_follow(line[5]))
		return (first_case(line, 5));
	if (!ft_strncmp(line, OP16, 3) && right_follow(line[3]))
		return (nineth_case(line, 3));
	return (0);
}

int		valid_opt(char **file, int *line, t_label *act)
{
	int		i;

	if (act->name && !ft_strncmp(file[*line], act->name, (i = (int)ft_strlen(act->name))))
		i = (file[*line][i] == ':' ? i + 1 : 0);
	else
		i = 0;
	while (file[*line][i] && ft_iswhitespace(file[*line][i]))
		i++;
	i = all_op(&file[*line][i]);
	return (i);
}

/*
*	On regarde qu'on ne croise pas un autre label ni une opération non valide
*	On skip les lignes vide ou commentaire	
*/

int		get_act_opt(char **file, int *line, t_label *act)
{
	while (file[*line])
	{
		skip_comment_and_empty_line(file, line);
		if (label_name_valid(file[*line], NULL))
			return (1);
		if (!valid_opt(file, line, act))
			return (-1);
		*line += 1;
		act->size = 1;
	}
	return (0);
}

/*
*	On rajoute les opérations pour le label en cours, jusqu'à ce qu'une opération ne soit pas valide
*	qu'on croise un autre label
*/

int		get_opt(char **file, int *line, t_label *act)
{
	int		ret;

	ret = 0;
	ft_printf("LABEL %s\n", act->name);
	while (file[*line] && !ret)
		ret = get_act_opt(file, line, act);
	return (ret);
}
