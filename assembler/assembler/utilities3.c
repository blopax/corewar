/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:09:02 by atourner          #+#    #+#             */
/*   Updated: 2018/06/14 10:10:28 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"
#include "ft_printf.h"

void		ft_get_describe_len(int *name_len, int *cmd_len, int *len)
{
	*name_len = (int)ft_strlen(NAME_CMD_STRING);
	*cmd_len = (int)ft_strlen(COMMENT_CMD_STRING);
	*len = 0;
}

int			ft_strncmp_s(char *line)
{
	int			len;
	int			cmd_len;
	int			name_len;
	char		*tmp;

	ft_get_describe_len(&name_len, &cmd_len, &len);
	if (!line)
		return (0);
	tmp = ft_skip_space(line);
	if (!ft_strncmp(tmp, NAME_CMD_STRING, name_len))
		return (1);
	if (!ft_strncmp(tmp, COMMENT_CMD_STRING, cmd_len))
		return (2);
	return (0);
}

int			ft_noth_after(char *line, int ret)
{
	char	*tmp;

	tmp = ft_skip_space(line);
	if (!*tmp || *tmp == '#')
		return (ret);
	return (-1);
}
