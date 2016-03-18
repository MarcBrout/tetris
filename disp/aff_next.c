/*
** aff_next.c for yes in /home/duhieu_b/System_unix/PSU_2015_tetris
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Thu Mar  3 18:16:41 2016 benjamin duhieu
** Last update Fri Mar 18 21:17:06 2016 marc brout
*/

#include <ncurses.h>
#include <curses.h>
#include <stdbool.h>
#include "program.h"
#include "my.h"

void	aff_next(t_program *tetris)
{
  int	i;
  int	j;

  i = -1;
  while (tetris->tet.game.next && tetris->tet.game.next[++i])
    {
      j = 0;
      while (tetris->tet.game.next[i] &&
	     tetris->tet.game.next[i][++j] != -1)
	{
	  if (tetris->tet.game.next[i][j] > 0)
	    {
	      wattron(tetris->tet.next.game,
		      COLOR_PAIR(tetris->tet.game.next[i][j]));
	      mvwprintw(tetris->tet.next.game, i, j, "*");
	      wattroff(tetris->tet.next.game,
		       COLOR_PAIR(tetris->tet.game.next[i][j]));
	    }
	}
    }
}

void	put_to_next(t_program *tetris, t_tetrimino *next)
{
  int	i;
  int	j;
  t_pos	posit;

  if (tetris->start.hide)
    {
      i = -1;
      posit.x = (tetris->tet.next.x_max / 2) - (next->width / 2);
      posit.y = (tetris->tet.next.y_max / 2) - (next->height / 2);
      while (++i < next->height)
	{
	  j = -1;
	  while (++j < next->width)
	    {
	      if (next->tmino[i][j])
		tetris->tet.game.next[i + posit.y][j + posit.x] =
		  next->color;
	      else
		tetris->tet.game.next[i + posit.y][j + posit.x] = 0;
	    }
	}
      aff_next(tetris);
    }
}

void	erase_next(t_program *tetris)
{
  int	i;
  int	j;

  i = -1;
  while (tetris->tet.game.next[++i])
    {
      j = 0;
      while (tetris->tet.game.next[i][++j] != -1)
	tetris->tet.game.next[i][j] = 0;
    }
}

t_tetrimino	*next_form(t_program *tet, int *next)
{
  static bool	bol = false;

  werase(tet->tet.next.game);
  wborder(tet->tet.next.game, '|', '|', '-', '-', '/', '\\', '\\', '/');
  mvwprintw(tet->tet.next.game, 0, 1, "NEXT");
  if (!bol)
    {
      if (*next == -1)
	{
	  if (first_piece(tet))
	    return (NULL);
	}
      else if (*next == 0)
	bol = true;
      if (!bol)
	return (put_to_next(tet, tet->cur), tet->first);
    }
  if (bol)
    {
      if (!*next)
	if ((other_piece(tet)))
	  return (NULL);
      put_to_next(tet, tet->cur);
    }
  return (tet->first);
}
