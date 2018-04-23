/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 10:40:02 by atourner          #+#    #+#             */
/*   Updated: 2018/04/20 17:05:41 by atourner         ###   ########.fr       */
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
	return (last->next);
}

int			is_letter_in_label_name(char test)
{
	char	*label_chars = LABEL_CHARS;

	while (*label_chars)
		if (*label_chars == test)
			return (1);
		else
			label_chars++;
	return (0);
}

int			label_name_valid(char *line, char **name)
{
	int		i;

	i = 0;
	while (ft_iswhitespace(line[i]))
		i++;
	while (line[i] && is_letter_in_label_name(line[i]))
		i++;
	if (line[i] == ':')
		if (name && (*name = ft_strndup(line, i)))
			return (1);
	return (0);
}

int			get_current_label(char **file, int *line, t_label **first)
{
	t_label		*act;

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

void		skip_comment_and_empty_line(char **file, int *line)
{
	int		i;

	i = 0;
	while (file[*line])
	{
		if (!ft_iswhitespace(file[*line][i]) && file[*line][i])
			if (file[*line][i] != '#')
				return ;
		if (!file[*line][i] || file[*line][i] == '#')
		{
			i = -1;
			*line += 1;
		}
		i++;
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
		if (get_current_label(file, &line, &first) < 0)
			return (NULL);
	}
	return (NULL);
}
