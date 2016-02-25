/*
** tabs.c for tetris in /home/brout_m/RENDU/PSU/PSU_2015_tetris
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu Feb 25 19:55:42 2016 marc brout
** Last update Thu Feb 25 20:32:23 2016 marc brout
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

int			fill_line(const char		*str,
				  int			*line,
				  int			width,
				  int			color)
{
  int			i;

  i = -1;
  while (++i < width)
    {
      if (!str[i] || (str && str[i] != '*' && str[i] != ' '))
	return (1);
      else if (str && str[i] == '*')
	line[i] = color;
    }
  if (str[i])
    return (1);
  return (0);
}

void			fill_tab(t_tetriminos		*tmino,
				 int			color,
				 int			fd)
{
  int			i;
  char			*tmp;

  i = -1;
  while (++i < tmino->height)
    {
      if (tmp = get_next_line(fd))
	{
	  if (fill_line(tmp, &tmino->tab[i], tmino->width, color))
	    {
	      tmino->working = 0;
	      break;
	    }
	}
      else
	{
	  tmino->working = 0;
	  break;
	}
      free(tmp);
    }
  if (tmp = get_next_line(fd))
    tmino->working = 0;
}
