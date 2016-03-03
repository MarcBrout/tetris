/*
** create_win_tet.c for create
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Thu Mar  3 10:37:03 2016 benjamin duhieu
** Last update Thu Mar  3 10:39:00 2016 benjamin duhieu
*/

#include <ncurses.h>
#include <curses.h>
#include <stdlib.h>
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

int		create_win(t_tet *tetris, int xmax, int ymax)
{
  getmaxyx(stdscr, tetris->height, tetris->width);
  tetris->board.x_max = 10;
  tetris->board.y_max = 20;
  if ((tetris->board.game = subwin(stdscr,
				   tetris->board.y_max, tetris->board.x_max,
				    1, 27)) == NULL)
    return (my_puterror("Error : Can't create a new window\n", 1));
  tetris->score.x_max = 20;
  tetris->score.y_max = 11;
  if ((tetris->score.game = subwin(stdscr,
				   tetris->score.y_max, tetris->score.x_max,
				   8, 1)) == NULL)
    return (my_puterror("Error : Can't create a new window\n", 1));
  tetris->next.x_max = xmax;
  tetris->next.y_max = ymax;
  if ((tetris->next.game = subwin(stdscr,
				  tetris->next.y_max, tetris->next.x_max,
				    1, 39)) == NULL)
    return (my_puterror("Error : Can't create a new window\n", 1));
  return (0);
}
