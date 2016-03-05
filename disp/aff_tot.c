/*
** aff_tot.c for tot in /home/duhieu_b/System_unix/PSU_2015_tetris/disp
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Thu Mar  3 10:44:16 2016 benjamin duhieu
** Last update Fri Mar  4 20:11:28 2016 benjamin duhieu
*/

#include <ncurses.h>
#include <curses.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include "program.h"
#include "my.h"

void	init_piece(t_program *tetris, t_tetrimino *tet)
{
  tet->posx = (tetris->tet.board.x_max / 2) - (tet->width / 2);
  tet->posy = max_htetriminos(tetris->tminos) - tet->height;
  tetris->piece = 1;
  /* my_printf("-----posx = %d------posy = %d--------\n", tet->posx, tet->posy); */
}

int	chk_case(t_tetrimino *tet, int chk, int i)
{
  while (++chk < tet->width)
    {
      if (i == tet->height - 1 && tet->tmino[chk])
	return (chk);
      if (i < tet->height && tet->tmino[i][chk])
	{
	  if (!tet->tmino[i + 1][chk])
	    return (chk);
	}
    }
  return (chk);
}

int	move_piece(t_program *tetris, t_tetrimino *tet)
{
  int	i;
  int	chk;

  i = -1;
  while (++i < tet->height)
    {
      chk = -1;
      while ((chk = chk_case(tet, chk, i)) < tet->width)
	{
	  /* my_printf("tetris->tet.game.board[tet->posy + i + 1][tet->posx + chk] = %d\n", tetris->tet.game.board[tet->posy + i + 1][tet->posx + chk]); */
	  /* my_printf("tet->posx : %d, tet->posy : %d\n", tet->posx, tet->posy); */
	  if (tetris->tet.game.board[tet->posy + i + 1][tet->posx + chk] != 0)
	    return (1);
	}
    }
  tet->posy += 1;
  return (0);
}

void		put_to_board(t_program *tetris, t_tetrimino *tet)
{
  int		i;
  int		j;

  i = -1;
  while (++i < tet->height)
    {
      j = -1;
      while (++j < tet->width)
	{
	  /* printf("tet->posy : %d, tet->posx : %d, j : %d\n", tet->posy, tet->posx, j); */
	  /* my_printf("tet->color : %d\n", tet->color); */
	  tetris->tet.game.board[(tet->posy - 1)][tet->posx + j] = 0;
	  if (tet->tmino[i][j])
	    tetris->tet.game.board[tet->posy + i][tet->posx + j] = tet->color;
	}
    }
}

void		display_to_board(t_program *tetris)
{
  int		i;
  int		j;

  i = -1;
  my_printf("-----------------------------------------------------------------------i = %d\n", i);
  while (tetris->tet.game.board && tetris->tet.game.board[++i])
    {
      j = 0;
      my_printf("-----------------------------------------------------------------------j = %d\n", j);
      while (tetris->tet.game.board[i] && tetris->tet.game.board[i][++j] != -1)
	{
	  my_printf("|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||i = %d\n", i);
	  if (tetris->tet.game.board[i][j] > 0)
	  {
	    my_printf("-----------------------------------------------------------------------i  = %d, j = %d, color = %d\n", i, j, tetris->tet.game.board[i][j]);
	    wattron(tetris->tet.board.game, COLOR_PAIR(tetris->tet.game.board[i][j]));
	    mvwprintw(tetris->tet.board.game, i, j, "*");
	    wattroff(tetris->tet.board.game, COLOR_PAIR(tetris->tet.game.board[i][j]));
	  }
	}
    }
}

/* void	debug(t_program *tetris, t_tetrimino *tet) */
/* { */
/*   int	i; */
/*   int	j; */

/*   i = -1; */
/*   while (++i < 25) */
/*     { */
/*       j = -1; */
/*       while (++j < 12) */
/* 	my_printf("%d", tetris->tet.game.board[i][j]); */
/*       my_printf("tet->posx : %d, tet->posy : %d\n", tet->posx, tet->posy); */
/*     } */
/* } */

int	game(t_program *tetris, t_tetrimino *tet)
{
  wborder(tetris->tet.board.game, '|', '|', '-', '-', '-', '-', '-','-');
  /* my_printf("------------------------------------------------------------------------------------------------------------\n"); */
  if (!tetris->piece)
    init_piece(tetris, tet);
  else if (tetris->piece == 1)
    {
      if (move_piece(tetris, tet))
	{
	  tetris->piece = 0;
	  return (1);
	}
      put_to_board(tetris, tet);
      display_to_board(tetris);
      /* debug(tetris, tet); */
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
  if (malloc_game(&tetris->tet, y_max))
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
