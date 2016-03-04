/*
** main.c for tetris in /home/duhieu_b/System_unix/PSU_2015_tetris/program
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Feb 26 16:23:36 2016 marc brout
** Last update Fri Mar  4 17:31:43 2016 benjamin duhieu
*/

#include "program.h"
#include "my.h"

void		show_start(t_start *start, t_program *prog)
{
  my_printf("*** DEBUG MODE ***\n");
  my_printf("Key Left : %s\n", start->kl);
  my_printf("Key Right : %s\n", start->kr);
  my_printf("Key Turn : %s\n", start->kt);
  my_printf("Key Drop : %s\n", start->kd);
  my_printf("Key Quit : %s\n", start->kq);
  my_printf("Key Pause : %s\n", start->kp);
  (start->hide) ? my_printf("Next : Yes\n") : my_printf("Next : No\n");
  my_printf("Level : %d\n", start->level);
  my_printf("Size : %d*%d\n", start->row, start->col);
  debug_tetriminos_list(prog->tminos, prog->nb_tminos);
}

int		main(int ac, char **av, UNUSED char **env)
{
  t_program	prog;
  int		ret;

  if (init_start(&prog.start) ||
      !(prog.tminos = load_tetriminos("./tetriminos", &prog.nb_tminos)))
    return (1);
  if (ac > 1)
    {
      if ((ret = parse_args(&prog, (const char **)av)) == 1)
	return (1);
      else if (ret == 2)
	return (0);
    }
  /* my_printf("%d\n", KEY_RIGHT); */
  tri_tetriminos(prog.tminos);
  if (prog.start.debug)
    show_start(&prog.start, &prog);
  purify_tetriminos(prog.tminos);
  prog.piece = 0;
  /* my_disp(&prog); */
  free_list(prog.tminos);
  return (0);
}
