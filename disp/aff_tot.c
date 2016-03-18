/*
** aff_tot.c for tot in /home/duhieu_b/System_unix/PSU_2015_tetris/disp
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Thu Mar  3 10:44:16 2016 benjamin duhieu
** Last update Fri Mar 18 21:20:23 2016 marc brout
*/

#include <ncurses.h>
#include <curses.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include "program.h"
#include "my.h"

int	game(t_program *tetr, t_tetrimino *tet, int i)
{
  int	(*key_tab[6])(t_program *, t_tetrimino *);
  int	recup;
  char	*touch;

  werase(tetr->tet.board.game);
  wborder(tetr->tet.board.game, '|', '|', '-', '-', '-', '-', '-', '-');
  init_tab(key_tab);
  if (!tetr->piece)
    {
      init_piece(tetr, tet, &tetr->posit);
      display_to_board(tetr);
    }
  else if (tetr->piece == 1)
    {
      set_piece(tet);
      if ((touch = recup_entry(tetr)))
	if ((recup = is_it_a_key(tetr->start.keys, touch)) >= 0)
	  if (key_tab[recup](tetr, tet))
	    return (-1);
      if ((recup = display_piece(tetr, tet, i)) == -1)
      	return (-1);
      if (recup > 0)
      	return (1);
    }
  return (0);
}

int		draw(t_program *tetris, time_t init, int i)
{
  time_t	new_time;
  t_tetrimino	*tmp;
  int		chk;
  static int	next = -1;

  if ((new_time = (time(NULL) - tetris->pause)) == -1)
    return (-1);
  change_score(tetris, new_time, init);
  if (!(tmp = next_form(tetris, &next)))
    return (-1);
  else
    next = 1;
  wrefresh(tetris->tet.next.game);
  if ((chk = game(tetris, tmp, i)) == -1)
    return (1);
  if (chk > 0)
    next = 0;
  wrefresh(tetris->tet.board.game);
  return (0);
}

int		the_game(t_program *tet, time_t init, int y, int i)
{
  int		chk;

  if ((chk = draw(tet, init, i)) == -1)
    return (1);
  if (chk > 0)
    {
      clear();
      replace_high_scores(tet, tet->start.name, tet->tet.play.score);
      tet->tet.over.x_max = 20;
      tet->tet.over.y_max = 12;
      if ((tet->tet.over.game =
	   newwin(tet->tet.over.y_max, tet->tet.over.x_max, 8, 1))
	  == NULL)
	return (my_puterror("Error : Can't create the game \
over window\n", 1));
      while (!(game_over(tet, y)));
      reset_terminal_to_default(&tet->oldt);
      endwin();
      return (-1);
    }
  return (0);
}

int		disp(t_program *tetris, int x_max, int y_max)
{
  time_t	init;
  int		chk;
  int		y;
  int		i;

  init = 0;
  tetris->speed = 15;
  i = 0;
  if ((init = init_game(tetris, x_max, y_max, init)) == -1)
    return (1);
  while (1)
    {
      if ((y = chk_window(tetris)) == -1)
	return (1);
      if ((chk = the_game(tetris, init, y, i)) == -1)
	return (0);
      if (chk > 0)
	return (1);
      i++;
      usleep(500);
    }
  clear();
  reset_terminal_to_default(&tetris->oldt);
  endwin();
  return (0);
}
