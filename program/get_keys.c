/*
** get_keys.c for tetris in /home/brout_m/RENDU/PSU/PSU_2015_tetris
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri Mar  4 11:56:44 2016 marc brout
** Last update Wed Mar 16 16:40:22 2016 marc brout
*/

#include "program.h"
#include "my.h"

int	keyleft(t_start *start, char **av, int *i, char arg)
{
  if (!arg)
    {
      if (!av[*i + 1] || !av[*i + 1][0] || av[*i + 1][0] == '-' ||
	  !(start->keys[K_LEFT] = my_strdup(av[*i + 1])))
	return (1);
      *i += 1;
    }
  else
    {
      if (!av[*i][11] || !(start->keys[K_LEFT] =
			   my_strdup(&av[*i][11])))
	return (1);
    }
  return (0);
}

int	keyright(t_start *start, char **av, int *i, char arg)
{
  if (!arg)
    {
      if (!av[*i + 1] || !av[*i + 1][0] || av[*i + 1][0] == '-' ||
	  !(start->keys[K_RIGHT] = my_strdup(av[*i + 1])))
	return (1);
      *i += 1;
    }
  else
    {
      if (!av[*i][12] || !(start->keys[K_RIGHT] =
			   my_strdup(&av[*i][12])))
	return (1);
    }
  return (0);
}

int	keyturn(t_start *start, char **av, int *i, char arg)
{
  if (!arg)
    {
      if (!av[*i + 1] || !av[*i + 1][0] || av[*i + 1][0] == '-' ||
	  !(start->keys[K_TURN] = my_strdup(av[*i + 1])))
	return (1);
      *i += 1;
    }
  else
    {
      if (!av[*i][11] || !(start->keys[K_TURN] =
			   my_strdup(&av[*i][11])))
	return (1);
    }
  return (0);
}

int	keydrop(t_start *start, char **av, int *i, char arg)
{
  if (!arg)
    {
      if (!av[*i + 1] || !av[*i + 1][0] || av[*i + 1][0] == '-' ||
	  !(start->keys[K_DROP] = my_strdup(av[*i + 1])))
	return (1);
      *i += 1;
    }
  else
    {
      if (!av[*i][11] || !(start->keys[K_DROP] =
			   my_strdup(&av[*i][11])))
	return (1);
    }
  return (0);
}

int	keyquit(t_start *start, char **av, int *i, char arg)
{
  if (!arg)
    {
      if (!av[*i + 1] || !av[*i + 1][0] || av[*i + 1][0] == '-' ||
	  !(start->keys[K_QUIT] = my_strdup(av[*i + 1])))
	return (1);
      *i += 1;
    }
  else
    {
      if (!av[*i][11] || !(start->keys[K_QUIT] =
			   my_strdup(&av[*i][11])))
	return (1);
    }
  return (0);
}
