/*
** get_hight_score.c for tetris in ~/RENDU/PSU/PSU_2015_tetris/program
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu Mar 17 11:04:39 2016 marc brout
** Last update Thu Mar 17 13:03:08 2016 marc brout
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "program.h"
#include "my.h"

void		init_high_scores(t_program *tetris)
{
  int		i;

  i = 0;
  while (i < 10)
    {
      tetris->hscore[i].name = NULL;
      tetris->hscore[i].score = 0;
      i += 1;
    }
}

int		load_high_scores(t_program *tetris)
{
  int		fd;
  int		i;
  char		*str;

  init_high_scores(tetris);
  if ((fd = open("./tetriminos/highscores", O_RDONLY)) < 0)
    return (0);
  i = 0;
  while (i < 10)
    {
      if (!(tetris->hscore[i].name = get_next_line(fd)))
	break;
      if (!(str = get_next_line(fd)))
	break;
      tetris->hscore[i].score = my_getnbrcst((const char *)str);
      i += 1;
      free(str);
    }
  return (1);
}
