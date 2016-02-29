/*
** main.c for tetris in /home/brout_m/RENDU/PSU/PSU_2015_tetris/program
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Fri Feb 26 16:23:36 2016 marc brout
** Last update Mon Feb 29 20:37:19 2016 marc brout
*/

#include <stdio.h>
#include "program.h"

int		main(int ac, UNUSED char **av, UNUSED char **env)
{
  t_program	prog;

  if (ac == 1)
    if (!(prog.tminos = load_tetriminos("./tetriminos", &prog.nb_tminos)))
      return (1);
  debug_tetriminos_list(prog.tminos, prog.nb_tminos);
  free_list(prog.tminos);
  return (0);
}