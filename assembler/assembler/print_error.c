/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:34:37 by atourner          #+#    #+#             */
/*   Updated: 2018/05/07 16:34:39 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "asm.h"
#include "op.h"

void		ft_print_error(int type, int len)
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
