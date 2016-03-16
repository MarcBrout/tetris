/*
** aff_next.c for yes in /home/duhieu_b/System_unix/PSU_2015_tetris
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Thu Mar  3 18:16:41 2016 benjamin duhieu
** Last update Mon Mar 14 21:24:01 2016 benjamin duhieu
*/

#include <ncurses.h>
#include <curses.h>
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
	      mvwprintw(tetris->tet.next.game, i + 1, j, "*");
	      wattroff(tetris->tet.next.game, COLOR_PAIR(tetris->tet.game.next[i][j]));
	    }
	}
    }
}

void	put_to_next(t_program *tetris, t_tetrimino *next)
{
  int	i;
  int	j;

  i = -1;
  while (++i < next->height)
    {
      j = -1;
      while (++j < next->width)
	{
	  if (next->tmino[i][j])
	    tetris->tet.game.next[i + 1][j + 1] = next->color;
	  else
	    tetris->tet.game.next[i + 1][j + 1] = 0;
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
	{
	  /* printf("tetris->tet.game[%d][%d] = %d\n", i, j, tetris->tet.game.next[i][j]); */
	  tetris->tet.game.next[i][j] = 0;
	}
    }
}

t_tetrimino	*next_form(t_program *tetris, int *next)
{
  t_tetrimino	*elem;
  static char	bol = 0;
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
	bol = 1;
      put_to_next(tetris, tetris->cur);
      return (tetris->first);
    }
  if (bol == 1)
    {
      if (!*next)
	{
	  erase_next(tetris);
	  free(tetris->first);
	  if ((tetris->first = malloc(sizeof(t_tetrimino))) == NULL)
	    return (NULL);
	  tetris->first = tetris->cur;
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
