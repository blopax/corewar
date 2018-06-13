/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurse_ev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 18:08:19 by atourner          #+#    #+#             */
/*   Updated: 2018/06/12 18:09:15 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "vm.h"

const char		g_music[10][50] =
			{"afplay ~/Downloads/GuileTheme.mp3 &\0",
			"afplay ~/Downloads/Pokemon.mp3 &\0",
			"afplay ~/Downloads/Zelda.mp3 &\0",
			"afplay ~/Downloads/Mario.mp3 &\0",
			"afplay ~/Downloads/Tetris.mp3 &\0"};

void	wait_plz(int ms)
{
    clock_t start = clock();
    while ((clock() - start) * 1000 < (unsigned long)ms * CLOCKS_PER_SEC);
}

void		ft_pause(WINDOW *board)
{
	while (wgetch(board) != ' ')
		;
}

void		change_music()
{
	static int	m = 1;

	if (m > -1)
	{
		m = -1;
		system("pkill afplay");
	}
	else
	{
		srand(time(NULL));
		m = rand() % 5;
		system(g_music[m]);
	}
}

void		launch_end(t_info *info, WINDOW *player)
{
	system("pkill afplay");
	system("afplay ~/Downloads/Pokemon_final.mp3 &");
	mvwprintw(player, (info->players_nb - 1) * 4 + 14, 1,
		"Winner is player %d :", info->last_player_alive);
	mvwprintw(player, (info->players_nb - 1)* 4 + 15, 1,
		"\t%s", info->players_info[info->last_player_alive].name);
	wrefresh(player);
}