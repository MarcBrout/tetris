/*
** key_function_next.c for next_key in /home/duhieu_b/Unix/PSU_2015_tetris
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Mar 18 16:03:27 2016 benjamin duhieu
** Last update Fri Mar 18 16:16:43 2016 benjamin duhieu
*/

#include <ncurses.h>
#include <curses.h>
#include <unistd.h>
#include "my.h"
#include "program.h"

int	key_quit(UNUSED t_program *tetris, UNUSED t_tetrimino *tet)
{
  return (1);
}
