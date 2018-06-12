/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bulbi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 15:28:01 by atourner          #+#    #+#             */
/*   Updated: 2018/06/12 15:34:16 by atourner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm.h>

static void		print_third_part(WINDOW *player, int x, int y)
{
	mvwprintw(player, 73 + y, 90 + x,
		"    | .\" `. `-.                /-.           /          ,");
	mvwprintw(player, 74 + y, 90 + x,
		"    | `._.'    `,_            ;  /         ,'          .");
	mvwprintw(player, 75 + y, 90 + x,
		"   .'          /| `-.        . ,'         ,           ,");
	mvwprintw(player, 76 + y, 90 + x,
		"   '-.__ __ _,','    '`-..___;-...__   ,.'\\ ____.___.'");
	mvwprintw(player, 77 + y, 90 + x,
		"   `\"^--'..'   '-`-^-'\"--    `-^-'`.''\"\"\"\"\"`.,^.`.--'");
}

static void		print_second_part(WINDOW *player, int x, int y)
{
	mvwprintw(player, 62 + y, 90 + x,
		"    ,`-.    ,\".   `--'                      >.      ,'     |");
	mvwprintw(player, 63 + y, 90 + x,
		"   . .'\'   `-'       __    ,  ,-.         /  `.__.-      ,'");
	mvwprintw(player, 64 + y, 90 + x,
		"   ||:, .           ,'  ;  /  / \\ `        `.    .      .'/");
	mvwprintw(player, 65 + y, 90 + x,
		"   j|:D  \\          `--'  ' ,'_  . .         `.__, \\   , /");
	mvwprintw(player, 66 + y, 90 + x,
		"  / L:_  |                 .  \"' :_;                `.'.'");
	mvwprintw(player, 67 + y, 90 + x,
		"  .    \"\"'                  \"\"\"\"\"'                    V");
	mvwprintw(player, 68 + y, 90 + x,
		"   `.                                 .    `.   _,..  `");
	mvwprintw(player, 69 + y, 90 + x,
		"     `,_   .    .                _,-'/    .. `,'   __  `");
	mvwprintw(player, 70 + y, 90 + x,
		"      ) \\`._        ___....----\"'  ,'   .'  \\ |   '  \\  .");
	mvwprintw(player, 71 + y, 90 + x,
		"     /   `. \"`-.--\"'         _,' ,'     `---' |    `./  |");
	mvwprintw(player, 72 + y, 90 + x,
		"    .   _  `\"\"'--.._____..--\"   ,             '         |");
}

static void		print_first_part(WINDOW *player, int x, int y)
{
	mvwprintw(player, 50 + y, 90 + x,
		"                                             /");
	mvwprintw(player, 51 + y, 90 + x,
		"                          _,.------....___,.' ',.-.");
	mvwprintw(player, 52 + y, 90 + x,
		"                       ,-'          _,.--\"        |");
	mvwprintw(player, 53 + y, 90 + x,
		"                     ,'         _.-'              .");
	mvwprintw(player, 54 + y, 90 + x,
		"                    /   ,     ,'                   `");
	mvwprintw(player, 55 + y, 90 + x,
		"                   .   /     /                     ``.");
	mvwprintw(player, 56 + y, 90 + x,
		"                   |  |     .                       \\.\\ ");
	mvwprintw(player, 57 + y, 90 + x,
		"         ____      |___._.  |       __               \\ `.");
	mvwprintw(player, 58 + y, 90 + x,
		"       .'    `---\"\"       ``\"-.--\"'`  \\               .  \\ ");
	mvwprintw(player, 59 + y, 90 + x,
		"      .  ,            __               `              |   .");
	mvwprintw(player, 60 + y, 90 + x,
		"      `,'         ,-\"'  .               \\             |    L");
	mvwprintw(player, 61 + y, 90 + x,
		"     ,'          '    _.'                -._          /    |");
}

void			print_bulbasaur(t_info *info, WINDOW *player)
{
	static int		x;
	static int		y;

	wattron(player, COLOR_PAIR(5));
	if (!(info->cycles % 100))
	{
		x = 1;
		y = 0;
	}
	else if (!(info->cycles % 50))
	{
		x = -1;
		y = 0;
	}
	else if (!(info->cycles % 25))
	{
		x = 0;
		y = -1;
	}
	print_first_part(player, x, y);
	print_second_part(player, x, y);
	print_third_part(player, x, y);
}
