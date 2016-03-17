/*
** game_over.c for game_over in /home/duhieu_b/Unix/PSU_2015_tetris
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Thu Mar 17 17:46:29 2016 benjamin duhieu
** Last update Thu Mar 17 20:20:23 2016 benjamin duhieu
*/

#include <ncurses.h>
#include <curses.h>
#include "program.h"
#include "my.h"

void	size_over(t_program *tetris, int nbr, int place, int x)
{
  int	power;
  int	i;

  power = 10000;
  i = 0;
  while ((power / 10) > (nbr / 10) && (power / 10) > 0)
    {
      mvwprintw(tetris->tet.over.game, place, x + i, " ");
      i++;
      power /= 10;
    }
  mvwprintw(tetris->tet.over.game, place, x + i, "%d",
	    tetris->hscore[place - 1]);
}

void	put_score(t_program *tetris, char *str, int x, int y)
{
  int	count;
  int	i;

  count = 8 - my_strlen(str);
  x += my_strlen(str) + 1;
  i = -1;
  while (++i < count)
    mvwprintw(tetris->tet.over.game, y, x + i, " ");
  mvwprintw(tetris->tet.over.game, y, x + i, ":");
  i++;
  size_over(tetris, tetris->tet.play.score, y, x + i);
}

void	tab_score(t_program *tetris)
{
  int	i;

  werase(tetris->tet.over.game);
  wborder(tetris->tet.over.game, '|', '|', '-', '-', '/', '\\', '\\', '/');
  mvwprintw(tetris->tet.over.game, 0, 1, "HIGHSCORE");
  i = -1;
  while (++i < 10)
    {
      mvwprintw(tetris->tet.over.game, i + 1, 2, "%s", tetris->hscore[i].name);
      put_score(tetris, tetris->hscore[i].name, 2, i + 1);
    }
}

void	ga(int y)
{
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
}

void	me(int y)
{
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
}

void	ov(int y)
{
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
}

void	er(int y)
{
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
}
