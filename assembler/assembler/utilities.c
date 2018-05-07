/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 12:32:20 by atourner          #+#    #+#             */
/*   Updated: 2018/05/07 17:58:33 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "ft_printf.h"
#include "op.h"

void		ft_skip_empty(char **file, int *line)
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

char		*ft_skip_space(char *str)
{
	while (ft_iswhitespace(*str))
		str++;
	return (str);
}

int			ft_letter_lab_name(char test)
{
	char		*label_chars;
	char		*save;

	if (!(label_chars = (char*)malloc(sizeof(char) * ft_strlen(LABEL_CHARS))))
		return (0);
	ft_strcpy(label_chars, LABEL_CHARS);
	save = label_chars;
	while (*label_chars)
		if (*label_chars == test)
		{
			free(save);
			return (1);
		}
		else
			label_chars++;
	free(save);
	return (0);
}

int			ft_nb_letter(char *line, char c)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (line[i] && line[i] != COMMENT_CHAR)
		if (line[i] == c)
		{
			nb++;
			i++;
		}
		else
			i++;
	return (nb);
}

int			ft_val_lab(char *line, char **name)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (ft_iswhitespace(line[i]))
		i++;
	while (line[i + j] && ft_letter_lab_name(line[i + j]))
		j++;
	if (line[i + j] == LABEL_CHAR)
	{
		if (name)
		{
			*name = ft_strndup(&line[i], j);
			while (j != -1)
			{
				line[i + j] = ' ';
				j--;
			}
		}
		return (1);
	}
	return (0);
}
