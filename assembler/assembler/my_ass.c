/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_ass.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 10:58:30 by atourner          #+#    #+#             */
/*   Updated: 2018/06/15 17:38:17 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "asm.h"
#include "op.h"

/*
**	si file est null, erreur, sinon je l'imprime dans le fichier
*/

int			main(int ac, char **av)
{
	t_print		*file;

	file = NULL;
	if (ac != 2)
		ft_printf("Usage : The assembly need only one file to be used\n");
	else
	{
		if (ft_valid_name(av[1]) &&
				(file = ft_val_asm(open(av[1], O_RDONLY))) && file->str)
			ft_print_file(file, av[1]);
		else
		{
			free(file);
			ft_printf("An error has occured for the compilation \
of your file %s\n", av[0]);
		}
	}
	return (0);
}
