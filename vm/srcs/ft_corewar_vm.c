/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_corewar_vm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 17:56:29 by nvergnac          #+#    #+#             */
/*   Updated: 2018/05/11 16:00:36 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_show_player_info(t_info *info)
{
	int	i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		printf("player_nb :\t%d\n", info->players_info[i].number);
		printf("player_fd :\t%d\n\n", info->players_info[i].fd);
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_info	*info;

	info = ft_init_info();
	ft_check_argc(argc, argv, info);
	printf("Check_arg_OK\n");
	ft_define_players(argc, argv, info);
	printf("SUCCESS\n");
	ft_show_player_info(info);
	ft_create_proc(info);
	return (0);
}
