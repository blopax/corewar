/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 20:06:03 by atourner          #+#    #+#             */
/*   Updated: 2018/04/18 14:47:17 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "asm.h"
#include "op.h"

int			*create_champion(char **name, t_label *first)
{
	if (first && name)
		return (NULL);
	return (NULL);
}

int			*is_file_valid(char **file)
{
	char		**name;
	int			*ret;
	t_label		*first;
	int			last_line;

	ret = NULL;
	first = NULL;
	name = check_name_and_comment(file, &last_line);
	if (name)
		first = get_label(file, last_line);
	ret = create_champion(name, first);
	return (ret);
}
