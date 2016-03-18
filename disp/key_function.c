/*
** key_function.c for key in /home/duhieu_b/Unix/PSU_2015_tetris
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Mar 18 16:00:12 2016 benjamin duhieu
** Last update Fri Mar 18 17:02:58 2016 benjamin duhieu
*/

#include <time.h>
#include "program.h"

int	ky_right(t_program *tetris, t_tetrimino *tet)
{
  tetris->posit.x++;
  if (move_piece(tetris, tet, &tetris->posit))
    {
      tetris->posit.x--;
      display_to_board(tetris);
      return (0);
    }
  display_move_piece(tetris, tet, &tetris->posit);
  display_to_board(tetris);
  return (0);
}

int	ky_left(t_program *tetris, t_tetrimino *tet)
{
  tetris->posit.x--;
  if (move_piece(tetris, tet, &tetris->posit))
    {
      tetris->posit.x++;
      display_to_board(tetris);
      return (0);
    }
  display_move_piece(tetris, tet, &tetris->posit);
  display_to_board(tetris);
  return (0);
}

int	ky_drop(t_program *tetris, t_tetrimino *tet)
{
  while (!(move_piece(tetris, tet, &tetris->posit)))
    tetris->posit.y++;
  return (0);
}

int	ky_turn(t_program *tetris, t_tetrimino *tet)
{
  tet->rot = (tet->rot + 1);
  set_piece(tet);
  if (move_piece(tetris, tet, &tetris->posit))
    {
      tet->rot = (tet->rot - 1);
      set_piece(tet);
    }
  return (0);
}

int		ky_pause(t_program *tetris, UNUSED t_tetrimino *tet)
{
  int		recup;
  time_t	tmp;
  char		*touch;

  if ((tmp = time(NULL)) == -1)
    return (-1);
  while (42)
    {
      if ((touch = recup_entry(tetris)))
	if ((recup = is_it_a_key(tetris->start.keys, touch)) == 5)
	  break ;
    }
  if ((tetris->pause += time(NULL) - tmp) == -1)
    return (-1);
  return (0);
}
