/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_corewar_vm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvergnac <nvergnac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 17:56:29 by nvergnac          #+#    #+#             */
/*   Updated: 2018/06/15 13:32:32 by pclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_nl_space(int i)
{
	if (i % 64 == 0)
		ft_putstr("\n");
	else
		ft_putstr(" ");
}

void	ft_show_board(t_info *info)
{
	unsigned int	player;
	unsigned int	i;

	player = 0;
	i = 0;
	while (i < MEM_SIZE)
	{
		if (info->board[i] == 0)
			ft_putstr("\x1B[34m00\x1B[37m");
		else
		{
			if (info->board[i] < 16)
				ft_putstr("0");
			ft_putstr(ft_itoa_base(info->board[i], "0123456789abcdef"));
		}
		i++;
		ft_nl_space(i);
	}
	ft_putstr("\n");
}

void	ft_show_live_board(t_info *info)
{
	unsigned int	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (info->live_board[i] != 5000000000)
		{
			ft_putstr("There has been a live detected at position ");
			ft_putnbr(i);
			ft_putstr(" for player ");
			ft_putnbr(info->live_board[i]);
			ft_putstr("\n");
		}
		i++;
	}
}

void	ft_intro_contestant(t_info *info)
{
	int		i;

	i = 0;
	ft_putstr("Introducing contestants...\n");
	while (i < info->players_nb)
	{
		ft_putstr("* Player ");
		ft_putnbr(i + 1);
		ft_putstr(", weighing ");
		ft_putnbr(info->players_info[i].size);
		ft_putstr(" bytes, \"");
		ft_putstr(info->players_info[i].name);
		ft_putstr("\"\n");
		ft_putstr(info->players_info[i].comment);
		ft_putstr("\n");
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_info	*info;
	int		i;

	i = 0;
	info = ft_init_info();
	ft_check_argc(argc, argv, info);
	ft_define_players(argc, argv, info);
	while (i < info->players_nb)
	{
		if (get_player(&(info->players_info[i])) != 0)
			ft_error(7, info);
		i++;
	}
	ft_intro_contestant(info);
	set_vm(info);
	ft_create_proc(info);
	ft_run_vm(info);
	ft_free_all(info);
	return (0);
}
