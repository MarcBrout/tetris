/*
** get_max_key_len.c for tetris in ~/RENDU/PSU/PSU_2015_tetris
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu Mar 17 19:29:59 2016 marc brout
** Last update Thu Mar 17 20:25:42 2016 marc brout
*/

#include "program.h"
#include "my.h"

int	get_max_key_len(t_program *tetris)
{
  int	max;
  int	ret;
  int	i;

  i = 0;
  max = 0;
  while (i < 6)
    {
      if (max < (ret = my_strlen(tetris->start.keys[i])))
	max = ret;
      i += 1;
    }
  return (max);
}
