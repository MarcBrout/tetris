/*
** rotate.c for tetris in /home/brout_m/RENDU/PSU/PSU_2015_tetris
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu Mar 17 17:55:54 2016 marc brout
** Last update Thu Mar 17 21:25:15 2016 marc brout
*/

#include "program.h"



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
  while (y < tmino->height)
    {
      x = 0;
      while (x < tmino->width)
	{
	  tmino->tmino_aff[y][x] = tmino->tmino[y][x];
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
  while (y < tmino->height)
    {
      x = 0;
      while (x < tmino->width)
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
  max = (tmino->width > tmino->height) ? tmino->width : tmino->height;
  i = 0;
  while (i < tmino->rot)
    {
      rotate_piece(tmino, max);
      i += 1;
    }
  copy_rotation_to_tab(tmino);
}
