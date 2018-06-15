/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:34:22 by atourner          #+#    #+#             */
/*   Updated: 2018/06/14 11:05:59 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "asm.h"
#include "op.h"

char	*g_allop[16] = {"live\0", "ld\0", "st\0", "add\0", "sub\0",
	"and\0", "or\0", "xor\0", "zjmp\0", "ldi\0",
	"sti\0", "fork\0", "lld\0", "lldi\0", "lfork\0", "aff\0"};

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

static int		choose_op(int op, t_label *act, char *line, int len)
{
	if (op == 1 || op == 9 || op == 12 || op == 15)
		return (ft_case_1(line, ft_split_arg(&line[len]), op, act));
	if (op == 2 || op == 13)
		return (ft_case_2(line, ft_split_arg(&line[len]), op, act));
	if (op == 3)
		return (ft_case_3(line, ft_split_arg(&line[len]), op, act));
	if (op == 4 || op == 5)
		return (ft_case_4(line, ft_split_arg(&line[len]), op, act));
	if (op == 6 || op == 7 || op == 8)
		return (ft_case_5(line, ft_split_arg(&line[len]), op, act));
	if (op == 10)
		return (ft_case_6(line, ft_split_arg(&line[len]), op, act));
	if (op == 11)
		return (ft_case_7(line, ft_split_arg(&line[len]), op, act));
	if (op == 16)
		return (ft_case_8(line, ft_split_arg(&line[len]), op, act));
	return (0);
}

static int		all_op(char *line, t_label *act)
{
	int		op;

	op = 0;
	while (op < 16)
		if (!ft_strncmp(line, g_allop[op], (int)ft_strlen(g_allop[op]))
			&& right_follow(line[ft_strlen(g_allop[op])]))
			break ;
		else
			op++;
	if (op < 16 && right_follow(line[ft_strlen(g_allop[op])]))
		return (choose_op(op + 1, act, line, (int)ft_strlen(g_allop[op])));
	return (0);
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
