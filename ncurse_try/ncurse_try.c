#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

/*
 * http://tldp.org/HOWTO/NCURSES-Programming-HOWTO/
 */

void wait_plz(int ms)
{
    clock_t start = clock();
    while ((clock() - start) * 1000 < ms * CLOCKS_PER_SEC);
}

int main()
{
	initscr();
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_RED);
	init_pair(2, COLOR_BLACK, COLOR_GREEN);
	init_pair(3, COLOR_BLACK, COLOR_YELLOW);
	init_pair(4, COLOR_BLACK, COLOR_WHITE);
	init_pair(5, COLOR_BLACK, COLOR_BLUE);
	int		i = 0;
	system("afplay ~/Downloads/GuileTheme.mp3 &");
	while (i < 200)
	{
		wait_plz(50);
		i++;
		attron(COLOR_PAIR(i % 1));
		mvprintw(1,0,"%.2x\n", 0xFF);
		attron(COLOR_PAIR(i % 2));
		mvprintw(2,0,"%.2x\n", 0x00);
		attron(COLOR_PAIR(i % 3));
		mvprintw(3,0,"%.2x\n", 0xFF);
		attron(COLOR_PAIR(i % 4));
		mvprintw(4,0,"%.2x\n", 0xFF);
		attron(COLOR_PAIR(i % 5));
		mvprintw(5,0,"%.2x\n", 0xFF);
		refresh();
		if (!(i % 50))
			system("afplay ~/Downloads/Whilem_cry.mp3 &");
	}
	system("pkill afplay; afplay ~/Downloads/final_victory.mp3 &");
	getch();
	endwin();
	return (0);
}
