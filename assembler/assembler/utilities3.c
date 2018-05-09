/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:09:02 by atourner          #+#    #+#             */
/*   Updated: 2018/05/07 18:11:58 by atourner         ###   ########.fr       */
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
