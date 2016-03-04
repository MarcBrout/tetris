/*
** main.c for main in /home/duhieu_b/System_unix
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Thu Feb 25 16:57:52 2016 benjamin duhieu
** Last update Thu Mar  3 19:44:18 2016 benjamin duhieu
*/

#include <ncurses.h>
#include <stdlib.h>
#include <curses.h>
#include <time.h>
#include <unistd.h>
#include "disp.h"
#include "program.h"

int		my_disp(t_program *tetris)
{
  int		x_max;
  int		y_max;

  srand(time(NULL));
  tetris->tet.play.high_score = 0;
  tetris->tet.play.score = 0;
  tetris->tet.play.line = 0;
  tetris->tet.play.level = 0;
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
