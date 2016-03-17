/*
** free.c for tetris in /home/brout_m/RENDU/PSU/PSU_2015_tetris/program
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Mon Feb 29 20:21:56 2016 marc brout
** Last update Thu Mar 17 16:44:25 2016 marc brout
*/

#include	<stdlib.h>
#include	"program.h"

void		free_keys(t_program *tetris)
{
  int		i;

  i = 0;
  while (i < 6)
    {
      if (tetris->start.keyalloc[i])
	free(tetris->start.keys[i]);
      i = i + 1;
    }
  free(tetris->start.keys);
}

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

void		free_high_score(t_program *tetris)
{
  int		i;

  i = 0;
  while (i < 10)
    {
      if (tetris->hscore[i].name)
	free(tetris->hscore[i].name);
      i += 1;
    }
}

void		free_rot_tab(int **rot_tab, int w, int h)
{
  int		max;
  int		i;

  max = (w > h) ? w : h;
  i = 0;
  while (i < max)
    {
      free(rot_tab[i]);
      i += 1;
    }
  free(rot_tab);
}

void		free_list(t_tetrimino *root)
{
  t_tetrimino	*tmp;
  t_tetrimino	*tmp2;

  tmp2 = root->next;
  while ((tmp = tmp2))
    {
      tmp2 = tmp->next;
      if (tmp->name)
	free((char *)tmp->name);
      free_tab(tmp->tmino, tmp->height);
      free_rot_tab(tmp->tmino_aff, tmp->width, tmp->height);
      free_rot_tab(tmp->tmino_rot, tmp->width, tmp->height);
      free(tmp);
    }
  free(root);
}
