/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ncurse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 14:59:59 by atourner          #+#    #+#             */
/*   Updated: 2018/06/12 15:44:58 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>
#include <time.h>

static int		g_wait_time = 1;
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

int			init_ncurse(WINDOW **board, WINDOW **player)
{
	static int	first = 0;

	if (!first)
	{
		initscr();
		system("afplay ~/Downloads/Pokemon.mp3 &");
	}
	curs_set(0);
	cbreak();
	*board = newwin(65 + 1, 65 * 3 + 1, 0, 0);
	*player = newwin(80, 165, 0, 65 * 3 + 2);
	box(*player, ACS_VLINE, ACS_HLINE);
	box(*board, ACS_VLINE, ACS_HLINE);
	nodelay(*board, 1);
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_BLACK, COLOR_WHITE);
	init_pair(3, COLOR_RED, COLOR_WHITE);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_GREEN, COLOR_BLACK);
	init_pair(6, COLOR_BLUE, COLOR_BLACK);
	init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(8, COLOR_CYAN, COLOR_BLACK);
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
			if (act->pc == i && act->alive != -1)
			{
				if (act->carry)
					wattron(board, COLOR_PAIR(3));
				else
					wattron(board, COLOR_PAIR(2));
				break;
			}
			act = act->next;
		}
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


char		*str_chrreplace(char *str)
{
	int		i;
	char	*name;

	name = ft_strnew(128);
	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			str[i] = ' ';
		else
			name[i] = str[i];
	return (name);
}

void		print_player(t_info *info, WINDOW *player)
{
	int		i;
	char	*name;

	i = 0;
	while (i < info->players_nb)
	{
		wattron(player, COLOR_PAIR(5 + i));
		name = str_chrreplace(info->players_info[i].name);
		mvwprintw(player, i * 4 + 1, 1, "Joueur %d -> %d", i, info->players_info[i].number);
		mvwprintw(player, i * 4 + 2, 1, "\tName : %s", name);
		mvwprintw(player, i * 4 + 3, 1, "\tLive : %d", info->players_info[i].live);
		ft_strdel(&name);
		i++;
	}
	wattron(player, COLOR_PAIR(1));
	mvwprintw(player, --i * 4 + 5, 1, "Cycle to die : %d", info->cycles_to_die);
	mvwprintw(player, i * 4 + 6, 1, "Actual cycle : %d", info->cycles);
	mvwprintw(player, i * 4 + 7, 1, "Check : %d / 8", info->check);
	mvwprintw(player, i * 4 + 8, 1, "Count_to_die : %d", info->countdown_to_die);
	mvwprintw(player, i * 4 + 9, 1, "Total_live : %d", info->total_lives);
	mvwprintw(player, i * 4 + 10, 1, "Wait time : %d ms", g_wait_time);
	print_bulbasaur(info, player);
	print_pikachu(info, player);
	wrefresh(player);
}

void		ft_visu(t_info *info)
{
	WINDOW		*board;
	int			ret;
	WINDOW		*player;

	ret = init_ncurse(&board, &player);
	print_player(info, player);
	print_board(info, board, ret);
}