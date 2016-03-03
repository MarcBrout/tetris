/*
** aff_score.c for score in /home/duhieu_b/System_unix/PSU_2015_tetris/disp
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Thu Mar  3 10:41:16 2016 benjamin duhieu
** Last update Thu Mar  3 10:41:58 2016 benjamin duhieu
*/

#include <ncurses.h>
#include <curses.h>
#include <stdlib.h>
#include "program.h"

void	size_file(t_tet *tetris, int nbr, int place)
{
  int	power;
  int	i;

  power = 10000;
  i = 0;
  while ((power / 10) >= nbr && (power / 10) > 0)
    {
      mvwprintw(tetris->score.game, place, 13 + i, " ");
      i++;
      power /= 10;
    }
  mvwprintw(tetris->score.game, place, 13 + i, "%d", nbr);
}

void	score(t_tet *tetris)
{
  wborder(tetris->score.game, '|', '|', '-', '-', '/', '\\', '\\', '/');
  mvwprintw(tetris->score.game, 2, 2, "High Score");
  mvwprintw(tetris->score.game, 3, 2, "Score");
  mvwprintw(tetris->score.game, 5, 2, "Lines");
  mvwprintw(tetris->score.game, 6, 2, "Level");
  mvwprintw(tetris->score.game, 8, 2, "Timer:");
  size_file(tetris, tetris->play.high_score, 2);
  size_file(tetris, tetris->play.score, 3);
  mvwprintw(tetris->score.game, 5, 16, "0");
  size_file(tetris, tetris->play.line, 5);
  mvwprintw(tetris->score.game, 6, 16, "0");
  size_file(tetris, tetris->play.level, 6);
  mvwprintw(tetris->score.game, 8, 13, "00:00");
  mvwprintw(tetris->score.game, 8, 14, "%d:%d",
	    tetris->play.min, tetris->play.sec);
}

void	padding_tab(int **tab)
{
  int	i;
  int	j;

  i = -1;
  while (tab && tab[i + 1] != NULL)
    {
      j = -1;
      while (tab[i] && tab[i][++j] != -1)
	{
	if (j > 0 && j < 10)
	  tab[i][j] = 0;
	else
	  tab[i][j] = -1;
	}
    }
  j = -1;
  while (tab && tab[i] && tab[i][++j] != -1)
    tab[i][j] = -1;
}
