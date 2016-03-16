/*
** create_win_tet.c for create
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Thu Mar  3 10:37:03 2016 benjamin duhieu
** Last update Wed Mar 16 19:24:53 2016 benjamin duhieu

*/

#include <curses.h>
#include <stdlib.h>
#include <stdio.h>
#include "program.h"

int		max_wtetriminos(t_tetrimino *tet)
{
  t_tetrimino	*elem;
  int		width;

  elem = tet->next;
  width = 0;
  while (elem != NULL)
    {
      if (width <= elem->width)
	width = elem->width;
      elem = elem->next;
    }
  return (width);
}

int		max_htetriminos(t_tetrimino *tet)
{
  t_tetrimino	*elem;
  int		height;

  elem = tet->next;
  height = 0;
  while (elem != NULL)
    {
      if (height <= elem->height)
	height = elem->height;
      elem = elem->next;
    }
  return (height);
}

int		create_win(t_program *tet, t_tet *tetris, int xmax, int ymax)
{
  getmaxyx(stdscr, tetris->height, tetris->width);
  tetris->board.x_max = tet->start.col + 2;
  tetris->board.y_max = tet->start.row + 2;
  if ((tetris->board.game = newwin(tetris->board.y_max, tetris->board.x_max,
  				   1, 27)) == NULL)
    return (my_puterror("Error : Can't create the board window\n", 1));
  tetris->score.x_max = 20;
  tetris->score.y_max = 11;
  if ((tetris->score.game = newwin(tetris->score.y_max, tetris->score.x_max,
				   8, 1)) == NULL)
    return (my_puterror("Error : Can't create the score window\n", 1));
  tetris->next.x_max = xmax + 2;
  tetris->next.y_max = ymax + 2;
  if ((tetris->next.game = newwin(tetris->next.y_max, tetris->next.x_max,
				  1, 39)) == NULL)
    return (my_puterror("Error : Can't create the next tetrimino window\n", 1));
  return (0);
}
