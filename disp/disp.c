/*
** main.c for main in /home/duhieu_b/System_unix
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Thu Feb 25 16:57:52 2016 benjamin duhieu
** Last update Thu Mar 17 11:49:14 2016 benjamin duhieu
*/

#include <ncurses.h>
#include <stdlib.h>
#include <curses.h>
#include <time.h>
#include <unistd.h>
#include "disp.h"
#include "program.h"
#include "my.h"
#include "get_next_line.h"

int		my_disp(t_program *tetris)
{
  int		x_max;
  int		y_max;

  srand(time(NULL));
  my_printf("\nEnter your name (6 characters max): ");
  while ((!(tetris->start.name = get_next_line(0)) ||
	  (my_strlen(tetris->start.name) > 6) || !tetris->start.name[0]))
    {
      my_printf("\nInvalid Login ...\n");
      my_printf("Please Enter a valid name (6 characters max): ");
    }
  tetris->tet.play.high_score = 0;
  tetris->tet.play.score = 0;
  tetris->tet.play.line = 0;
  tetris->tet.play.level = tetris->start.level;
  tetris->tet.play.sec = 0;
  tetris->tet.play.min = 0;
  x_max = max_wtetriminos(tetris->tminos);
  y_max = max_htetriminos(tetris->tminos);
  if (disp(tetris, x_max, y_max))
    {
      endwin();
      return (1);
    }
  return (0);
}
