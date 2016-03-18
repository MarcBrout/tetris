/*
** verif.c for verif in /home/duhieu_b/Unix/PSU_2015_tetris
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Mar 18 16:09:20 2016 benjamin duhieu
** Last update Fri Mar 18 17:04:23 2016 benjamin duhieu
*/

#include <ncurses.h>
#include <curses.h>
#include <time.h>
#include "program.h"

int	init_game(t_program *tetris, int x_max, int y_max, time_t init)
{
  if ((init = time(NULL)) == -1)
    return (-1);
  tetris->pause = 0;
  initscr();
  keypad(stdscr, true);
  set_escdelay(0);
  noecho();
  curs_set(0);
  if (create_win(tetris, &tetris->tet, x_max, y_max))
    return (-1);
  if (malloc_game(tetris, &tetris->tet))
    return (-1);
  if (malloc_next(&tetris->tet, x_max, y_max))
    return (-1);
  text();
  set_no_canonique_no_wait(&tetris->oldt, &tetris->newt);
  return (init);
}

int		chk_window(t_program *tetris)
{
  int	x;
  int	y;

  getmaxyx(stdscr, y, x);
  if (x <= 41 + tetris->tet.board.x_max + tetris->tet.next.x_max ||
      y <= 2 + tetris->tet.board.y_max)
    return (-1);
  wrefresh(stdscr);
  return (y);
}
