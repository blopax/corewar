/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:09:02 by atourner          #+#    #+#             */
/*   Updated: 2018/06/12 17:28:35 by atourner         ###   ########.fr       */
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

int			ft_strncmp_s(char **file, int *act, int choice)
{
	int			i;
	int			len;
	int			cmd_len;
	int			name_len;

	ft_get_describe_len(&name_len, &cmd_len, &len);
	i = 0;
	while (ft_iswhitespace(file[*act][i]))
		i++;
	if (!choice)
		return (strncmp(&file[*act][i], NAME_CMD_STRING, name_len));
	return (strncmp(&file[*act][i], COMMENT_CMD_STRING, cmd_len));
}
