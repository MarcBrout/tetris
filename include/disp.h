/*
** disp.h for disp in /home/duhieu_b/System_unix/PSU_2015_tetris/disp
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Thu Feb 25 20:06:03 2016 benjamin duhieu
** Last update Thu Mar 17 20:03:18 2016 benjamin duhieu
*/

#ifndef DISP_H_
# define DISP_H_

# include <ncurses.h>
# include <curses.h>

typedef	struct	s_game
{
  WINDOW	*game;
  int		x_max;
  int		y_max;
}		t_game;

typedef	struct	s_score
{
  int		high_score;
  int		score;
  int		line;
  int		level;
  int		sec;
  int		min;
}		t_score;

typedef struct	s_tab
{
  int		**board;
  int		**next;
}		t_tab;

typedef	struct	s_pos
{
  int		x;
  int		y;
}		t_pos;

typedef	struct	s_tet
{
  t_game	board;
  t_game	score;
  t_game	next;
  t_game	over;
  t_score	play;
  t_tab		game;
  int		height;
  int		width;
}		t_tet;

int	my_puterror(const char *str, int);

void	size_file(t_tet *, int, int);
void	text_end();
void	text_next();
void	text();

#endif /* !DISP_H_ */
