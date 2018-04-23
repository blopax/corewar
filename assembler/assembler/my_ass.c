/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_ass.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 10:58:30 by atourner          #+#    #+#             */
/*   Updated: 2018/04/16 16:45:57 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "asm.h"
#include "op.h"

int		main(int ac, char **av)
{
	int		*file;

	if (ac == 1)
		ft_printf("Usage : The assembly need at least one file to be used\n");
	else
	{
		while (++av && *av)
		{
			if (valid_name(av[0]) && (file = val_asm(open(av[0], O_RDONLY))))
				print_in_file(file, av[0]);
			else
				ft_printf("An error has occured for the compilation \
of your file %s\n", av[0]);
		}
	}
	return (0);
}
