/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 15:29:38 by nvergnac          #+#    #+#             */
/*   Updated: 2018/06/15 14:38:51 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_usage(void)
{
	ft_putstr("usage : ./corewar ");
	ft_putstr("[-visual] [-dump [x]] [-n [n1]] player1.cor ");
	ft_putstr("[-n [n2]] player2.cor [-n [n3]] player3.cor ");
	ft_putstr("[-n [n4]] player4.cor...\n\n");
	ft_putstr("-visual :\tEnable ncurse visual for Corewar.\n");
	ft_putstr("-dump :\t\tDump the memory at the 'n' cycle.\n");
	ft_putstr("-n :\t\tChange player's R1 value\n\n");
	ft_putstr("'-dump' and '-visual' flags are not compatible\n");
}

void	ft_error(int error_code, t_info *info)
{
	if (error_code == 1)
		ft_putstr("Incorrect parameters before a player\n");
	if (error_code == 2)
		ft_putstr("Player file not found\n");
	if (error_code == 3)
		ft_putstr("You must enter a valid number\n");
	if (error_code == 4)
		ft_putstr("Problem while checking parameters\n");
	if (error_code == 5)
		ft_putstr("Two players have the same number.\n");
	if (error_code == 6)
		ft_putstr("Incorrect -dump int value or no value.\n");
	if (error_code == 7)
		ft_putstr("Incorrect .cor parameter.\n");
	if (error_code == 8)
		ft_putstr("No player detected.\n");
	if (error_code == 9)
		ft_putstr("Error : No parameters detected.\n");
	ft_usage();
	ft_free_all(info);
	exit(0);
}

void	ft_check_argc(int argc, char **argv, t_info *info)
{
	if (argc == 1)
		ft_error(9, info);
	if (argc > MAX_ARG)
	{
		ft_putstr("Error : Too many parameters.\n");
		ft_free_all(info);
		exit(0);
	}
	if (ft_strcmp("-visual", argv[1]) == 0)
	{
		info->argv[1] = 1;
		info->visual = 1;
	}
	if (ft_strcmp("-dump", argv[1]) == 0)
	{
		info->argv[1] = 1;
		if (ft_str_isdigit(argv[2]) == 0 && ft_atoi_cor(argv[2], info) >= 0)
		{
			info->dump = ft_atoi_cor(argv[2], info);
			info->argv[2] = 1;
		}
		else
			ft_error(6, info);
	}
}
