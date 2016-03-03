/*
** misc.c for tetris in /home/brout_m/RENDU/PSU/PSU_2015_tetris/program
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu Feb 25 17:43:44 2016 marc brout
** Last update Thu Feb 25 20:31:37 2016 benjamin duhieu
*/

#include "disp.h"

int	my_strlen(const char *str)
{
  int	i;

  i = 0;
  while (str && str[i])
    i++;
  return (i);
}
