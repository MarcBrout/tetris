/*
** recup_env.c for tetris in /home/brout_m/RENDU/PSU/PSU_2015_tetris
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Sat Mar  5 15:29:25 2016 marc brout
** Last update Sat Mar  5 19:11:44 2016 marc brout
*/

#include <term.h>
#include <curses.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "program.h"
#include "my.h"
#include "get_next_line.h"

int	my_set_term()
{
  int	err;
  int	ret;

  if ((err = setupterm((char *)0, 1, &ret)) == ERR)
    return (1);
  return (0);
}

char	*recup_entry()
{
  char	*tmp;
  char	c;
  int	i;

  if (!(tmp = malloc(1)))
    return (NULL);
  tmp[0] = 0;
  i = 0;
  while (read(0, &c, 1) > 0)
    {
      if (!(tmp = my_realloc(tmp, i + 1)))
	return (NULL);
      tmp[i] = c;
      i += 1;
    }
  if (!tmp[0])
    return (NULL);
  return (tmp);
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
