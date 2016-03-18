/*
** chk_board.c for chk_board in /home/duhieu_b/Unix/PSU_2015_tetris
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Mar 18 16:13:52 2016 benjamin duhieu
** Last update Fri Mar 18 18:25:38 2016 marc brout
*/

#include <ncurses.h>
#include <curses.h>
#include <unistd.h>
#include "my.h"
#include "program.h"

int	line_completed(t_program *tetris, t_tetrimino *tet, t_pos *posit)
{
  int	i;
  int	j;
  int	count;
  char	chk;

  i = -1;
  chk = 0;
  count = 0;
  while (++i < tet->size_max)
    {
      j = 0;
      while ((posit->y + i) < (tetris->start.row + 1) &&
	     tetris->tet.game.board[posit->y + i][++j] > 0);
      if (j == tetris->start.col + 1)
	{
	  tetris->tet.play.line++;
	  count++;
	  new_tab(tetris->tet.game.board, posit->y + i);
	  chk = 1;
	}
    }
  tetris->tet.play.score += (count * count) * 10;
  return (chk);
}

void	put_to_board(t_program *tetris, t_tetrimino *tet, t_pos *posit)
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
	    tetris->tet.game.board[posit->y + i][posit->x + j] = tet->tmino_aff[i][j];
	}
    }
}

void	init_tab(int (*key_tab[6])(t_program *, t_tetrimino *))
{
  key_tab[K_LEFT] = &ky_left;
  key_tab[K_RIGHT] = &ky_right;
  key_tab[K_TURN] = &ky_turn;
  key_tab[K_DROP] = &ky_drop;
  key_tab[K_QUIT] = &ky_quit;
  key_tab[K_PAUSE] = &ky_pause;
}

void	new_tab(int **tab, int i)
{
  int	j;

  while (i > 0)
    {
      j = 0;
      while (tab[i][++j] != -1)
	tab[i][j] = tab[i - 1][j];
      i--;
    }
}
