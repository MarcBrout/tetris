/*
** get_pause.c for tetris in /home/brout_m/RENDU/PSU/PSU_2015_tetris
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri Mar  4 13:18:17 2016 marc brout
** Last update Fri Mar  4 16:25:01 2016 marc brout
*/

#include "program.h"
#include "my.h"

int	help(UNUSED t_start *start, UNUSED char **av,
	     UNUSED int *i, UNUSED char arg)
{
  display_help();
  return (2);
}

int	keypause(t_start *start, char **av, int *i, char arg)
{
  free(start->kp);
  if (!arg)
    {
      if (!av[*i + 1] || av[*i + 1][0] == '-' ||
	  !(start->kp = my_strdup(av[*i + 1])))
	return (1);
      *i += 1;
    }
  else
    {
      if (!av[*i][12] || !(start->kp = my_strdup(&av[*i][12])))
	return (1);
    }
  return (0);
}
