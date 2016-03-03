/*
** main.c for tetris in /home/duhieu_b/System_unix/PSU_2015_tetris/program
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Thu Mar  3 10:12:03 2016 benjamin duhieu
** Last update Thu Mar  3 10:25:48 2016 benjamin duhieu
*/

#include "program.h"

int		main(int ac, UNUSED char **av, UNUSED char **env)
{
  t_program	prog;

  if (ac == 1)
    if (!(prog.tminos = load_tetriminos("./tetriminos", &prog.nb_tminos)))
      return (1);
  debug_tetriminos_list(prog.tminos, prog.nb_tminos);
  my_disp(&prog);
  free_list(prog.tminos);
  return (0);
}
