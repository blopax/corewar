/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ncurse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 14:59:59 by atourner          #+#    #+#             */
/*   Updated: 2018/06/12 18:05:53 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <time.h>

static int		g_wait_time = 1;
static int		g_continu_visu = 1;

void		get_ev(WINDOW *board, char c)
{
	if (c == ' ')
		ft_pause(board);
	if (c == 'm')
		change_music();
	if (c == 'q')
		if (g_wait_time >= 10)
			g_wait_time -= 10;
	if (c == 'w')
		if (g_wait_time != 0)
			g_wait_time -= 1;
	if (c == 'e')
		g_wait_time += 1;
	if (c == 'r')
		g_wait_time += 10;
	if (c == 'c')
		g_continu_visu = 0;
}

void		print_board(t_info *info, WINDOW *board, int ret)
{
	int		i;
	char	c;

	i = 0;
	while (i < MEM_SIZE)
	{
		wattron(board, COLOR_PAIR(1));
		is_proc(i, info->first_processus, board);
		mvwprintw(board, (i / 64) + 1, ((i % 64) + 1) * 3, "%.2x", info->board[i]);
		if (!ret && i % 64 == 0)
		{
			wrefresh(board);
			wait_plz(40);
		}
		i++;
	}
	wrefresh(board);
	wait_plz(g_wait_time);
	c = wgetch(board);
	if (c != ERR)
		get_ev(board, c);
}

void		print_player(t_info *info, WINDOW *player)
{

	wprint_player(player, info, g_wait_time);
	print_bulbasaur(info, player);
	print_pikachu(info, player);
	if (!g_continu_visu)
		mvwprintw(player, (info->players_nb - 1) * 4 + 12, 1,
			"Thanks for waiting the vm to calculate the end ;)");
	wrefresh(player);
}

void		ft_visu(t_info *info, int end)
{
	WINDOW		*board;
	int			ret;
	WINDOW		*player;

	if (g_continu_visu || end)
	{
		ret = ft_init_ncurse(&board, &player);
		print_board(info, board, ret);
		print_player(info, player);
	}
	if (end)
	{
		launch_end(info, player);
		while(wgetch(board) == ERR)
			;
		system("pkill afplay");
		delwin(board);
		delwin(player);
		endwin();
	}
}