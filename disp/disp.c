/*
** main.c for main in /home/duhieu_b/System_unix
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Thu Feb 25 16:57:52 2016 benjamin duhieu
** Last update Sat Mar 19 00:53:42 2016 marc brout
*/

#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include <time.h>
#include <unistd.h>
#include "disp.h"
#include "program.h"
#include "my.h"
#include "get_next_line.h"

int		game_over(t_program *tetris, int y)
{
  int	recup;
  char	*touch;

  tab_score(tetris);
  wrefresh(tetris->tet.over.game);
  ga(y);
  me(y);
  ov(y);
  er(y);
  wrefresh(stdscr);
  if ((touch = recup_entry(tetris)))
    if ((recup = is_it_a_key(tetris->start.keys, touch)) == 4)
      return (1);
  return (0);
}

void		init_tet_play(t_program *t)
{
  t->tet.play.high_score = t->hscore[0].score;
  t->tet.play.score = 0;
  t->tet.play.line = 0;
  t->tet.play.level = t->start.level;
  t->tet.play.sec = 0;
  t->tet.play.min = 0;
}

int		my_disp(t_program *t)
{
  int		x_max;
  int		y_max;

  srand(time(NULL));
  my_printf("\nEnter your name (6 characters max): ");
  if ((!(t->start.name = get_next_line(0)) ||
       (my_strlen(t->start.name) > 6) || !t->start.name[0]))
    {
      if (t->start.name)
	free(t->start.name);
      if (!(t->start.name = my_strdup("NONAME")))
	return (1);;
    }
  init_tet_play(t);
  x_max = max_wtetriminos(t->tminos);
  y_max = max_htetriminos(t->tminos);
  if (disp(t, x_max, y_max))
    {
      endwin();
      return (1);
    }
  return (0);
}
