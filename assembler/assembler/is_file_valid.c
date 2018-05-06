/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 20:06:03 by atourner          #+#    #+#             */
/*   Updated: 2018/05/06 12:23:24 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "asm.h"
#include "op.h"

void				add_name_comment(unsigned char *ret, char **name, int size)
{
	int		magic;

	if (ret && name)
		magic = 0;
	magic = COREWAR_EXEC_MAGIC;
	ret[0] = magic >> 24;
	ret[1] = (magic >> 16) & 0xFF;
	ret[2] = (magic >> 8) & 0xFF;
	ret[3] = magic & 0xFF;
	ft_strncpy((char*)&ret[4], name[0], PROG_NAME_LENGTH);
	ret[4 + PROG_NAME_LENGTH + 4] = size >> 24;
	ret[4 + PROG_NAME_LENGTH + 5] = (size >> 16) & 0xFF;
	ret[4 + PROG_NAME_LENGTH + 6] = (size >> 8) & 0xFF;
	ret[4 + PROG_NAME_LENGTH + 7] = (size) & 0xFF;
	ft_strncpy((char*)&ret[4 + PROG_NAME_LENGTH + 8], name[1], COMMENT_LENGTH);
}

unsigned char		*create_champion(char **name, t_label *first, int *size_ptr)
{
	unsigned char	*ret;
	int				size;

	size = add_all_op_size(first);
	if (!first || !name ||
		!(ret = ft_memalloc(size + COMMENT_LENGTH + PROG_NAME_LENGTH + 16)))
		return (NULL);
	add_name_comment(ret, name, size);
	if (!(add_op_str(ret, first, size_ptr)))
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}

/*
**	validation du fichier si c'est bon, creation du champion
*/

t_print				*is_file_valid(char **file)
{
	char				**name;
	t_print				*ret;
	t_label				*first;
	int					last_line;

	if ((ret = (t_print*)ft_memalloc(sizeof(t_print))))
	{
		first = NULL;
		name = check_name_and_comment(file, &last_line);
		if (name)
			first = get_label(file, last_line);
		ret->str = create_champion(name, first, &ret->size);
		ft_free_ar((void**)name);
		free_chain(first, 1);
	}
	return (ret);
}
