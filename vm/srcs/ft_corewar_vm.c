/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_corewar_vm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 17:56:29 by nvergnac          #+#    #+#             */
/*   Updated: 2018/05/02 19:30:06 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_proc	*ft_init_proc(void)
{
	t_proc	*new_proc;

	new_proc = (t_proc*)malloc(sizeof(t_proc));
	ft_bzero(new_proc->reg, sizeof(int) * 16);
	new_proc->carry = 0;
	new_proc->pc = 0;
	new_proc->opcode = 0;
	new_proc->ocp = 0;
	new_proc->cycles_to_go = 0;
	new_proc->alive = 0;
	new_proc->next = 0;
	return (new_proc);
}

void	ft_init_players(t_info *new_info)
{
	int		i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		new_info->players_info[i].fd = 0;
		new_info->players_info[i].header = 0;
		new_info->players_info[i].magic = 0;
		new_info->players_info[i].name = 0;
		new_info->players_info[i].comment = 0;
		new_info->players_info[i].size = 0;
		new_info->players_info[i].program = 0;
		new_info->players_info[i].live = 0;
		new_info->players_info[i].turn = 0;
		new_info->players_info[i].number = 0;
		i++;
	}
}

t_info	*ft_init_info(void)
{
	t_info	*new_info;

	new_info = (t_info*)malloc((sizeof(t_info)));
	ft_bzero(new_info->board, MEM_SIZE);
	new_info->first_processus = ft_init_proc();
	new_info->cycles_to_die = CYCLE_TO_DIE;
	new_info->cycles = 0;
	new_info->check = 0;
	new_info->lives_threshold = NBR_LIVE;
	new_info->total_lives = 0;
	new_info->dump = 0;
	new_info->players_nb = 0;
	ft_init_players(new_info);
	ft_bzero(new_info->argv, 15);
	return (new_info);
}

void	ft_error(int error_code)
{
	if (error_code == 1)
		ft_putstr("Incorrect parameters before a player\n");
	if (error_code == 2)
		ft_putstr("Player file not found\n");
	if (error_code == 3)
		ft_putstr("Incorrect number used in parameters\n");
	exit (0);
}

void	ft_check_argv_validity(t_info *info, int i)
{
	int	k;

	k = 0;
	while (k < i)
	{
		if (info->argv[k] == 0)
			ft_error(4);
		k++;
	}
}

void	ft_define_players(int argc, char **argv, t_info *info)
{
	int i;
	int n_flag;

	i = 1;
	while (i < argc)
	{
		n_flag = 0;
		if (ft_strcmp(ft_strstr(argv[i], ".cor"), ".cor") == 0)
		{
			info->argv[i] = 1;
			if (i > 2 && ft_strcmp(argv[i - 2], "-n") == 0)
			{
				info->argv[i - 2] = 1;
				if ((argv[i - 1][0] != '-' ||
						ft_isdigit(ft_atoi_cor(argv[i - 1] + 1)) != 0) &&
						(n_flag = ft_atoi(argv[i - 1]) * -1) >= 0)
					info->argv[i - 1] = 1;
				else
					ft_error(1);
			}
			if ((info->players_info[info->players_nb].fd =
						open(argv[i], O_RDONLY)) == -1)
				ft_error(2);
			info->players_nb++;
			ft_check_argv_validity(info, i);
		}
		i++;
	}
}

void	ft_check_argc(int argc, char **argv, t_info *info)
{
	if (argc == 0)
	{
		ft_putstr("Error : No parameters detected.\nusage : ./corewar ");
		ft_putstr("[-dump n] [-n] -player1.cor [-n] -player2.cor...\n");
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
		if((info->dump = ft_atoi(argv[2])) > 0)
			info->argv[2] = 1;
		else
			ft_error(3);
	}
}

int	main(int argc, char **argv)
{
	t_info	*info;

	info = ft_init_info();
	ft_check_argc(argc, argv, info);
	ft_define_players(argc, argv, info);
	return (0);
}
