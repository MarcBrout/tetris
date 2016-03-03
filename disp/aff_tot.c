/*
** aff_tot.c for tot in /home/duhieu_b/System_unix/PSU_2015_tetris/disp
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Thu Mar  3 10:44:16 2016 benjamin duhieu
** Last update Thu Mar  3 11:26:01 2016 benjamin duhieu
*/

#include <ncurses.h>
#include <curses.h>
#include <unistd.h>
#include <stdio.h>
#include "program.h"

int	game(t_program *tetris)
{
  wborder(tetris->tet.board.game, '|', '|', '-', '-', '-', '-', '-','-');
  return (0);
}

void	next_form(t_program *tetris)
{
  wborder(tetris->tet.next.game, '|', '|', '-', '-', '/', '\\', '\\', '/');
  mvwprintw(tetris->tet.next.game, 0, 1, "NEXT");
}

void	draw(t_program *tetris)
{
  score(&tetris->tet);
  wrefresh(tetris->tet.score.game);
  game(tetris);
  wrefresh(tetris->tet.board.game);
  next_form(tetris);
  wrefresh(tetris->tet.next.game);
}

int		disp(t_program *tetris)
{
  initscr();
  keypad(stdscr, TRUE);
  set_escdelay(0);
  noecho();
  curs_set(0);
  while (1)
    {
      clear();
      text();
      wrefresh(stdscr);
      draw(tetris);
      sleep(1);
    }
  endwin();
  return (0);
}
