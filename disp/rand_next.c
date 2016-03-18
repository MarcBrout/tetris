/*
** rand_next.c for rand in /home/duhieu_b/Unix/PSU_2015_tetris
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Fri Mar 18 16:20:05 2016 benjamin duhieu
** Last update Fri Mar 18 16:42:32 2016 marc brout
*/

#include "program.h"

void		my_random_first(t_program *tetris)
{
  t_tetrimino	*elem;
  int		choose_tet;

  elem = tetris->tminos;
  choose_tet = rand() % tetris->nb_tminos;
  while (choose_tet >= 0 && elem->next != NULL)
    {
      elem = elem->next;
      choose_tet--;
    }
  tetris->first = elem;
}

void		my_random_cur(t_program *tetris)
{
  t_tetrimino	*elem;
  int		choose_tet;

  elem = tetris->tminos;
  choose_tet = rand() % tetris->nb_tminos;
  while (choose_tet >= 0 && elem->next != NULL)
    {
      elem = elem->next;
      choose_tet--;
    }
  tetris->cur = elem;
}

int		first_piece(t_program *tetris)
{
  if ((tetris->first = malloc(sizeof(t_tetrimino))) == NULL)
    return (1);
  my_random_first(tetris);
  my_random_cur(tetris);
  return (0);
}

int		other_piece(t_program *tetris)
{
  erase_next(tetris);
  free(tetris->first);
  if ((tetris->first = malloc(sizeof(t_tetrimino))) == NULL)
    return (1);
  tetris->first = tetris->cur;
  tetris->first->rot = 0;
  my_random_cur(tetris);
  return (0);
}
