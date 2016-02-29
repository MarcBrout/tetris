/*
** free.c for tetris in /home/brout_m/RENDU/PSU/PSU_2015_tetris/program
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Feb 29 20:21:56 2016 marc brout
** Last update Mon Feb 29 20:36:34 2016 marc brout
*/

#include	<stdlib.h>
#include	"program.h"

void		free_tab(int **tab, int height)
{
  int		i;

  i = 0;
  while (i < height)
    {
      free(tab[i]);
      i += 1;
    }
  free(tab);
}

void		free_list(t_tetrimino *root)
{
  t_tetrimino	*tmp;
  t_tetrimino	*tmp2;

  tmp = root->next;
  while (tmp)
    {
      tmp2 = tmp->next;
      if (tmp->name)
	free((char *)tmp->name);
      free_tab(tmp->tmino, tmp->height);
      free(tmp);
      tmp = tmp2;
    }
  free(root);
}
