/*
** tri.c for tetris in /home/brout_m/RENDU/PSU/PSU_2015_tetris/program
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Tue Mar  1 13:33:50 2016 marc brout
** Last update Fri Mar 18 17:07:59 2016 marc brout
*/

#include "program.h"
#include "my.h"

void			swap_tetriminos(t_tetrimino *current,
					t_tetrimino *current_prev,
					t_tetrimino *target)
{
  current_prev->next = target;
  current->next = target->next;
  target->next = current;
}

void			tri_tetriminos(t_tetrimino *root)
{
  t_tetrimino		*prec;
  t_tetrimino		*first;
  t_tetrimino		*start;
  int			tri;

  tri = 1;
  while (tri)
    {
      start = root;
      prec = start;
      first = start->next;
      tri = 0;
      while (first && first->next)
	{
	  if (my_strcmp((char *)first->name, (char *)first->next->name)
	      > 0)
	    {
	      swap_tetriminos(first, prec, first->next);
	      tri = 1;
	    }
	  prec = first;
	  first = first->next;
	}
    }
}

int		purify_tetriminos(t_tetrimino *root,
				  t_program *tetris)
{
  int		nb;
  t_tetrimino	*tmp;
  t_tetrimino	*prev;

  tmp = root->next;
  prev = root;
  nb = 0;
  while (tmp)
    {
      if (!tmp->working || tmp->width > tetris->start.col ||
	  tmp->height > tetris->start.row)
	{
	  nb += 1;
	  prev->next = tmp->next;
	  free((char *)tmp->name);
	  free_tab(tmp->tmino, tmp->height);
	  free(tmp);
	  tmp = prev;
	}
      if (tmp != root && init_rotation_tabs(tmp))
	return (-1);
      prev = tmp;
      tmp = tmp->next;
    }
  return (nb);
}
