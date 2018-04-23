/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_comment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 09:36:35 by atourner          #+#    #+#             */
/*   Updated: 2018/04/19 17:02:11 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "asm.h"
#include "op.h"

int		get_len(char **file, int i, int *act)
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

int		content_start(char *file, int start)
{
	int		i;

	i = 0;
	while (file[i] && ft_iswhitespace(file[i]))
		i++;
	if (file[i] == '\"')
		return (i + 1 + start);
	return (-1);
}

char	*get_content(char **file, int line, int act)
{
	char			*content;
	int				i;
	int				len;

	i = 0;
	if ((content = ft_strnew((line == 0 ? PROG_NAME_LENGTH : COMMENT_LENGTH))))
	{
		len = content_start(&file[line][act], act);
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

void	get_describe_len(int *name_len, int *cmd_len, int *len)
{
	*name_len = (int)ft_strlen(NAME_CMD_STRING);
	*cmd_len = (int)ft_strlen(COMMENT_CMD_STRING);
	*len = 0;
}

char	*get_describe(char **file, int *act, int choice)
{
	int			len;
	int			cmd_len;
	int			name_len;
	int			save;

	get_describe_len(&name_len, &cmd_len, &len);
	save = *act;
	if (!choice)
	{
		if (!strncmp(file[*act], NAME_CMD_STRING, name_len) && ((len =
		get_len(file, content_start(&file[*act][name_len], name_len), act)) > 0)
		&& len <= PROG_NAME_LENGTH)
			return (get_content(file, save, content_start(&file[save][name_len], 5)));
		else
			ft_printf("%s\n", len <= 0 ? "Wrong name format" : "Max name len is\
128");
	}
	else
	{
		if (!strncmp(file[*act], COMMENT_CMD_STRING, cmd_len) && ((len =
		get_len(file, content_start(&file[*act][cmd_len], cmd_len), act)) >= 0)
		&& len <= COMMENT_LENGTH)
			return (get_content(file, save, 8));
		else
			ft_printf("%s\n", len < 0 ? "Wrong comment format" : "Max comment \
len is 2048");
	}
	return (NULL);
}

/*
*	verif du nom et commentaire si un des deux renvoient NULL, erreur
*/

char	**check_name_and_comment(char **file, int *act)
{
	char	**champion_describe;

	*act = 0;
	if (!(champion_describe = (char**)malloc(sizeof(char*) * 2)))
	{
		ft_printf("Malloc error\nCheck your memory\n");
		return (NULL);
	}
	skip_comment_and_empty_line(file, act);
	champion_describe[0] = get_describe(file, act, 0);
	skip_comment_and_empty_line(file, act);
	champion_describe[1] = get_describe(file, act, 1);
	if (!champion_describe[0] || !champion_describe[1])
	{
		ft_free_ar((void**)champion_describe);
		return (NULL);
	}
	return (champion_describe);
}
