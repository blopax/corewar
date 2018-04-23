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

int		all_op(char *line)
{
	if (!ft_strncmp(line, OP1, 4) && line[4] != ':' && ft_iswhitespace(line[4]))
		return (1);
	if (!ft_strncmp(line, OP2, 2) && line[2] != ':'  && ft_iswhitespace(line[2]))
		return (2);
	if (!ft_strncmp(line, OP3, 2) && line[2] != ':' && ft_iswhitespace(line[2]))
		return (3);
	if (!ft_strncmp(line, OP4, 3) && line[3] != ':' && ft_iswhitespace(line[3]))
		return (4);
	if (!ft_strncmp(line, OP5, 3) && line[3] != ':' && ft_iswhitespace(line[3]))
		return (5);
	if (!ft_strncmp(line, OP6, 3) && line[3] != ':' && ft_iswhitespace(line[3]))
		return (6);
	if (!ft_strncmp(line, OP7, 2) && line[2] != ':' && ft_iswhitespace(line[2]))
		return (7);
	if (!ft_strncmp(line, OP8, 3) && line[3] != ':' && ft_iswhitespace(line[3]))
		return (8);
	if (!ft_strncmp(line, OP9, 4) && line[4] != ':' && ft_iswhitespace(line[4]))
		return (9);
	if (!ft_strncmp(line, OP10, 3) && line[3] != ':' && ft_iswhitespace(line[3]))
		return (10);
	if (!ft_strncmp(line, OP11, 3) && line[3] != ':' && ft_iswhitespace(line[3]))
		return (11);
	if (!ft_strncmp(line, OP12, 4) && line[4] != ':' && ft_iswhitespace(line[4]))
		return (12);;
	if (!ft_strncmp(line, OP13, 3) && line[3] != ':' && ft_iswhitespace(line[3]))
		return (13);
	if (!ft_strncmp(line, OP14, 4) && line[4] != ':' && ft_iswhitespace(line[4]))
		return (14);
	if (!ft_strncmp(line, OP15, 5) && line[5] != ':' && ft_iswhitespace(line[5]))
		return (15);
	if (!ft_strncmp(line, OP16, 3) && line[3] != ':' && ft_iswhitespace(line[5]))
		return (16);
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

int		get_opt(char **file, int *line, t_label *act)
{
	int		ret;

	ret = 0;
	ft_printf("LABEL %s\n", act->name);
	while (file[*line] && !ret)
		ret = get_act_opt(file, line, act);
	ft_printf("%d %d\n", *line, ret);
	return (ret);
}
