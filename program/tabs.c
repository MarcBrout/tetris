/*
** tabs.c for tetris in /home/brout_m/RENDU/PSU/PSU_2015_tetris
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu Feb 25 19:55:42 2016 marc brout
** Last update Thu Feb 25 20:03:07 2016 marc brout
*/

#include "program.h"

int			**tab(t_tetriminos		*tmino)
{
  int			**tab;
  int			i;
  int			j;

  if (!(tab = malloc(sizeof(int *) * (tmino->height + 1))))
    return (NULL);
  i = -1;
  while (++i < tmino->height)
    {
      j = -1;
      if (!(tab[i] = malloc(sizeof(int) * (tmino->width + 1))))
	    return (NULL);
      while (++j < tmino->width)
	tab[i][j] = 0;
      tab[i][j] = -1;
    }
  tab[i] = NULL;
  return (tab);
}

void			fill_tab(t_tetriminos		*tmino,
				 int			color,
				 int			fd)
{
  int			i;
  int			j;
  char			*tmp;

  i = -1;
  while (++i < tmino->height)
    {
      j = -1;
      if (tmp = my_
      while
    }
}
