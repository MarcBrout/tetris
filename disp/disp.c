/*
1;2802;0c** main.c for main in /home/duhieu_b/System_unix
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Thu Feb 25 16:57:52 2016 benjamin duhieu
** Last update Thu Mar 17 19:44:53 2016 marc brout
*/

#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include <time.h>
#include <unistd.h>
#include "disp.h"
#include "program.h"
#include "my.h"
#include "get_next_line.h"

int		game_over(UNUSED t_program *tetris, UNUSED int x, int y)
{
  int	recup;
  char	*touch;

  wattron(stdscr, COLOR_PAIR(5));
  mvprintw((y / 2) - 4, 2, "*********");
  mvprintw((y / 2) - 3, 3, "*        ");
  mvprintw((y / 2) - 2, 4, "*        ");
  mvprintw((y / 2) - 1, 5, "*        ");
  mvprintw((y / 2), 6, "*   *****");
  mvprintw((y / 2) + 1, 7, "*       *");
  mvprintw((y / 2) + 2, 8, "*       *");
  mvprintw((y / 2) + 3, 9, "*       *");
  mvprintw((y / 2) + 4, 10, "*********");
  wattroff(stdscr, COLOR_PAIR(5));
  wattron(stdscr, COLOR_PAIR(3));
  mvprintw((y / 2) - 4, 12, "    *    ");
  mvprintw((y / 2) - 3, 13, "   * *   ");
  mvprintw((y / 2) - 2, 14, "  *   *  ");
  mvprintw((y / 2) - 1, 15, " *     * ");
  mvprintw(y / 2, 16, "*********");
  mvprintw((y / 2) + 1, 17, "*       *");
  mvprintw((y / 2) + 2, 18, "*       *");
  mvprintw((y / 2) + 3, 19, "*       *");
  mvprintw((y / 2) + 4, 20, "*       *");
  wattroff(stdscr, COLOR_PAIR(3));
  wattron(stdscr, COLOR_PAIR(2));
  mvprintw((y / 2) - 4, 22, "  *   *  ");
  mvprintw((y / 2) - 3, 23, " * * * * ");
  mvprintw((y / 2) - 2, 24, "*   *   *");
  mvprintw((y / 2) - 1, 25, "*       *");
  mvprintw((y / 2), 26, "*       *");
  mvprintw((y / 2) + 1, 27, "*       *");
  mvprintw((y / 2) + 2, 28, "*       *");
  mvprintw((y / 2) + 3, 29, "*       *");
  mvprintw((y / 2) + 4, 30, "*       *");
  wattroff(stdscr, COLOR_PAIR(2));
  wattron(stdscr, COLOR_PAIR(6));
  mvprintw((y / 2) - 4, 32, "*********");
  mvprintw((y / 2) - 3, 33, "*        ");
  mvprintw((y / 2) - 2, 34, "*        ");
  mvprintw((y / 2) - 1, 35, "*        ");
  mvprintw((y / 2), 36, "******   ");
  mvprintw((y / 2) + 1, 37, "*        ");
  mvprintw((y / 2) + 2, 38, "*        ");
  mvprintw((y / 2) + 3, 39, "*        ");
  mvprintw((y / 2) + 4, 40, "*********");
  wattroff(stdscr, COLOR_PAIR(6));
  wattron(stdscr, COLOR_PAIR(1));
  mvprintw((y / 2) + 6, 32, "*********");
  mvprintw((y / 2) + 7, 33, "*       *");
  mvprintw((y / 2) + 8, 34, "*       *");
  mvprintw((y / 2) + 9, 35, "*       *");
  mvprintw((y / 2) + 10, 36, "*       *");
  mvprintw((y / 2) + 11, 37, "*       *");
  mvprintw((y / 2) + 12, 38, "*       *");
  mvprintw((y / 2) + 13, 39, "*       *");
  mvprintw((y / 2) + 14, 40, "*********");
  wattroff(stdscr, COLOR_PAIR(1));
  wattron(stdscr, COLOR_PAIR(4));
  mvprintw((y / 2) + 6, 42, "*       *");
  mvprintw((y / 2) + 7, 43, "*       *");
  mvprintw((y / 2) + 8, 44, " *     * ");
  mvprintw((y / 2) + 9, 45, " *     * ");
  mvprintw((y / 2) + 10, 46, "  *   *  ");
  mvprintw((y / 2) + 11, 47, "  *   *  ");
  mvprintw((y / 2) + 12, 48, "   * *   ");
  mvprintw((y / 2) + 13, 49, "   * *   ");
  mvprintw((y / 2) + 14, 50, "    *    ");
  wattroff(stdscr, COLOR_PAIR(4));
  wattron(stdscr, COLOR_PAIR(2));
  mvprintw((y / 2) + 6, 52, "*********");
  mvprintw((y / 2) + 7, 53, "*        ");
  mvprintw((y / 2) + 8, 54, "*        ");
  mvprintw((y / 2) + 9, 55, "*        ");
  mvprintw((y / 2) + 10, 56, "******   ");
  mvprintw((y / 2) + 11, 57, "*        ");
  mvprintw((y / 2) + 12, 58, "*        ");
  mvprintw((y / 2) + 13, 59, "*        ");
  mvprintw((y / 2) + 14, 60, "*********");
  wattroff(stdscr, COLOR_PAIR(2));
  wattron(stdscr, COLOR_PAIR(6));
  mvprintw((y / 2) + 6, 62, "*********");
  mvprintw((y / 2) + 7, 63, "*       *");
  mvprintw((y / 2) + 8, 64, "*       *");
  mvprintw((y / 2) + 9, 65, "*****   *");
  mvprintw((y / 2) + 10, 66, "      ***");
  mvprintw((y / 2) + 11, 67, "    *   *");
  mvprintw((y / 2) + 12, 68, "  *     *");
  mvprintw((y / 2) + 13, 69, "*       *");
  mvprintw((y / 2) + 14, 70, "*       *");
  wattroff(stdscr, COLOR_PAIR(6));
  wrefresh(stdscr);
  if ((touch = recup_entry(tetris)))
    if ((recup = is_it_a_key(tetris->start.keys, touch)) == 4)
      return (1);
  return (0);
}

int		my_disp(t_program *tetris)
{
  int		x_max;
  int		y_max;

  srand(time(NULL));
  my_printf("\nEnter your name (6 characters max): ");
  while ((!(tetris->start.name = get_next_line(0)) ||
	  (my_strlen(tetris->start.name) > 6) || !tetris->start.name[0]))
    {
      my_printf("\nInvalid Login ...\n");
      my_printf("Please Enter a valid name (6 characters max): ");
    }
  tetris->tet.play.high_score = tetris->hscore[0].score;
  tetris->tet.play.score = 0;
  tetris->tet.play.line = 0;
  tetris->tet.play.level = tetris->start.level;
  tetris->tet.play.sec = 0;
  tetris->tet.play.min = 0;
  x_max = max_wtetriminos(tetris->tminos);
  y_max = max_htetriminos(tetris->tminos);
  if (disp(tetris, x_max, y_max))
    {
      endwin();
      return (1);
    }
  return (0);
}
