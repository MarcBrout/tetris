/*
** main.c for tetris in /home/duhieu_b/System_unix/PSU_2015_tetris/program
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Feb 26 16:23:36 2016 marc brout
** Last update Sat Mar  5 18:26:52 2016 marc brout
*/

#include <curses.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "program.h"
#include "my.h"

int			read_non_canonique()
{
  struct termios	oldt;
  struct termios	newt;
  char			c;

  if (ioctl(0, TCGETS, &oldt) < 0 ||
      ioctl(0, TCGETS, &newt) < 0)
    return (1);;
  newt.c_lflag &= ~ICANON;
  newt.c_lflag &= ~ECHO;
  newt.c_cc[VMIN] = 1;
  if (ioctl(0, TCSETS, &newt) < 0 ||
      read(0, &c, 1) < 0 || (c = 0) ||
      ioctl(0, TCSETS, &oldt) < 0)
    return (1);
  return (0);
}

int		show_start(t_start *start, t_program *prog)
{
  my_printf("*** DEBUG MODE ***\n");
  my_printf("Key Left : %s\n", start->keys[K_LEFT]);
  my_printf("Key Right : %s\n", start->keys[K_RIGHT]);
  my_printf("Key Turn : %s\n", start->keys[K_TURN]);
  my_printf("Key Drop : %s\n", start->keys[K_DROP]);
  my_printf("Key Quit : %s\n", start->keys[K_QUIT]);
  my_printf("Key Pause : %s\n", start->keys[K_PAUSE]);
  (start->hide) ? my_printf("Next : Yes\n") : my_printf("Next : No\n");
  my_printf("Level : %d\n", start->level);
  my_printf("Size : %d*%d\n", start->row, start->col);
  debug_tetriminos_list(prog->tminos, prog->nb_tminos);
  return (read_non_canonique());
}

int		launch_tetris(t_program *prog)
{
  if (!(prog->tminos =
	load_tetriminos("./tetriminos", &prog->nb_tminos)))
    return (1);
  keypad(stdscr, TRUE);
  tri_tetriminos(prog->tminos);
  if (prog->start.debug)
    show_start(&prog->start, prog);
  purify_tetriminos(prog->tminos);
  prog->piece = 0;
  my_disp(prog);
  free_list(prog->tminos);
  keypad(stdscr, FALSE);
  return (0);
}

int		main(int ac, char **av,char **env)
{
  t_program	prog;
  int		ret;

  if (!env[0] || my_set_term(env) || init_start(&prog.start))
    return (1);
  if (ac > 1)
    {
      if ((ret = parse_args(&prog, (const char **)av)))
	return (ret % 2);
    }
  launch_tetris(&prog);
  return (0);
}
