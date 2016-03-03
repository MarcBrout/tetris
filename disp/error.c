/*
** error.c for tetris in /home/brout_m/RENDU/PSU/PSU_2015_tetris/program
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu Feb 25 17:40:23 2016 marc brout
** Last update Thu Feb 25 20:29:53 2016 benjamin duhieu
*/

#include <unistd.h>
#include "disp.h"

int		my_puterror(const char *str, int error)
{
  write(2, str, my_strlen(str));
  return (error);
}
