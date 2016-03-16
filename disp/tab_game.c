/*
** tab_game.c for tab in /home/duhieu_b/System_unix/PSU_2015_tetris/disp
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Thu Mar  3 10:42:55 2016 benjamin duhieu
** Last update Tue Mar 15 18:56:10 2016 benjamin duhieu
*/

#include <stdlib.h>
#include "program.h"

void	padding_tab(int **tab)
{
  int	i;
  int	j;

  i = -1;
  while (tab && ++i < 18 && tab[i])
    {
      j = -1;
      while (++j < 12)
	{
	  if (j > 0 && j < 11)
	    tab[i][j] = 0;
	  else
	    tab[i][j] = -1;
	}
    }
  j = -1;
  while (tab && ++j < 12)
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

int	malloc_game(t_tet *tetris)
{
  int	i;

  if ((tetris->game.board = malloc(sizeof(int *) * (20))) == NULL)
    return (1);
  tetris->game.board[19] = NULL;
  i = -1;
  while (++i < 19)
    {
      if ((tetris->game.board[i] = malloc(sizeof(int) * 12)) == NULL)
	return (1);
      tetris->game.board[i][11] = -1;
    }
  padding_tab(tetris->game.board);
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
      if ((tetris->game.next[i] = malloc(sizeof(int) * (xmax + 3))) == NULL)
	return (1);
      tetris->game.next[i][xmax + 2] = -1;
    }
  padding_next(tetris->game.next, ymax, xmax);
  return (0);
}
