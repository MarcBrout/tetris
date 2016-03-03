/*
** aff_tetris.c for aff in /home/duhieu_b/System_unix/PSU_2015_tetris/disp
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Thu Mar  3 10:40:05 2016 benjamin duhieu
** Last update Thu Mar  3 10:40:38 2016 benjamin duhieu
*/

#include <ncurses.h>
#include <curses.h>
#include "program.h"

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
