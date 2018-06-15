/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ncurses.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 18:20:57 by atourner          #+#    #+#             */
/*   Updated: 2018/06/15 14:33:12 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "vm.h"

static void	option_ncurses(void)
{
	curs_set(0);
	cbreak();
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_BLACK, COLOR_WHITE);
	init_pair(3, COLOR_RED, COLOR_WHITE);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_GREEN, COLOR_BLACK);
	init_pair(6, COLOR_BLUE, COLOR_BLACK);
	init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(8, COLOR_CYAN, COLOR_BLACK);
	init_color(9, 255, 255, 255);
	init_pair(9, 9, COLOR_BLACK);
}

int			ft_init_ncurse(WINDOW **board, WINDOW **player)
{
	static int	first = 0;

	if (!first)
	{
		initscr();
		system("afplay ~/Downloads/Pokemon.mp3 &");
	}
	option_ncurses();
	*board = newwin(65 + 1, 65 * 3 + 1, 0, 0);
	*player = newwin(80, 165, 0, 65 * 3 + 2);
	box(*player, ACS_VLINE, ACS_HLINE);
	box(*board, ACS_VLINE, ACS_HLINE);
	nodelay(*board, 1);
	if (!first)
	{
		first = 1;
		wrefresh(*board);
		wrefresh(*player);
		wait_plz(1000);
		return (0);
	}
	return (1);
}

void		is_proc(int i, t_proc *act, WINDOW *board)
{
	while (act)
	{
		if (act->pc == i && act->alive > -1)
		{
			if (act->carry)
				wattron(board, COLOR_PAIR(3));
			else
				wattron(board, COLOR_PAIR(2));
			break ;
		}
		act = act->next;
	}
}

void		is_live(int i, t_info *info, WINDOW *board)
{
	int		act_player;

	act_player = 0;
	if (info->live_board[i] != 5000000000)
	{
		while (act_player < info->players_nb &&
			info->live_board[i] != info->players_info[act_player].number)
			act_player++;
		wattron(board, COLOR_PAIR(act_player + 5));
	}
}
