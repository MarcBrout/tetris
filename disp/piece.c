/*
** piece.c for piece in /home/duhieu_b/Unix/PSU_2015_tetris
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Mar 18 16:14:34 2016 benjamin duhieu
** Last update Fri Mar 18 16:16:15 2016 benjamin duhieu
*/

#include <ncurses.h>
#include <curses.h>
#include <unistd.h>
#include "my.h"
#include "program.h"

void	init_piece(t_program *tetris, t_tetrimino *tet, t_pos *posit)
{
  posit->x = (tetris->tet.board.x_max / 2) - (tet->width / 2);
  posit->y = 0;
  tetris->piece = 1;
}

int	move_piece(t_program *tetris, t_tetrimino *tet, t_pos *posit)
{
  int	i;
  int	j;

  i = -1;
  while (++i < tet->size_max)
    {
      j = -1;
      while (++j < tet->size_max)
	{
	  if (tet->tmino_aff[i][j])
	    if (posit->y + i > tetris->start.row
		|| (posit->x + j < 1 || posit->x + j > tetris->start.col) ||
		tetris->tet.game.board[posit->y + i][posit->x + j] > 0)
	      return (1);
	}
    }
  return (0);
}
