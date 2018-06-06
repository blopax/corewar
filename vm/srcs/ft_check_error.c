/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 15:29:38 by nvergnac          #+#    #+#             */
/*   Updated: 2018/06/06 14:40:42 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_error(int error_code)
{
	if (error_code == 1)
		ft_putstr("Incorrect parameters before a player\n");
	if (error_code == 2)
		ft_putstr("Player file not found\n");
	if (error_code == 3)
		ft_putstr("You must enter a number between -2147483648 and 2147483647\n");
	if (error_code == 4)
		ft_putstr("Problem while checking parameters\n");
	if (error_code == 5)
		ft_putstr("Two players have the same number.\n");
	if (error_code == 6)
		ft_putstr("Incorrect -dump int value.\n");
	exit (0);
}

void	ft_check_argc(int argc, char **argv, t_info *info)
{
	if (argc == 1)
	{
		ft_putstr("Error : No parameters detected.\nusage : ./corewar ");
		ft_putstr("[-dump x] [-n1] -player1.cor [-n2] -player2.cor...\n");
		exit (0);
	}
	if (argc > MAX_ARG)
	{
		ft_putstr("Error : Too many parameters.\n");
		exit (0);
	}
	if (ft_strcmp("-dump", argv[1]) == 0)
	{
		info->argv[1] = 1;
		if (ft_str_isdigit(argv[2]) == 0 && ft_atoi_cor(argv[2]) >= 0)
		{
			info->dump = ft_atoi_cor(argv[2]);
			info->argv[2] = 1;
		}
		else
			ft_error(6);
	}
}
