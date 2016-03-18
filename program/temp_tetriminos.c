/*
** temp_tetriminos.c for tetris in ~/RENDU/PSU/PSU_2015_tetris/program
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu Mar 17 11:19:44 2016 marc brout
** Last update Thu Mar 17 22:08:14 2016 marc brout
*/

#include "program.h"

void	       my_bzero(void *data, int size)
{
  char		*tmp;
  int		i;

  if (!data)
    return ;
  tmp = (char *)data;
  i = 0;
  while (i < size)
    {
      tmp[i] = 0;
      i += 1;
    }
}

void		copy_rotation_tabs(t_tetrimino *tmino)
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

int		init_rotation_tabs(t_tetrimino *tmino)
{
  int		max;
  int		i;

  max = tmino->size_max;
  if (!(tmino->tmino_aff = malloc(sizeof(int *) * (max + 1))) ||
      !(tmino->tmino_rot = malloc(sizeof(int *) * (max + 1))))
    return (1);
  i = 0;
  while (i < max)
    {
      if (!(tmino->tmino_aff[i] = malloc(sizeof(int) * (max + 1))) ||
	  !(tmino->tmino_rot[i] = malloc(sizeof(int) * (max + 1))))
	return (1);
      my_bzero(tmino->tmino_aff[i], sizeof(int) * (max + 1));
      my_bzero(tmino->tmino_rot[i], sizeof(int) * (max + 1));
      i += 1;
    }
  return (0);
}
