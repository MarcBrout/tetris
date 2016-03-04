/*
** aff_tetris.c for aff in /home/duhieu_b/System_unix/PSU_2015_tetris/disp
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Thu Mar  3 10:40:05 2016 benjamin duhieu
** Last update Thu Mar  3 13:30:42 2016 benjamin duhieu
*/

#include <ncurses.h>
#include <curses.h>
#include "program.h"

void	text_end()
{
  wattron(stdscr, COLOR_PAIR(5));
  mvprintw(1, 23, "***");
  mvprintw(2, 23, "* ");
  mvprintw(3, 23, "***");
  mvprintw(4, 23, "  *");
  mvprintw(5, 23, "***");
  wattroff(stdscr, COLOR_PAIR(5));
}

void	text_next()
{
  wattron(stdscr, COLOR_PAIR(3));
  mvprintw(1, 11, "***");
  mvprintw(2, 11, " * ");
  mvprintw(3, 11, " * ");
  mvprintw(4, 11, " * ");
  mvprintw(5, 11, " * ");
  wattroff(stdscr, COLOR_PAIR(3));
  wattron(stdscr, COLOR_PAIR(2));
  mvprintw(1, 16, "***");
  mvprintw(2, 16, "* *");
  mvprintw(3, 16, " **");
  mvprintw(4, 16, "* *");
  mvprintw(5, 16, "* *");
  wattroff(stdscr, COLOR_PAIR(2));
  wattron(stdscr, COLOR_PAIR(6));
  mvprintw(1, 21, "*");
  mvprintw(2, 21, " ");
  mvprintw(3, 21, "*");
  mvprintw(4, 21, "*");
  mvprintw(5, 21, "*");
  wattroff(stdscr, COLOR_PAIR(6));
  text_end();
}

void	text()
{
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(4, COLOR_BLUE, COLOR_BLACK);
  init_pair(6, COLOR_CYAN, COLOR_BLACK);
  wattron(stdscr, COLOR_PAIR(1));
  mvprintw(1, 1, "***");
  mvprintw(2, 1, " * ");
  mvprintw(3, 1, " * ");
  mvprintw(4, 1, " * ");
  mvprintw(5, 1, " * ");
  wattroff(stdscr, COLOR_PAIR(1));
  wattron(stdscr, COLOR_PAIR(4));
  mvprintw(1, 6, "***");
  mvprintw(2, 6, "*  ");
  mvprintw(3, 6, "** ");
  mvprintw(4, 6, "*  ");
  mvprintw(5, 6, "***");
  wattroff(stdscr, COLOR_PAIR(4));
  text_next();
}
