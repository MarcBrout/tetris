/*
** recup_env.c for tetris in /home/brout_m/RENDU/PSU/PSU_2015_tetris
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sat Mar  5 15:29:25 2016 marc brout
** Last update Sat Mar  5 16:13:49 2016 marc brout
*/

#include <term.h>
#include <curses.h>

int	my_set_term()
{
  int	err;
  int	ret;

  if ((err = setupterm((char *)0, 1, &ret)) == ERR)
    return (1);
  return (0);
}
