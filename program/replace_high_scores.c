/*
** replace_high_scores.c for tetris in ~/PSU/PSU_2015_tetris/program
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu Mar 17 17:45:37 2016 marc brout
** Last update Fri Mar 18 20:59:32 2016 marc brout
*/

#include <stdio.h>
#include "program.h"

int	is_high_score(t_program *tetris, int score)
{
  int	i;

  i = 0;
  while (i < 10)
    {
      if (score >= tetris->hscore[i].score)
	return (i);
      i += 1;
    }
  return (-1);
}

void	replace_high_scores(t_program *tetris,
			    char *name,
			    int score)
{
  int	pos;
  int	i;

  if ((pos = is_high_score(tetris, score)) >= 0)
    {
      i = 9;
      if (tetris->hscore[9].name)
	free(tetris->hscore[9].name);
      while (i > pos)
	{
	  tetris->hscore[i].name = tetris->hscore[i - 1].name;
	  tetris->hscore[i].score = tetris->hscore[i - 1].score;
	  i -= 1;
	}
      tetris->hscore[pos].name = name;
      tetris->hscore[pos].score = score;
    }
  else
    free(name);
}
