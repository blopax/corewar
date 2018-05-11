/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_corewar_vm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 17:56:29 by nvergnac          #+#    #+#             */
/*   Updated: 2018/05/11 17:37:28 by pclement         ###   ########.fr       */
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
		printf("player_fd :\t%d\n\n", info->players_info[i].fd);
		printf("player_header :\t%p\n\n", info->players_info[i].header);
		printf("player_magic :\t%d\n\n", info->players_info[i].magic);
		printf("player_name :\t%s\n\n", info->players_info[i].name);
		printf("player_comment :\t%s\n\n", info->players_info[i].comment);
		printf("player_size :\t%d\n\n", info->players_info[i].size);
		printf("player_program :\t%s\n\n", info->players_info[i].program);
		printf("player_fd :\t%d\n\n", info->players_info[i].fd);
		i++;
	}
}

void	ft_show_board(t_info *info)
{
	printf("board =\n\n%s", info->board);
}


int		main(int argc, char **argv)
{
	t_info	*info;
	int		i;

	info = ft_init_info();
	ft_check_argc(argc, argv, info);
	printf("Check_arg_OK\n");
	ft_define_players(argc, argv, info);
	printf("SUCCESS\n");
	i = 0;
	while (i < info->players_nb)
	{
		get_player(&(info->players_info[i]));
		i++;
	}
//	set_vm(info);
	ft_show_player_info(info);
	ft_show_board(info);
	return (0);
}
