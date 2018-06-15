/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurse_ev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 18:08:19 by atourner          #+#    #+#             */
/*   Updated: 2018/06/15 14:36:48 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "vm.h"

const char		g_music[10][50] = {
	"afplay ~/Downloads/GuileTheme.mp3 &\0",
	"afplay ~/Downloads/Pokemon.mp3 &\0",
	"afplay ~/Downloads/Zelda.mp3 &\0",
	"afplay ~/Downloads/Mario.mp3 &\0",
	"afplay ~/Downloads/Tetris.mp3 &\0"};

void		ft_hahaaa(t_proc *act)
{
	int		dead;

	dead = 0;
	while (act)
	{
		if (act->alive == -1)
		{
			dead = 1;
			act->alive = -2;
		}
		act = act->next;
	}
	if (dead)
		system("afplay ~/Downloads/Whilem_cry.mp3 &");
}

void		wait_plz(int ms)
{
	clock_t start;

	start = clock();
	while ((clock() - start) * 1000 < (unsigned long)ms * CLOCKS_PER_SEC)
		;
}

void		ft_pause(WINDOW *board)
{
	char	c;

	while ((c = wgetch(board)) == ERR)
		;
	if (c != ' ')
	{
		get_ev(board, c);
		ft_pause(board);
	}
}

void		change_music(void)
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
	mvwprintw(player, (info->players_nb - 1) * 4 + 17, 1,
		"Winner is player %d :", info->last_player_alive);
	mvwprintw(player, (info->players_nb - 1) * 4 + 19, 1,
		"\t%s", info->players_info[info->last_player_alive_idx].name);
	wrefresh(player);
}
