/*
** error.c for tetris in /home/brout_m/RENDU/PSU/PSU_2015_tetris/program
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu Feb 25 17:40:23 2016 marc brout
** Last update Mon Feb 29 18:28:30 2016 marc brout
*/

#include <unistd.h>
#include "program.h"

int		my_puterror(const char *str, int error)
{
  write(2, str, my_strlencst(str));
  return (error);
}

void		*my_puterror_null(const char *str)
{
  write(2, str, my_strlencst(str));
  return (NULL);
}
