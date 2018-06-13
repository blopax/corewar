
#include "vm.h"

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

void	wprint_player(WINDOW *player, t_info *info, int g_wait_time)
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
}