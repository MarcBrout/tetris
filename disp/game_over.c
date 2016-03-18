/*
** game_over.c for game_over in /home/duhieu_b/Unix/PSU_2015_tetris
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Thu Mar 17 17:46:29 2016 benjamin duhieu
** Last update Fri Mar 18 17:43:43 2016 marc brout
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
  mvwprintw(tetris->tet.over.game, place, x + i, "%d", nbr);
}

void	put_score(t_program *tetris, char *str, int x, int y)
{
  int	count;
  int	i;

  count = (str) ? 8 - my_strlen(str) : 8;
  x += (str) ? my_strlen(str) + 1 : 1;
  i = -1;
  while (++i < count)
    mvwprintw(tetris->tet.over.game, y, x + i, " ");
  mvwprintw(tetris->tet.over.game, y, x + i, ":");
  i++;
  size_over(tetris, tetris->hscore[y - 1].score, y, x + i);
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
