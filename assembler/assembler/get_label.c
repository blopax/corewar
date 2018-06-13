/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:33:52 by atourner          #+#    #+#             */
/*   Updated: 2018/06/12 19:29:27 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "asm.h"
#include "op.h"

static t_label		*search_last(t_label *first)
{
	t_label		*last;

	last = first;
	while (last->next != NULL)
		last = last->next;
	last->next = (t_label*)ft_memalloc(sizeof(t_label));
	last->next->relative_pos = last->relative_pos + last->size;
	return (last->next);
}

static int			get_current_label(char **file, int *line, t_label **first)
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
	if (!act || (!ft_val_lab(file[*line], &act->name) && (*first)->next))
	{
		ft_printf("Error line %d file %s\n", *line, file[*line]);
		return (-1);
	}
	else
	{
		if (ft_get_opt(file, line, act) >= 0)
			return (1);
		return (0);
	}
}

t_label				*ft_get_label(char **file, int line)
{
	t_label		*first;

	first = NULL;
	if (!file)
		return (NULL);
	while (file[line])
	{
		ft_skip_empty(file, &line);
		if (!file[line])
			break ;
		if (get_current_label(file, &line, &first) < 0)
			return (NULL);
	}
	return (first);
}
