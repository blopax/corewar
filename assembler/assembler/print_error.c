/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 13:02:10 by atourner          #+#    #+#             */
/*   Updated: 2018/05/06 13:11:01 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "asm.h"
#include "op.h"

void		print_error(int type, int len)
{
	char	str[9];
	int		len_err;

	if (type == 0)
		ft_strcpy(str, "name\0");
	else
		ft_strcpy(str, "comment\0");
	if (len <= 0)
		ft_printf("Wrong %s format\n", str);
	else
	{
		len_err = (type == 0 ? PROG_NAME_LENGTH : COMMENT_LENGTH);
		ft_printf("Max %s len is %d\nYours is %d\n", str, len_err, len);
	}
}
