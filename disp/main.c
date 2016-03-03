/*
** main.c for main in /home/duhieu_b/System_unix
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Thu Feb 25 16:57:52 2016 benjamin duhieu
** Last update Tue Mar  1 14:39:51 2016 benjamin duhieu
*/

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <unistd.h>
#include "disp.h"
#include "program.h"

int		max_wtetriminos(t_tetrimino *tet)
{
  t_tetrimino	*elem;
  int		width;

  elem = tet->next;
  width = 0;
  while (elem != NULL)
    {
      if (width <= elem->width)
	width = elem->width;
      elem = elem->next;
    }
  return (width);
}

int		max_htetriminos(t_tetrimino *tet)
{
  t_tetrimino	*elem;
  int		height;

  elem = tet->next;
  height = 0;
  while (elem != NULL)
    {
      if (height <= elem->height)
	height = elem->height;
      elem = elem->next;
    }
  return (height);
}

int		create_win(t_tet *tetris, int xmax, int ymax)
{
  getmaxyx(stdscr, tetris->height, tetris->width);
  tetris->board.x_max = 10;
  tetris->board.y_max = 20;
  if ((tetris->board.game = subwin(stdscr,
				   tetris->board.y_max, tetris->board.x_max,
				    1, 27)) == NULL)
    return (my_puterror("Error : Can't create a new window\n", 1));
  tetris->score.x_max = 20;
  tetris->score.y_max = 11;
  if ((tetris->score.game = subwin(stdscr,
				   tetris->score.y_max, tetris->score.x_max,
				   8, 1)) == NULL)
    return (my_puterror("Error : Can't create a new window\n", 1));
  tetris->next.x_max = xmax;
  tetris->next.y_max = ymax;
  if ((tetris->next.game = subwin(stdscr,
				  tetris->next.y_max, tetris->next.x_max,
				    1, 39)) == NULL)
    return (my_puterror("Error : Can't create a new window\n", 1));
  return (0);
}

void	text_end()
{
  wattron(stdscr, COLOR_PAIR(5));
  mvwprintw(stdscr, 1, 23, "***");
  mvwprintw(stdscr, 2, 23, "* ");
  mvwprintw(stdscr, 3, 23, "***");
  mvwprintw(stdscr, 4, 23, "  *");
  mvwprintw(stdscr, 5, 23, "***");
  wattroff(stdscr, COLOR_PAIR(5));
}

void	text_next()
{
  wattron(stdscr, COLOR_PAIR(3));
  mvwprintw(stdscr, 1, 11, "***");
  mvwprintw(stdscr, 2, 11, " * ");
  mvwprintw(stdscr, 3, 11, " * ");
  mvwprintw(stdscr, 4, 11, " * ");
  mvwprintw(stdscr, 5, 11, " * ");
  wattroff(stdscr, COLOR_PAIR(3));
  wattron(stdscr, COLOR_PAIR(2));
  mvwprintw(stdscr, 1, 16, "***");
  mvwprintw(stdscr, 2, 16, "* *");
  mvwprintw(stdscr, 3, 16, " **");
  mvwprintw(stdscr, 4, 16, "* *");
  mvwprintw(stdscr, 5, 16, "* *");
  wattroff(stdscr, COLOR_PAIR(2));
  wattron(stdscr, COLOR_PAIR(6));
  mvwprintw(stdscr, 1, 21, "*");
  mvwprintw(stdscr, 2, 21, " ");
  mvwprintw(stdscr, 3, 21, "*");
  mvwprintw(stdscr, 4, 21, "*");
  mvwprintw(stdscr, 5, 21, "*");
  wattroff(stdscr, COLOR_PAIR(6));
  text_end();
}

void	text()
{
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(4, COLOR_BLUE, COLOR_BLACK);
  init_pair(6, COLOR_CYAN, COLOR_BLACK);
  start_color();
  wattron(stdscr, COLOR_PAIR(1));
  mvwprintw(stdscr, 1, 1, "***");
  mvwprintw(stdscr, 2, 1, " * ");
  mvwprintw(stdscr, 3, 1, " * ");
  mvwprintw(stdscr, 4, 1, " * ");
  mvwprintw(stdscr, 5, 1, " * ");
  wattroff(stdscr, COLOR_PAIR(1));
  wattron(stdscr, COLOR_PAIR(4));
  mvwprintw(stdscr, 1, 6, "***");
  mvwprintw(stdscr, 2, 6, "*  ");
  mvwprintw(stdscr, 3, 6, "** ");
  mvwprintw(stdscr, 4, 6, "*  ");
  mvwprintw(stdscr, 5, 6, "***");
  wattroff(stdscr, COLOR_PAIR(4));
  text_next();
}

