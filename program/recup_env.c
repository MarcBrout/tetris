/*
** recup_env.c for tetris in /home/brout_m/RENDU/PSU/PSU_2015_tetris
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sat Mar  5 15:29:25 2016 marc brout
** Last update Thu Mar 17 20:14:13 2016 marc brout
*/

#include <term.h>
#include <curses.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdlib.h>
#include "program.h"
#include "my.h"
#include "get_next_line.h"

int	my_set_term()
{
  int	err;
  int	ret;
  char	*s;

  if ((err = setupterm(NULL, 1, &ret)) == ERR)
    return (1);
  if ((s = tigetstr("smkx")) == (char *)-1)
    return (2);
  putp(s);
  return (0);
}

char	*recup_entry(t_program *tetris)
{
  my_bzero(tetris->start.key, tetris->start.maxl + 1);
  if (read(0, tetris->start.key, tetris->start.maxl) <= 0)
    return (NULL);
  flushinp();
  if (!tetris->start.key[0])
    return (NULL);
  return (tetris->start.key);
}

int	is_it_a_key(char **keys, char *input)
{
  int	i;

  i = 0;
  while (i < 6 && my_strcmp(input, keys[i]))
    i += 1;
  if (i == 6)
    return (-1);
  return (i);
}

int	set_no_canonique_no_wait(struct termios *oldt,
				 struct termios *newt)
{
  if (ioctl(0, TCGETS, oldt) < 0 ||
      ioctl(0, TCGETS, newt) < 0)
    return (1);
  newt->c_lflag &= ~ICANON;
  newt->c_lflag &= ~ECHO;
  newt->c_cc[VMIN] = 0;
  newt->c_cc[VTIME] = 1;
  if (ioctl(0, TCSETS, newt) < 0)
    return (1);
  return (0);
}

int	reset_terminal_to_default(struct termios *oldt)
{
  if (ioctl(0, TCSETS, oldt) < 0)
    return (1);
  return (0);
}
