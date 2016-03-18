/*
** get_hight_score.c for tetris in ~/RENDU/PSU/PSU_2015_tetris/program
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu Mar 17 11:04:39 2016 marc brout
** Last update Fri Mar 18 17:58:21 2016 marc brout
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
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
      tetris->hscore[i].name = my_strdup("UNKNWON");
      tetris->hscore[i].score = 0;
      i += 1;
    }
}

void		tri_high_scores(t_program *tetris)
{
  t_hscore	tmp;
  int		i;
  char		swap;

  swap = 1;
  while (swap)
    {
      i = 0;
      swap = 0;
      while (i < 9)
	{
	  if (tetris->hscore[i].score < tetris->hscore[i + 1].score)
	    {
	      tmp.name = tetris->hscore[i].name;
	      tmp.score = tetris->hscore[i].score;
	      tetris->hscore[i].name = tetris->hscore[i + 1].name;
	      tetris->hscore[i].score = tetris->hscore[i + 1].score;
	      tetris->hscore[i + 1].name = tmp.name;
	      tetris->hscore[i + 1].score = tmp.score;
	      swap = 1;
	    }
	  i += 1;
	}
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
  while ((str = get_next_line(fd)))
    free(str);
  tri_high_scores(tetris);
  return (1);
}

void		my_putnbr_tofd(int nb, int fd)
{
  int		power;
  int		stock;
  char		c;

  power = 1;
  if (nb < 0)
    {
      write(fd, "-", 1);
      nb = -nb;
    }
  stock = nb;
  while ((nb / 10) > 0)
    {
      power *= 10;
      nb /= 10;
    }
  while ((power / 10) > 0)
    {
      c = (stock / power) + 48;
      write(fd, &c, 1);
      stock = stock - ((stock / power) * power);
      power /= 10;
    }
  c = (stock % power) + 48;
  write(fd, &c, 1);
}

int		save_high_scores(t_program *tetris)
{
  int		fd;
  int		i;

  if ((fd = open("./tetriminos/highscores", O_RDWR | O_CREAT | O_TRUNC,
		 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) < 0)
    return (1);
  i = 0;
  while (i < 10)
    {
      if (tetris->hscore[i].name)
	write(fd, tetris->hscore[i].name,
	      my_strlen(tetris->hscore[i].name));
      else
	write(fd, "UNKNOWN", 7);
      write(fd, "\n", 1);
      my_putnbr_tofd(tetris->hscore[i].score, fd);
      write(fd, "\n", 1);
      i += 1;
    }
  return (0);
}