void	size_file(t_tet *tetris, int nbr, int place)
{
  int	power;
  int	i;

  power = 10000;
  i = 0;
  while ((power / 10) >= nbr && (power / 10) > 0)
    {
      mvwprintw(tetris->score.game, place, 13 + i, " ");
      i++;
      power /= 10;
    }
  mvwprintw(tetris->score.game, place, 13 + i, "%d", nbr);
}

void	score(t_tet *tetris)
{
  wborder(tetris->score.game, '|', '|', '-', '-', '/', '\\', '\\', '/');
  mvwprintw(tetris->score.game, 2, 2, "High Score");
  mvwprintw(tetris->score.game, 3, 2, "Score");
  mvwprintw(tetris->score.game, 5, 2, "Lines");
  mvwprintw(tetris->score.game, 6, 2, "Level");
  mvwprintw(tetris->score.game, 8, 2, "Timer:");
  size_file(tetris, tetris->play.high_score, 2);
  size_file(tetris, tetris->play.score, 3);
  mvwprintw(tetris->score.game, 5, 16, "0");
  size_file(tetris, tetris->play.line, 5);
  mvwprintw(tetris->score.game, 6, 16, "0");
  size_file(tetris, tetris->play.level, 6);
  mvwprintw(tetris->score.game, 8, 13, "00:00");
  mvwprintw(tetris->score.game, 8, 14, "%d:%d",
	    tetris->play.min, tetris->play.sec);
}

void	padding_tab(int **tab)
{
  int	i;
  int	j;

  i = -1;
  while (tab && tab[i + 1] != NULL)
    {
      j = -1;
      while (tab[i] && tab[i][++j] != -1)
	{
	if (j > 0 && j < 10)
	  tab[i][j] = 0;
	else
	  tab[i][j] = -1;
	}
    }
  j = -1;
  while (tab && tab[i] && tab[i][++j] != -1)
    tab[i][j] = -1;
}

int	malloc_game(t_tet *tetris, int ymax)
{
  int	i;

  if ((tetris->game.board = malloc(sizeof(int *) * 21 + ymax)) == NULL)
    return (1);
  tetris->game.board[20 + ymax] = NULL;
  i = -1;
  while (++i < 20)
    {
      if ((tetris->game.board[i] = malloc(sizeof(int) * 11)) == NULL)
	return (1);
      tetris->game.board[i][11] = -1;
    }
  padding_tab(tetris->game.board);
  return (0);
}

int	malloc_next(t_tet *tetris, int xmax, int ymax)
{
  int	i;

  if ((tetris->game.next = malloc(sizeof(int *) * (ymax + 1))) == NULL)
    return (1);
  tetris->game.next[ymax] = NULL;
  i = -1;
  while (++i < ymax)
    {
      if ((tetris->game.next[i] = malloc(sizeof(int) * xmax + 1)) == NULL)
	return (1);
      tetris->game.next[i][xmax] = -1;
    }
  padding_tab(tetris->game.board);
  return (0);
}

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

int		main()
{
  t_program	tetris;
  int		x_max;
  int		y_max;

  tetris.tet.play.high_score = 0;
  tetris.tet.play.score = 0;
  tetris.tet.play.line = 0;
  tetris.tet.play.level = 0;
  tetris.tet.play.sec = 0;
  tetris.tet.play.min = 0;
  x_max = max_wtetriminos(tetris.tminos);
  y_max = max_htetriminos(tetris.tminos);
  if (create_win(&tetris.tet, x_max, y_max))
    return (1);
  if (malloc_game(&tetris.tet, y_max))
    return (1);
  if (malloc_next(&tetris.tet, x_max, y_max))
    return (1);
  disp(&tetris);
  return (0);
}
