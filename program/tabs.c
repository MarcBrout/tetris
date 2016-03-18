/*
** tabs.c for tetris in /home/brout_m/RENDU/PSU/PSU_2015_tetris
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu Feb 25 19:55:42 2016 marc brout
** Last update Fri Mar 18 17:10:13 2016 marc brout
*/

#include <stdio.h>
#include "get_next_line.h"
#include "program.h"

void			free_args(t_args *rootarg)
{
  t_args		*tmp;
  t_args		*tmp2;

  tmp = rootarg->next;
  while (tmp)
    {
      tmp2 = tmp->next;
      if (tmp->arg)
	free(tmp->arg);
      if (tmp->long_arg)
	free(tmp->long_arg);
      free(tmp);
      tmp = tmp2;
    }
}

int			**array(t_tetrimino *tmino)
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

int			fill_line(const char *str, int *line,
				  int width, int color)
{
  int			i;

  i = 0;
  while (i < width)
    {
      if (str && i < my_strlencst(str) &&
	  (str[i] != '*' && str[i] != ' ' && str[i]))
	return (1);
      if (str && i < my_strlencst(str) && str[i] == '*')
	line[i] = color;
      i++;
    }
  while (i < my_strlencst(str))
    {
      if (str[i] && str[i] != ' ')
	return (1);
      i += 1;
    }
  return (0);
}

int			check_empty_col(int **tab, int width,
					int height)
{
  int			x;
  int			y;
  int			pres;

  x = 0;
  while (x < width)
    {
      y = 0;
      pres = 0;
      while (y < height)
	{
	  if (tab[y][x])
	    pres = 1;
	  y += 1;
	}
      if (!pres)
	return (0);
      x += 1;
    }
  return (1);
}

void			fill_tab(t_tetrimino *tm, int color, int fd)
{
  int			i;
  char			*tmp;

  i = -1;
  while (++i < tm->height)
    {
      if ((tmp = get_next_line(fd)))
	{
	  if (fill_line(tmp, tm->tmino[i], tm->width, color))
	    tm->working = 0;
	}
      else
	tm->working = 0;
      free(tmp);
    }
  if (tm->working)
    {
      tm->working = check_empty_col(tm->tmino, tm->width, tm->height);
      tm->working = check_empty_col(tm->tmino, tm->width, tm->height);
    }
  if ((tmp = get_next_line(fd)))
    tm->working = 0;
  free(tmp);
}
