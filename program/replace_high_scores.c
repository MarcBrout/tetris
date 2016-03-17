/*
** replace_high_scores.c for tetris in ~/RENDU/PSU/PSU_2015_tetris/program
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu Mar 17 17:45:37 2016 marc brout
** Last update Thu Mar 17 17:50:55 2016 marc brout
*/

#include "program.h"

void	replace_high_scores(t_program *tetris,
			    char *name,
			    int score)
{
  int	i;

  i = 9;
  if (tetris->hscore[9].name)
    free(tetris->hscore[9].name);
  while (i > 0)
    {
      tetris->hscore[i].name = tetris->hscore[i - 1].name;
      tetris->hscore[i].score = tetris->hscore[i - 1].score;
      i -= 1;
    }
  tetris->hscore[0].name = name;
  tetris->hscore[0].score = score;
}
