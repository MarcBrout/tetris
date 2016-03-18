/*
** aff_next.c for yes in /home/duhieu_b/System_unix/PSU_2015_tetris
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Thu Mar  3 18:16:41 2016 benjamin duhieu
** Last update Fri Mar 18 14:19:40 2016 benjamin duhieu
*/

#include <ncurses.h>
#include <curses.h>
#include <stdbool.h>
#include "program.h"
#include "my.h"

void	aff_next(t_program *tetris)
{
  int	i;
  int	j;

  i = -1;
  while (tetris->tet.game.next && tetris->tet.game.next[++i])
    {
      j = 0;
      while (tetris->tet.game.next[i] && tetris->tet.game.next[i][++j] != -1)
	{
	  if (tetris->tet.game.next[i][j] > 0)
	    {
	      wattron(tetris->tet.next.game, COLOR_PAIR(tetris->tet.game.next[i][j]));
	      mvwprintw(tetris->tet.next.game, i, j, "*");
	      wattroff(tetris->tet.next.game, COLOR_PAIR(tetris->tet.game.next[i][j]));
	    }
	}
    }
}

void	put_to_next(t_program *tetris, t_tetrimino *next)
{
  int	i;
  int	j;
  t_pos	posit;

  i = -1;
  posit.x = (tetris->tet.next.x_max / 2) - (next->width / 2);
  posit.y = (tetris->tet.next.y_max / 2) - (next->height / 2);
  while (++i < next->height)
    {
      j = -1;
      while (++j < next->width)
	{
	  if (next->tmino[i][j])
	    tetris->tet.game.next[i + posit.y][j + posit.x] = next->color;
	  else
	    tetris->tet.game.next[i + posit.y][j + posit.x] = 0;
	}
    }
  aff_next(tetris);
}

void	erase_next(t_program *tetris)
{
  int	i;
  int	j;

  i = -1;
  while (tetris->tet.game.next[++i])
    {
      j = 0;
      while (tetris->tet.game.next[i][++j] != -1)
	tetris->tet.game.next[i][j] = 0;
    }
}

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
  my_random_cur(tetris);
  return (0);
}

t_tetrimino	*next_form(t_program *tetris, int *next)
{
  static bool	bol = false;
  t_tetrimino	*elem;
  int		choose_tet;

  werase(tetris->tet.next.game);
  wborder(tetris->tet.next.game, '|', '|', '-', '-', '/', '\\', '\\', '/');
  mvwprintw(tetris->tet.next.game, 0, 1, "NEXT");
  if (!bol)
    {
      if (*next == -1)
	{
	  if ((tetris->first = malloc(sizeof(t_tetrimino))) == NULL)
	    return (NULL);
	  /* if (first_piece(tetris)) */
	  /*   return (NULL); */
	  elem = tetris->tminos;
	  choose_tet = rand() % tetris->nb_tminos;
	  while (choose_tet >= 0 && elem->next != NULL)
	    {
	      elem = elem->next;
	      choose_tet--;
	    }
	  tetris->first = elem;
	  elem = tetris->tminos;
	  choose_tet = rand() % tetris->nb_tminos;
	  while (choose_tet >= 0 && elem->next != NULL)
	    {
	      elem = elem->next;
	      choose_tet--;
	    }
	  tetris->cur = elem;
	}
      else if (*next == 0)
	bol = true;
      if (!bol)
	{
	  put_to_next(tetris, tetris->cur);
	  return (tetris->first);
	}
    }
  if (bol)
    {
      if (!*next)
	{
	/* if ((other_piece(tetris))) */
	/*   return (NULL); */
	  erase_next(tetris);
	  free(tetris->first);
	  if ((tetris->first = malloc(sizeof(t_tetrimino))) == NULL)
	    return (NULL);
	  tetris->first = tetris->cur;
	  tetris->first->rot = 0;
	  elem = tetris->tminos;
	  choose_tet = rand() % tetris->nb_tminos;
	  while (choose_tet >= 0 && elem->next != NULL)
	    {
	      elem = elem->next;
	      choose_tet--;
	    }
	  tetris->cur = elem;
	}
      put_to_next(tetris, tetris->cur);
    }
  return (tetris->first);
}
