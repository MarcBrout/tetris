/*
** rotate.c for tetris in /home/brout_m/RENDU/PSU/PSU_2015_tetris
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu Mar 17 17:55:54 2016 marc brout
** Last update Fri Mar 18 14:25:41 2016 marc brout
*/

#include "program.h"
#include "my.h"

void		rotate_piece(t_tetrimino *tmino, int max)
{
  int		x;
  int		y;
  int		i;
  int		j;

  x = 0;
  j = 0;
  while (x < max)
    {
      i = 0;
      y = max - 1;
      while (y >= 0)
	{
	  tmino->tmino_rot[j][i] = tmino->tmino_aff[y][x];
	  y -= 1;
	  i += 1;
	}
      x += 1;
      j += 1;
    }
}

void		copy_tab_for_rotation(t_tetrimino *tmino)
{
  int		x;
  int		y;

  y = 0;
  while (y < tmino->size_max)
    {
      x = 0;
      while (x < tmino->size_max)
	{
	  if (x < tmino->width && y < tmino->height)
	    tmino->tmino_aff[y][x] = tmino->tmino[y][x];
	  else
	    tmino->tmino_aff[y][x] = 0;
	  x += 1;
	}
      y += 1;
    }
}

void		copy_rotation_to_tab(t_tetrimino *tmino)
{
  int		x;
  int		y;

  y = 0;
  while (y < tmino->size_max)
    {
      x = 0;
      while (x < tmino->size_max)
	{
	  tmino->tmino_aff[y][x] = tmino->tmino_rot[y][x];
	  x += 1;
	}
      y += 1;
    }
}

void		set_piece(t_tetrimino *tmino)
{
  int		i;
  int		max;

  copy_tab_for_rotation(tmino);
  if (tmino->rot % 4)
    {
      max = tmino->size_max;
      i = 0;
      while (i < (tmino->rot % 4))
	{
	  rotate_piece(tmino, max);
	  copy_rotation_to_tab(tmino);
	  i += 1;
	}
    }
}
