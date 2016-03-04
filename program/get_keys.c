/*
** get_keys.c for tetris in /home/brout_m/RENDU/PSU/PSU_2015_tetris
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri Mar  4 11:56:44 2016 marc brout
** Last update Fri Mar  4 16:08:30 2016 marc brout
*/

#include "program.h"
#include "my.h"

int	keyleft(t_start *start, char **av, int *i, char arg)
{
  free(start->kl);
  if (!arg)
    {
      if (!av[*i + 1] || av[*i + 1][0] == '-' ||
	  !(start->kl = my_strdup(av[*i + 1])))
	return (1);
      *i += 1;
    }
  else
    {
      if (!av[*i][11] || !(start->kl = my_strdup(&av[*i][11])))
	return (1);
    }
  return (0);
}

int	keyright(t_start *start, char **av, int *i, char arg)
{
  free(start->kr);
  if (!arg)
    {
      if (!av[*i + 1] || av[*i + 1][0] == '-' ||
	  !(start->kr = my_strdup(av[*i + 1])))
	return (1);
      *i += 1;
    }
  else
    {
      if (!av[*i][12] || !(start->kr = my_strdup(&av[*i][12])))
	return (1);
    }
  return (0);
}

int	keyturn(t_start *start, char **av, int *i, char arg)
{
  free(start->kt);
  if (!arg)
    {
      if (!av[*i + 1] || av[*i + 1][0] == '-' ||
	  !(start->kt = my_strdup(av[*i + 1])))
	return (1);
      *i += 1;
    }
  else
    {
      if (!av[*i][11] || !(start->kt = my_strdup(&av[*i][11])))
	return (1);
    }
  return (0);
}

int	keydrop(t_start *start, char **av, int *i, char arg)
{
  free(start->kd);
  if (!arg)
    {
      if (!av[*i + 1] || av[*i + 1][0] == '-' ||
	  !(start->kd = my_strdup(av[*i + 1])))
	return (1);
      *i += 1;
    }
  else
    {
      if (!av[*i][11] || !(start->kd = my_strdup(&av[*i][11])))
	return (1);
    }
  return (0);
}

int	keyquit(t_start *start, char **av, int *i, char arg)
{
  free(start->kq);
  if (!arg)
    {
      if (!av[*i + 1] || av[*i + 1][0] == '-' ||
	  !(start->kq = my_strdup(av[*i + 1])))
	return (1);
      *i += 1;
    }
  else
    {
      if (!av[*i][11] || !(start->kq = my_strdup(&av[*i][11])))
	return (1);
    }
  return (0);
}
