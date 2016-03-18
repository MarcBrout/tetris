/*
** debug.c for tetris in /home/brout_m/RENDU/PSU/PSU_2015_tetris/program
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri Feb 26 17:19:32 2016 marc brout
** Last update Fri Mar 18 17:10:14 2016 marc brout
*/

#include <unistd.h>
#include "program.h"
#include "my.h"

void		debug_tetriminos_list(t_tetrimino *tminos,
				      int nb_tminos)
{
  int		i;
  t_tetrimino	*tmp;

  i = -1;
  my_printf("Tetriminos : %d\n", nb_tminos);
  tmp = tminos->next;
  while (++i < nb_tminos && tmp)
    {
      if (tmp->working)
	debug_working_tetrimino(tmp);
      else
	debug_not_working_tetrimino(tmp);
      tmp = tmp->next;
    }
  my_printf("Press a key to start Tetris\n");
}

int		check_another_star(int **tmino, int y, int x, int w)
{
  int		i;

  i = 0;
  while (x + i < w)
    {
      if (tmino[y][x + i])
	return (1);
      i += 1;
    }
  return (0);
}

void		debug_working_tetrimino(t_tetrimino *tmino)
{
  int		x;
  int		y;

  y = 0;
  my_printf("Tetriminos : Name %s : Size %d*%d : Color %d :\n",
	    tmino->name, tmino->width, tmino->height, tmino->color);
  while (y < tmino->height)
    {
      x = 0;
      while (x < tmino->width)
	{
	  if (check_another_star(tmino->tmino, y, x, tmino->width))
	    {
	      if (tmino->tmino[y][x])
		write(1, "*", 1);
	      else
		write(1, " ", 1);
	      x += 1;
	    }
	  else
	    break ;
	}
      write(1, "\n", 1);
      y += 1;
    }
}

void		debug_not_working_tetrimino(t_tetrimino *tmino)
{
  my_printf("Tetriminos : Name %s : Error\n", tmino->name);
}
