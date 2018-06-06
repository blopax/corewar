/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_corewar_vm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 17:56:29 by nvergnac          #+#    #+#             */
/*   Updated: 2018/06/06 15:58:31 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_show_player_info(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->players_nb)
	{
		printf("player_nb :\t%d\n", info->players_info[i].number);
		printf("player_fd :\t%d\n", info->players_info[i].fd);
		printf("player_header :\t%p\n", info->players_info[i].header);
		printf("player_magic :\t%u\n", info->players_info[i].magic);
		printf("player_name :\t%s\n", info->players_info[i].name);
		printf("player_comment :\t%s\n", info->players_info[i].comment);
		printf("player_size :\t%u\n", info->players_info[i].size);
		printf("player_program :\t%p\n", info->players_info[i].program);
		printf("_______________________\n");
		i++;
	}
}

void	ft_show_board(t_info *info)
{
	unsigned int	player;
	unsigned int	i;

	player = 0;
	i = 0;
	while (i < MEM_SIZE)
	{
		while (i < player * MEM_SIZE / info->players_nb + info->players_info[player].size)
		{
			if (info->board[i] < 16)
				printf("0");
			printf("%x", info->board[i]);
			i++;
			if (i % 64 == 0)
				printf("\n");
			else
				printf(" ");
		}
		player++;
		while (i < player * MEM_SIZE / info->players_nb)
		{
			if (info->board[i] == 0)
			{
				printf("\x1B[34m");
				printf("00");
				printf("\x1B[37m");
			}
			else
			{
				if (info->board[i] < 16)
					printf("0");
				printf("%x", info->board[i]);
			}
			i++;
			if (i % 64 == 0)
				printf("\n");
			else
				printf(" ");
		}
	}
	ft_putstr("\n");
}

int		main(int argc, char **argv)
{
	t_info	*info;
	int		i;

	info = ft_init_info();
	ft_check_argc(argc, argv, info);
//	printf("Check_arg_OK\n");
	ft_define_players(argc, argv, info);
//	printf("SUCCESS\n");
	i = 0;
	while (i < info->players_nb)
	{
		get_player(&(info->players_info[i]));
		i++;
	}
	set_vm(info);
	ft_create_proc(info);
	ft_show_board(info);
	printf("_______________________\n");
	ft_show_player_info(info);
//	free_player(&(info->players_info[0]));
	ft_run_vm(info);
//	ft_show_board(info);
	ft_free_all(info);
	return (0);
}
