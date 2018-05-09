/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_comment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:34:52 by atourner          #+#    #+#             */
/*   Updated: 2018/05/07 18:15:56 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "asm.h"
#include "op.h"

static int		get_len(char **file, int i, int *act)
{
	unsigned int	line;
	unsigned int	len;

	if (i < 0)
		return (-1);
	line = *act;
	len = 0;
	while (file[line] && file[line][i] != '\"')
	{
		if (!file[line][i])
		{
			if (!file[line + 1])
				return (-1);
			i = -1;
			line++;
		}
		i++;
		len++;
	}
	*act = line + 1;
	return (len);
}

static int		cont_start(char *file, int start)
{
	int		i;

	i = 0;
	while (file[i] && ft_iswhitespace(file[i]))
		i++;
	if (file[i] == '\"')
		return (i + 1 + start);
	return (-1);
}

static char		*get_content(char **file, int line, int act, int mall)
{
	char			*content;
	int				i;
	int				len;

	i = 0;
	if ((content = ft_strnew((mall == 0 ? PROG_NAME_LENGTH : COMMENT_LENGTH))))
	{
		len = act;
		while (file[line][len] != '\"')
		{
			content[i] = file[line][len];
			if (!file[line][len])
			{
				len = -1;
				content[i] = '\n';
				line++;
			}
			len++;
			i++;
		}
	}
	return (content);
}

static char		*get_describe(char **file, int *act, int choice)
{
	int			len;
	int			cmd_len;
	int			name_len;
	int			sav;

	ft_get_describe_len(&name_len, &cmd_len, &len);
	sav = *act;
	if (!choice)
	{
		if (!strncmp(file[*act], NAME_CMD_STRING, name_len) && ((len =
		get_len(file, cont_start(&file[*act][name_len], name_len), act)) > 0)
		&& len <= PROG_NAME_LENGTH)
			return (get_content(file, sav,
						cont_start(&file[sav][name_len], 5), 0));
		else
			ft_print_error(0, len);
		return (NULL);
	}
	if (!strncmp(file[*act], COMMENT_CMD_STRING, cmd_len) && ((len =
	get_len(file, cont_start(&file[*act][cmd_len], cmd_len), act)) >= 0)
	&& len <= COMMENT_LENGTH)
		return (get_content(file, sav, cont_start(&file[sav][cmd_len], 8), 1));
	else
		ft_print_error(1, len);
	return (NULL);
}

/*
**	verif du nom et commentaire si un des deux renvoient NULL, erreur
*/

char			**ft_check_com_nam(char **file, int *act)
{
	char	**champion_describe;

	*act = 0;
	if (!(champion_describe = (char**)malloc(sizeof(char*) * 3)))
	{
		ft_printf("Malloc error\nCheck your memory\n");
		return (NULL);
	}
	ft_skip_empty(file, act);
	champion_describe[0] = get_describe(file, act, 0);
	ft_skip_empty(file, act);
	champion_describe[1] = get_describe(file, act, 1);
	champion_describe[2] = NULL;
	if (!champion_describe[0] || !champion_describe[1])
	{
		ft_free_ar((void**)champion_describe);
		return (NULL);
	}
	return (champion_describe);
}
