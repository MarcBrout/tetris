/*
** aff_tot.c for tot in /home/duhieu_b/System_unix/PSU_2015_tetris/disp
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Thu Mar  3 10:44:16 2016 benjamin duhieu
** Last update Fri Mar 18 16:19:10 2016 benjamin duhieu
*/

#include <ncurses.h>
#include <curses.h>
#include <unistd.h>
#include <time.h>
#include "program.h"
#include "my.h"

int	game(t_program *tetris, t_tetrimino *tet)
{
  int	(*key_tab[6])(t_program *, t_tetrimino *);
  int	recup;
  char	*touch;

  werase(tetris->tet.board.game);
  wborder(tetris->tet.board.game, '|', '|', '-', '-', '-', '-', '-','-');
  init_tab(key_tab);
  if (!tetris->piece)
    {
      init_piece(tetris, tet, &tetris->posit);
      display_to_board(tetris);
    }
  else if (tetris->piece == 1)
    {
      set_piece(tet);
      if ((touch = recup_entry(tetris)))
	if ((recup = is_it_a_key(tetris->start.keys, touch)) >= 0)
	  if (key_tab[recup](tetris, tet))
	    return (-1);
      if ((recup = display_piece(tetris, tet)) == -1)
      	return (-1);
      if (recup > 0)
      	return (1);
    }
  return (0);
}


int		draw(t_program *tetris, time_t init)
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
  if ((chk = game(tetris, tmp)) == -1)
    return (1);
  if (chk > 0)
    next = 0;
  wrefresh(tetris->tet.board.game);
  return (0);
}

int		the_game(t_program *tetris, time_t init, int y)
{
  int		chk;

  if ((chk = draw(tetris, init)) == -1)
    return (1);
  if (chk > 0)
    {
      clear();
      replace_high_scores(tetris, tetris->start.name, tetris->tet.play.score);
      tetris->tet.over.x_max = 20;
      tetris->tet.over.y_max = 12;
      if ((tetris->tet.over.game =
	   newwin(tetris->tet.over.y_max, tetris->tet.over.x_max, 8, 1)) == NULL)
	return (my_puterror("Error : Can't create the game over window\n", 1));
      while (!(game_over(tetris, y)));
      reset_terminal_to_default(&tetris->oldt);
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

  init = 0;
  if ((init = init_game(tetris, x_max, y_max, init)) == -1)
    return (1);
  while (1)
    {
      if ((y = chk_window(tetris)) == -1)
	return (1);
      if ((chk = the_game(tetris, init, y)) == -1)
	return (0);
      if (chk > 0)
	return (1);
      usleep(1010000 - (50000 * tetris->tet.play.level));
    }
  clear();
  reset_terminal_to_default(&tetris->oldt);
  endwin();
  return (0);
}
