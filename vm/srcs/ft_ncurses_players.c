/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ncurses_players.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 12:35:51 by atourner          #+#    #+#             */
/*   Updated: 2018/06/15 16:02:28 by nvergnac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static char	*str_chrreplace(char *str)
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

static void	wprint_player_and_stuff(WINDOW *player, t_info *info, int i,
		char *name)
{
	mvwprintw(player, i * 4 + 1, 1,
			"Player %d -> %d", i + 1, info->players_info[i].number);
	mvwprintw(player, i * 4 + 2, 1,
			"\tName : %s", name);
	mvwprintw(player, i * 4 + 3, 1,
			"\tLive : %d", info->players_info[i].live);
}

static void	wprint_proc(WINDOW *player, t_info *info, int i)
{
	t_proc		*act;
	int			nb_pc;

	nb_pc = 0;
	act = info->first_processus;
	while (act)
	{
		if (act->alive >= 0)
			nb_pc += 1;
		act = act->next;
	}
	mvwprintw(player, i * 4 + 13, 1, "Total proc : %d", nb_pc);
}

void		wprint_player(WINDOW *player, t_info *info, int g_wait_time)
{
	int		i;
	char	*name;

	i = 0;
	while (i < info->players_nb)
	{
		wattron(player, COLOR_PAIR(5 + i));
		name = str_chrreplace(info->players_info[i].name);
		wprint_player_and_stuff(player, info, i, name);
		ft_strdel(&name);
		i++;
	}
	wattron(player, COLOR_PAIR(1));
	mvwprintw(player, --i * 4 + 5, 1, "Current period : %d / %d",
			info->countdown_to_die, info->cycles_to_die);
	mvwprintw(player, i * 4 + 6, 1, "Total cycles : %d", info->cycles);
	mvwprintw(player, i * 4 + 7, 1, "Check : %d / 9", info->check);
	mvwprintw(player, i * 4 + 9, 1, "Live(s) in current period : %d",
			info->total_lives);
	mvwprintw(player, i * 4 + 11, 1, "Wait time : %d ms", g_wait_time);
	wprint_proc(player, info, i);
}
