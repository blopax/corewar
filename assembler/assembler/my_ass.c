/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_ass.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 10:58:30 by atourner          #+#    #+#             */
/*   Updated: 2018/05/06 12:23:32 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "asm.h"
#include "op.h"

/*
**	si file est null, erreur, sinon je l'imprime dans le fichier
*/

int		main(int ac, char **av)
{
	t_print		*file;

	if (ac == 1)
		ft_printf("Usage : The assembly need at least one file to be used\n");
	else
	{
		while (++av && *av)
		{
			if (valid_name(av[0]) &&
					(file = val_asm(open(av[0], O_RDONLY))) && file->str)
				print_in_file(file, av[0]);
			else
			{
				free(file);
				ft_printf("An error has occured for the compilation \
of your file %s\n", av[0]);
			}
		}
	}
	return (0);
}
