/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_comment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:34:52 by atourner          #+#    #+#             */
/*   Updated: 2018/06/14 10:09:21 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "asm.h"
#include "op.h"

static int		get_len(char **file, int i, int act)
{
	unsigned int	len;

	if (i < 0 || !file[act])
		return (-1);
	len = 0;
	while (file[act] && file[act][i] != '\"')
	{
		if (!file[act][i])
		{
			if (!file[act + 1])
				return (-1);
			i = -1;
			act++;
		}
		i++;
		len++;
	}
	if (!file[act])
		return (-1);
	return (ft_noth_after(&file[act][i + 1], len));
}

static int		cont_start(char *file, int start, int *start_in_f)
{
	char	*tmp;

	if (!file)
		return (-1);
	tmp = ft_skip_space(file);
	if (*tmp == '\"')
	{
		*start_in_f = tmp - file + 1 + start;
		return (tmp - file + 1 + start);
	}
	return (-1);
}

static char		*get_content(char **file, int *line, int act, int mall)
{
	char			*content;
	int				i;
	int				len;

	i = 0;
	if ((content = ft_strnew((mall == 0 ? PROG_NAME_LENGTH : COMMENT_LENGTH))))
	{
		len = act;
		while (file[*line][len] != '\"')
		{
			content[i] = file[*line][len];
			if (!file[*line][len])
			{
				len = -1;
				content[i] = '\n';
				*line += 1;
			}
			len++;
			i++;
		}
	}
	*line += 1;
	return (content);
}

static void		get_describe(char **file, int *act, int choice,
	char **champion_describe)
{
	int			len;
	int			cmd_len;
	int			name_len;
	int			start;

	ft_get_describe_len(&name_len, &cmd_len, &len);
	choice = ft_strncmp_s(file[*act]);
	if (choice == 1 && ((len = get_len(file,
	cont_start(&file[*act][name_len], name_len, &start), *act)) > 0)
		&& len <= PROG_NAME_LENGTH)
	{
		if (!champion_describe[0])
			champion_describe[0] = get_content(file, act, start, 0);
		return ;
	}
	else if (choice == 2 && ((len = get_len(file,
		cont_start(&file[*act][cmd_len], cmd_len, &start), *act)) >= 0)
	&& len <= COMMENT_LENGTH)
	{
		if (!champion_describe[1])
			champion_describe[1] = get_content(file, act, start, 1);
		return ;
	}
	ft_print_error(choice, len);
}

/*
**	verif du nom et commentaire si un des deux renvoient NULL, erreur
*/

char			**ft_check_com_nam(char **file, int *act)
{
	char	**champion_describe;

	*act = 0;
	if (!(champion_describe = (char**)ft_memalloc(sizeof(char*) * 3)))
	{
		ft_printf("Malloc error\nCheck your memory\n");
		return (NULL);
	}
	ft_skip_empty(file, act);
	get_describe(file, act, 0, champion_describe);
	ft_skip_empty(file, act);
	if (champion_describe[0] || champion_describe[1])
		get_describe(file, act, 0, champion_describe);
	champion_describe[2] = NULL;
	if (!champion_describe[0] || !champion_describe[1])
	{
		ft_free_ar((void**)champion_describe);
		return (NULL);
	}
	return (champion_describe);
}
