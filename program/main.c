/*
** main.c for tetris in /home/duhieu_b/System_unix/PSU_2015_tetris/program
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Feb 26 16:23:36 2016 marc brout
** Last update Thu Mar 17 17:08:41 2016 marc brout
*/

#include <curses.h>
#include <term.h>
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

void		put_visible_str(char *str)
{
  int		i;

  i = 0;
  while (str && str[i])
    {
      if (str[i] == 27)
	write(1, "^E", 2);
      else if (str[i] == ' ')
	write(1, "(space)", 7);
      else
	write(1, &str[i], 1);
      i += 1;
    }
}

int		show_start(t_start *start, t_program *prog)
{
  my_printf("*** DEBUG MODE ***\n");
  my_printf("Key Left : ");
  put_visible_str(start->keys[K_LEFT]);
  my_printf("\nKey Right : ");
  put_visible_str(start->keys[K_RIGHT]);
  my_printf("\nKey Turn : ");
  put_visible_str(start->keys[K_TURN]);
  my_printf("\nKey Drop : ");
  put_visible_str(start->keys[K_DROP]);
  my_printf("\nKey Quit : ");
  put_visible_str(start->keys[K_QUIT]);
  my_printf("\nKey Pause : ");
  put_visible_str(start->keys[K_PAUSE]);
  (start->hide) ? my_printf("\nNext : Yes\n") : my_printf("\nNext : No\n");
  my_printf("Level : %d\n", start->level);
  my_printf("Size : %d*%d\n", start->row, start->col);
  debug_tetriminos_list(prog->tminos, prog->nb_tminos);
  return (read_non_canonique());
}

int		launch_tetris(t_program *prog)
{

  int		ret;

  prog->start.hide = 1;
  if (!(prog->tminos =
	load_tetriminos("./tetriminos", &prog->nb_tminos)))
    return (1);
  prog->hs = load_high_scores(prog);
  tri_tetriminos(prog->tminos);
  if (prog->start.debug)
    show_start(&prog->start, prog);
  if ((ret = purify_tetriminos(prog->tminos)) < 0)
    return (1);
  prog->nb_tminos -= ret;
  prog->piece = 0;
  /* my_disp(prog); */
  if (save_high_scores(prog))
    return (1);
  free_keys(prog);
  free_high_score(prog);
  free_list(prog->tminos);
  return (0);
}

int		main(int ac, char **av,char **env)
{
  TERMINAL	*term;
  t_program	prog;
  int		ret;

  if (!env[0] || my_set_term() || init_start(&prog.start))
    return (1);
  if (ac > 1)
    {
      if ((ret = parse_args(&prog, (const char **)av)))
	return (ret % 2);
    }
  term = set_curterm(cur_term);
  del_curterm(term);
  launch_tetris(&prog);
  return (0);
}
