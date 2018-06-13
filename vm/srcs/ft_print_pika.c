/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pika.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 15:38:14 by atourner          #+#    #+#             */
/*   Updated: 2018/06/12 15:43:58 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		print_fourth_part(WINDOW *player, int x, int y)
{
	mvwprintw(player, 71 + y, 1 + x,
			"            ,'                  /");
	mvwprintw(player, 72 + y, 1 + x,
			"           '---------+-        /");
	mvwprintw(player, 73 + y, 1 + x,
			"                    /         /");
	mvwprintw(player, 74 + y, 1 + x,
			"                   '         /");
	mvwprintw(player, 75 + y, 1 + x,
			"                .'          /");
	mvwprintw(player, 76 + y, 1 + x,
			"              ,'           /");
	mvwprintw(player, 77 + y, 1 + x,
			"            _'....----\"\"\"\"\"");
}

static void		print_third_part(WINDOW *player, int x, int y)
{
	mvwprintw(player, 59 + y, 1 + x,
			"                 |  _ /,                     |");
	mvwprintw(player, 60 + y, 1 + x,
			"                 | | L)'..                   |");
	mvwprintw(player, 61 + y, 1 + x,
			"                 | .    | `                  |");
	mvwprintw(player, 62 + y, 1 + x,
			"                 '  \\'   L                   '");
	mvwprintw(player, 63 + y, 1 + x,
			"                  \\  \\   |                  j");
	mvwprintw(player, 64 + y, 1 + x,
			"                     `. `__'                 /");
	mvwprintw(player, 65 + y, 1 + x,
			"                 _,.--.---........__      /");
	mvwprintw(player, 66 + y, 1 + x,
			"                ---.,'---`         |   -j\"");
	mvwprintw(player, 67 + y, 1 + x,
			"                 .-'  '....__      L    |");
	mvwprintw(player, 68 + y, 1 + x,
			"               \"\"--..    _,-'       \\ l||");
	mvwprintw(player, 69 + y, 1 + x,
			"                   ,-'  .....------. `||'");
	mvwprintw(player, 70 + y, 1 + x,
			"               _,'                /");
}

static void		print_second_part(WINDOW *player, int x, int y)
{
	mvwprintw(player, 47 + y, 1 + x,
			"               |   _...        .____     | |/    '");
	mvwprintw(player, 48 + y, 1 + x,
			"          _.   |  .    `.  '--\"   /      `./     j");
	mvwprintw(player, 49 + y, 1 + x,
			"         \\' `-.|  '     |   `.   /        /     /");
	mvwprintw(player, 50 + y, 1 + x,
			"         '     `-. `---\"      `-\"        /     /");
	mvwprintw(player, 51 + y, 1 + x,
			"          \\       `.                  _,'     /");
	mvwprintw(player, 52 + y, 1 + x,
			"           \\        `                        .");
	mvwprintw(player, 53 + y, 1 + x,
			"            \\                                j");
	mvwprintw(player, 54 + y, 1 + x,
			"             \\                              /");
	mvwprintw(player, 55 + y, 1 + x,
			"               `.                           .");
	mvwprintw(player, 56 + y, 1 + x,
			"                 +                          \\");
	mvwprintw(player, 57 + y, 1 + x,
			"                 |                           L");
	mvwprintw(player, 58 + y, 1 + x,
			"                 |                           |");
}

static void		print_first_part(WINDOW *player, int x, int y)
{
	mvwprintw(player, 35 + y, 1 + x,
			"                                             ,-.");
	mvwprintw(player, 36 + y, 1 + x,
			"                                          _.|  '");
	mvwprintw(player, 37 + y, 1 + x,
			"                                        .'  | /");
	mvwprintw(player, 38 + y, 1 + x,
			"                                      ,'    |'");
	mvwprintw(player, 39 + y, 1 + x,
			"                                     /      /");
	mvwprintw(player, 40 + y, 1 + x,
			"                       _..----""---.'      /");
	mvwprintw(player, 41 + y, 1 + x,
			" _.....---------...,-\"\"                  ,'");
	mvwprintw(player, 42 + y, 1 + x,
			" `-._  \\                                /");
	mvwprintw(player, 43 + y, 1 + x,
			"     `-.+_            __           ,--. .");
	mvwprintw(player, 44 + y, 1 + x,
			"          `-.._     .:  ).        (`--\"| \\");
	mvwprintw(player, 45 + y, 1 + x,
			"               7    | `\" |         `...'  \\");
	mvwprintw(player, 46 + y, 1 + x,
			"               |     `--'     '+\"        ,\". ,\"\"-");
}

void			print_pikachu(t_info *info, WINDOW *player)
{
	static int	x;
	static int	y;

	wattron(player, COLOR_PAIR(4));
	if (!(info->cycles % 75))
	{
		x = 2;
		y = 0;
	}
	else if (!(info->cycles % 50))
	{
		x = 0;
		y = 0;
	}
	else if (!(info->cycles % 25))
	{
		x = 1;
		y = -1;
	}
	print_first_part(player, x, y);
	print_second_part(player, x, y);
	print_third_part(player, x, y);
	print_fourth_part(player, x, y);
}
