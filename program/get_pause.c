/*
** get_pause.c for tetris in /home/brout_m/RENDU/PSU/PSU_2015_tetris
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri Mar  4 13:18:17 2016 marc brout
** Last update Wed Mar 16 13:07:07 2016 marc brout
*/

#include "program.h"
#include "my.h"

int	help(UNUSED t_start *start, char **av,
	     UNUSED int *i, UNUSED char arg)
{
  display_help(av);
  return (2);
}

int	keypause(t_start *start, char **av, int *i, char arg)
{
  free(start->keys[K_PAUSE]);
  if (!arg)
    {
      if (!av[*i + 1] || av[*i + 1][0] == '-' ||
	  !(start->keys[K_PAUSE] = my_strdup(av[*i + 1])))
	return (1);
      *i += 1;
    }
  else
    {
      if (!av[*i][12] || !(start->keys[K_PAUSE] =
			   my_strdup(&av[*i][12])))
	return (1);
    }
  return (0);
}
