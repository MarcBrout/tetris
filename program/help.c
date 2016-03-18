/*
** help.c for tetris in /home/brout_m/RENDU/PSU/PSU_2015_tetris
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu Mar  3 13:15:17 2016 marc brout
** Last update Fri Mar 18 15:43:59 2016 marc brout
*/

#include "program.h"
#include "my.h"

int		level(t_start *start, char **av,
		      int *i, char arg)
{
  if (!arg)
    {
      if (!av[*i + 1] || av[*i + 1][0] == '-' ||
	  (start->level = my_getnbr(av[*i + 1])) <= 0)
	return (1);
      *i += 1;
      return (0);
    }
  if (!av[*i][8] || (start->level = my_getnbr(&av[*i][8])) <= 0)
    return (1);
  return (0);
}

int		mapsize(t_start *start, char **av,
			int *i, UNUSED char arg)
{
  int		c;

  c = 0;
  if (!av[*i][11] ||
      (start->row = my_getnbr_i(&av[*i][11], &c)) <= 0 ||
      !av[*i][11 + ++c] ||
      (start->col = my_getnbr_i(&av[*i][11], &c)) <= 0)
    return (1);
  return (0);
}

int		withoutnext(t_start *start, UNUSED char **av,
			    UNUSED int *i, UNUSED char arg)
{
  start->hide = 1;
  return (0);
}

int		debugmode(t_start *start, UNUSED char **av,
			  UNUSED int *i, UNUSED char arg)
{
  start->debug = 1;
  return (0);
}

void		display_help(char **av)
{
  my_printf("Usage: %s [options]\n", av[0]);
  my_printf("Options:\n");
  my_printf("--help Display this help\n");
  my_printf("-l --level={num} Start Tetris at level num\n");
  my_printf("-kl --key-left={K} Move tetrimino on LEFT with key K\n");
  my_printf("-kr --key-right={K} Move tetrimino on RIGHT with key K\n");
  my_printf("-kt --key-turn={K} Turn tetrimino with key K\n");
  my_printf("-kd --key-drop={K} Set default DROP on key K\n");
  my_printf("-kq --key-quit={K} Quit Program when press key K\n");
  my_printf("-kp --key-pause={K} Pause and restart game  when press key K\n");
  my_printf("--map-size={row,col} Set game size at row, col\n");
  my_printf("-w --without-next Hide next tetrimino\n");
  my_printf("-d --debug Debug mode\n");
}
