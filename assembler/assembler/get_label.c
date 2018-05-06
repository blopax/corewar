/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 10:40:02 by atourner          #+#    #+#             */
/*   Updated: 2018/05/06 13:27:51 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "asm.h"
#include "op.h"

t_label		*search_last(t_label *first)
{
	t_label		*last;

	last = first;
	while (last->next != NULL)
		last = last->next;
	last->next = (t_label*)ft_memalloc(sizeof(t_label));
	last->next->relative_pos = last->relative_pos + last->size;
	return (last->next);
}

int			get_current_label(char **file, int *line, t_label **first)
{
	t_label		*act;

	if (!file[*line])
		return (0);
	if (!*first)
	{
		act = (t_label*)ft_memalloc(sizeof(t_label));
		*first = act;
	}
	else
		act = search_last(*first);
	if (!act || (!label_name_valid(file[*line], &act->name) && (*first)->next))
	{
		ft_printf("Error line %d file %s\n", *line, file[*line]);
		return (-1);
	}
	else
	{
		if (get_opt(file, line, act) >= 0)
			return (1);
		return (0);
	}
}

t_label		*get_label(char **file, int line)
{
	t_label		*first;

	first = NULL;
	if (!file)
		return (NULL);
	while (file[line])
	{
		skip_comment_and_empty_line(file, &line);
		if (!file[line])
			break ;
		if (get_current_label(file, &line, &first) < 0)
			return (NULL);
	}
	return (first);
}
