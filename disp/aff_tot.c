/*
** aff_tot.c for tot in /home/duhieu_b/System_unix/PSU_2015_tetris/disp
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Thu Mar  3 10:44:16 2016 benjamin duhieu
** Last update Wed Mar 16 17:45:07 2016 benjamin duhieu
*/

#include <ncurses.h>
#include <curses.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include "program.h"
#include "my.h"

void	init_piece(t_program *tetris, t_tetrimino *tet, t_pos *posit)
{
  posit->x = (tetris->tet.board.x_max / 2) - (tet->width / 2);
  posit->y = 0;
  tetris->piece = 1;
}

void		display_to_board(t_program *tetris)
{
  int		i;
  int		j;

  i = -1;
  while (++i < 19)
    {
      j = -1;
	while (++j < 10)
	  {
	    if (tetris->tet.game.board[i][j] > 0)
	      {
		wattron(tetris->tet.board.game,
			COLOR_PAIR(tetris->tet.game.board[i][j]));
		mvwprintw(tetris->tet.board.game, i, j, "*");
		wattroff(tetris->tet.board.game,
			 COLOR_PAIR(tetris->tet.game.board[i][j]));
	      }
	  }
    }
}

void	display_move_piece(t_program *tetris, t_tetrimino *tet, t_pos *posit)
{
  int	i;
  int	j;

  i = -1;
  while (++i < tet->height)
    {
      j = -1;
      while (++j < tet->width)
	{
	  if (tet->tmino[i][j])
	    {
	      wattron(tetris->tet.board.game,
		      COLOR_PAIR(tet->tmino[i][j]));
	      mvwprintw(tetris->tet.board.game, posit->y + i, posit->x + j, "*");
	      wattroff(tetris->tet.board.game,
		       COLOR_PAIR(tet->tmino[i][j]));
	    }
	}
    }
}

int	move_piece(t_program *tetris, t_tetrimino *tet, t_pos *posit)
{
  int	i;
  int	j;

  i = -1;
  while (++i < tet->height)
    {
      j = -1;
      while (++j < tet->width)
	{
	  if (posit->y + i > 18 || (posit->x + j < 1 || posit->x + j > 8) ||
	      tetris->tet.game.board[posit->y + i][posit->x + j] > 0)
	    return (1);
	}
    }
  return (0);
}

void	put_to_board(t_program *tetris, t_tetrimino *tet, t_pos *posit)
{
  int	i;
  int	j;

  i = -1;
  while (++i < tet->height)

    {
      j = -1;
      while (++j < tet->width)
	{
	  if (tet->tmino[i][j])
	    tetris->tet.game.board[posit->y + i][posit->x + j] = tet->tmino[i][j];
	}
    }
}

int	key_right(t_program *tetris, t_tetrimino *tet)
{
  tetris->posit.x++;
  if (move_piece(tetris, tet, &tetris->posit))
    tetris->posit.x--;
  display_move_piece(tetris, tet, &tetris->posit);
  display_to_board(tetris);
  return (0);
}

int	key_left(t_program *tetris, t_tetrimino *tet)
{
  tetris->posit.x--;
  if (move_piece(tetris, tet, &tetris->posit))
    tetris->posit.x++;
  display_move_piece(tetris, tet, &tetris->posit);
  display_to_board(tetris);
  return (0);
}

int	key_drop(t_program *tetris, t_tetrimino *tet)
{
  while (!(move_piece(tetris, tet, &tetris->posit)))
    tetris->posit.y++;
  return (0);
}

int	key_quit(UNUSED t_program *tetris, UNUSED t_tetrimino *tet)
{
  return (1);
}

int		key_pause(t_program *tetris, UNUSED t_tetrimino *tet)
{
  int		recup;
  time_t	tmp;
  char		*touch;

  if ((tmp = time(NULL)) == -1)
    return (-1);
  while (42)
    {
      if ((touch = recup_entry()))
	if ((recup = is_it_a_key(tetris->start.keys, touch)) == 5)
	  break ;
    }
  if ((tetris->pause += time(NULL) - tmp) == -1)
    return (-1);
  return (0);
}

void	init_tab(int (*key_tab[6])(t_program *, t_tetrimino *))
{
  key_tab[K_LEFT] = &key_left;
  key_tab[K_RIGHT] = &key_right;
  /* key_tab[K_TURN] = &key_turn; */
  key_tab[K_DROP] = &key_drop;
  key_tab[K_QUIT] = &key_quit;
  key_tab[K_PAUSE] = &key_pause;
}

int	game(t_program *tetris, t_tetrimino *tet)
{
  int	(*key_tab[6])(t_program *, t_tetrimino *);
  int	recup;
  char	*touch;

  werase(tetris->tet.board.game);
  wborder(tetris->tet.board.game, '|', '|', '-', '-', '-', '-', '-','-');
  init_tab(key_tab);
  if ((touch = recup_entry()))
    {
      if ((recup = is_it_a_key(tetris->start.keys, touch)) >= 0)
	{
	  if (key_tab[recup](tetris, tet))
	    return (-1);
	}
    }
  if (!tetris->piece)
    {
      init_piece(tetris, tet, &tetris->posit);
      display_to_board(tetris);
    }
  else if (tetris->piece == 1)
    {
      if (move_piece(tetris, tet, &tetris->posit))
	{
	  tetris->posit.y--;
	  put_to_board(tetris, tet, &tetris->posit);
	  display_to_board(tetris);
	  tetris->piece = 0;
	  return (1);
	}
      else
	{
	  display_move_piece(tetris, tet, &tetris->posit);
	  display_to_board(tetris);
	  tetris->posit.y++;
	}
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
  tetris->tet.play.sec = (new_time - init) % 60;
  tetris->tet.play.min = (new_time - init) / 60;
  score(&tetris->tet);
  wrefresh(tetris->tet.score.game);
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

int		disp(t_program *tetris, int x_max, int y_max)
{
  time_t	init;
  int		chk;

  if ((init = time(NULL)) == -1)
    return (1);
  tetris->pause = 0;
  initscr();
  keypad(stdscr, TRUE);
  set_escdelay(0);
  noecho();
  curs_set(0);
  if (create_win(&tetris->tet, x_max, y_max))
    return (1);
  if (malloc_game(&tetris->tet))
    return (1);
  if (malloc_next(&tetris->tet, x_max, y_max))
    return (1);
  set_no_canonique_no_wait(&tetris->oldt, &tetris->newt);
  while (1)
    {
      clear();
      text();
      wrefresh(stdscr);
      if ((chk = draw(tetris, init)) == -1)
	{
	  endwin();
	  return (1);
	}
      if (chk > 0)
	{
	  endwin();
	  return (0);
	}
      sleep(1);
    }
  reset_terminal_to_default(&tetris->oldt);
  endwin();
  return (0);
}
