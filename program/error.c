/*
** error.c for tetris in /home/brout_m/RENDU/PSU/PSU_2015_tetris/program
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu Feb 25 17:40:23 2016 marc brout
** Last update Thu Feb 25 18:43:21 2016 marc brout
*/

int		my_puterror(const char *str, int error)
{
  write(2, str, my_strlen(str));
  return (error);
}

void		*my_puterror_null(const char *str)
{
  write(2, str, my_strlen(str));
  return (NULL);
}
