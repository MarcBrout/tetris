/*
** display.c for display in /home/duhieu_b/Unix/PSU_2015_tetris
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Mar 18 16:12:17 2016 benjamin duhieu
** Last update Fri Mar 18 16:38:50 2016 benjamin duhieu
*/

#include <ncurses.h>
#include <curses.h>
#include <unistd.h>
#include "my.h"
#include "program.h"

void		display_to_board(t_program *tetris)
{
  int		i;
  int		j;

  i = -1;
  while (++i < tetris->start.row + 1)
    {
      j = -1;
	while (++j < tetris->start.col + 1)
	  {
	    if (tetris->tet.game.board[i][j] > 0)
	      {
		wattron(tetris->tet.board.game,
			COLOR_PAIR(tetris->tet.game.board[i][j]));
		mvwprintw(tetris->tet.board.game, i, j, "*");
		wattroff(tetris->tet.board.game,
			 COLOR_PAIR(tetris->tet.game.board[i][j]));
	      }
	  }
    }
}

void	display_move_piece(t_program *tetris, t_tetrimino *tet, t_pos *posit)
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
	    {
	      wattron(tetris->tet.board.game,
		      COLOR_PAIR(tet->tmino_aff[i][j]));
	      mvwprintw(tetris->tet.board.game, posit->y + i, posit->x + j, "*");
	      wattroff(tetris->tet.board.game,
		       COLOR_PAIR(tet->tmino_aff[i][j]));
	    }
	}
    }
}

int	display_piece(t_program *tetris, t_tetrimino *tet)
{
  if (move_piece(tetris, tet, &tetris->posit))
    {
      tetris->posit.y--;
      if (tetris->posit.y < 0)
	return (-1);
      put_to_board(tetris, tet, &tetris->posit);
      line_completed(tetris, tet, &tetris->posit);
      display_to_board(tetris);
      tetris->piece = 0;
      return (1);
    }
  else
    {
      display_move_piece(tetris, tet, &tetris->posit);
      display_to_board(tetris);
      tetris->posit.y++;
    }
  return (0);
}
