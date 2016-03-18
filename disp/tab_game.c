/*
** tab_game.c for tab in /home/duhieu_b/System_unix/PSU_2015_tetris/disp
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Thu Mar  3 10:42:55 2016 benjamin duhieu
** Last update Fri Mar 18 17:14:02 2016 marc brout
*/

#include <stdlib.h>
#include "program.h"

void	padding_tab(t_program *tet, int **tab)
{
  int	i;
  int	j;

  i = -1;
  while (tab && ++i < tet->start.row  && tab[i])
    {
      j = -1;
      while (++j < tet->start.col + 1)
	{
	  if (j > 0 && j < tet->start.col)
	    tab[i][j] = 0;
	  else
	    tab[i][j] = -1;
	}
    }
  j = -1;
  while (tab && ++j < tet->start.col + 1)
    tab[i][j] = -1;
}

void	padding_next(int **tab, int ymax, int xmax)
{
 int	i;
  int	j;

  i = -1;
  while (tab && ++i < ymax + 2 && tab[i])
    {
      j = -1;
      while (++j < xmax + 2)
	{
	  if (j > 0 && j < xmax + 2)
	    tab[i][j] = 0;
	  else
	    tab[i][j] = -1;
	}
    }
}

int	malloc_game(t_program *tet, t_tet *tetris)
{
  int	i;

  if ((tetris->game.board = malloc(sizeof(int *) *
				   (tet->start.row + 3))) == NULL)
    return (1);
  tetris->game.board[tet->start.row + 2] = NULL;
  i = -1;
  while (++i < tet->start.row + 1)
    {
      if ((tetris->game.board[i] = malloc(sizeof(int) *
					  tet->start.col + 3)) == NULL)
	return (1);
    }
  padding_tab(tet, tetris->game.board);
  return (0);
}

int	malloc_next(t_tet *tetris, int xmax, int ymax)
{
  int	i;

  if ((tetris->game.next = malloc(sizeof(int *) * (ymax + 3))) == NULL)
    return (1);
  tetris->game.next[ymax + 2] = NULL;
  i = -1;
  while (++i < ymax + 2)
    {
      if ((tetris->game.next[i] = malloc(sizeof(int) * (xmax + 3)))
	  == NULL)
	return (1);
      tetris->game.next[i][xmax + 2] = -1;
    }
  padding_next(tetris->game.next, ymax, xmax);
  return (0);
}
