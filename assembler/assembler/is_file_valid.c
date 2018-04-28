/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 20:06:03 by atourner          #+#    #+#             */
/*   Updated: 2018/04/18 14:47:17 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "asm.h"
#include "op.h"

/*
*	validation du fichier si c'est bon, creation du champion
*/

int			*create_champion(char **name, t_label *first)
{
	if (first && name)
		return (NULL);
	return (NULL);
}

int			*is_file_valid(char **file)
{
	char		**name;
	int			*ret;
	t_label		*first;
	int			last_line;

	ret = NULL;
	first = NULL;
	name = check_name_and_comment(file, &last_line);
	if (name)
		first = get_label(file, last_line);
	for (t_label *act = first; act; act = act->next)
	{
		ft_printf("%s Size [%d]\n", act->name, act->size);
		for (t_op *op = act->op; op; op = op->next)
		{
			ft_printf("		Op [%d] Position relative [%d] ocp [%d]\n", op->op, op->relative_pos, op->ocp);
			for (int i = 0; op->par[i]; i++)
				ft_printf("			%s\n", op->par[i]);
		}
	}
	ret = create_champion(name, first);
	return (ret);
}
