/*
** aff_tot.c for tot in /home/duhieu_b/System_unix/PSU_2015_tetris/disp
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Thu Mar  3 10:44:16 2016 benjamin duhieu
** Last update Wed Mar 16 11:54:47 2016 benjamin duhieu
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
	  if (posit->y + i > 18 || (posit->x + j < 1 || posit->x + j > 11) ||
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

int	game(t_program *tetris, t_tetrimino *tet)
{
  werase(tetris->tet.board.game);
  wborder(tetris->tet.board.game, '|', '|', '-', '-', '-', '-', '-','-');

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
  static int	next = -1;

  if ((new_time = time(NULL)) == -1)
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
  if (game(tetris, tmp))
    next = 0;
  wrefresh(tetris->tet.board.game);
  return (0);
}

int		disp(t_program *tetris, int x_max, int y_max)
{
  time_t	init;

  if ((init = time(NULL)) == -1)
    return (1);
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
  while (1)
    {
      clear();
      text();
      wrefresh(stdscr);
      draw(tetris, init);
      sleep(1);
    }
  endwin();
  return (0);
}
