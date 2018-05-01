/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:12:54 by atourner          #+#    #+#             */
/*   Updated: 2018/04/16 16:41:54 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "op.h"
#include "asm.h"

char	*name_cor(char *name)
{
	char	*ret;
	int		i;

	i = 0;
	if (!(ret = (char*)ft_memalloc(ft_strlen(name) + 4)))
		return (NULL);
	i = ft_strlen(name);
	ft_strcpy(ret, name);
	ret[i - 1] = 'c';
	ret[i] = 'o';
	ret[i + 1] = 'r';
	return (ret);
}

void	print_in_file(t_print *to_print, char *name)
{
	int		fd;
	char	*ret;

	if ((ret = (name_cor(name))))
	{
		fd = open(ret, O_CREAT | O_RDWR,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		if (fd > 1)
			ft_putnstr_fd((char*)to_print->str, fd, to_print->size + 1);
		ft_printf("Fichier %s created\n", ret);
		free(ret);
	}
	free(to_print->str);
	free(to_print);
}
