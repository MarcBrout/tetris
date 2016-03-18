/*
** aff_score.c for score in /home/duhieu_b/System_unix/PSU_2015_tetris/disp
**
** Made by benjamin duhieu
** Login   <duhieu_b@epitech.net>
**
** Started on  Thu Mar  3 10:41:16 2016 benjamin duhieu
** Last update Fri Mar 18 21:18:15 2016 marc brout
*/

#include <ncurses.h>
#include <curses.h>
#include <stdlib.h>
#include "program.h"

void	size_file(t_tet *tetris, int nbr, int place)
{
  int	power;
  int	i;

  power = 10000;
  i = 0;
  while ((power / 10) > (nbr / 10) && (power / 10) > 0)
    {
      mvwprintw(tetris->score.game, place, 13 + i, " ");
      i++;
      power /= 10;
    }
  mvwprintw(tetris->score.game, place, 13 + i, "%d", nbr);
}

void	score(t_program *t, t_tet *tetris)
{
  werase(tetris->score.game);
  wborder(tetris->score.game, '|', '|', '-', '-', '/', '\\', '\\', '/');
  mvwprintw(tetris->score.game, 2, 2, "High Score");
  mvwprintw(tetris->score.game, 3, 2, "Score");
  mvwprintw(tetris->score.game, 5, 2, "Lines");
  mvwprintw(tetris->score.game, 6, 2, "Level");
  mvwprintw(tetris->score.game, 8, 2, "Timer:");
  size_file(tetris, tetris->play.high_score, 2);
  size_file(tetris, tetris->play.score, 3);
  mvwprintw(tetris->score.game, 5, 16, "0");
  size_file(tetris, tetris->play.line, 5);
  mvwprintw(tetris->score.game, 6, 16, "0");
  size_file(tetris, tetris->play.level, 6);
  mvwprintw(tetris->score.game, 8, 13, "%02d:", tetris->play.min);
  mvwprintw(tetris->score.game, 8, 16, "%02d", tetris->play.sec);
  mvwprintw(tetris->score.game, 10, 2, "Player:    %s", t->start.name);
}

void		change_score(t_program *tetris,
			     time_t new_time, time_t init)
{
  if (tetris->tet.play.score >= 100 * tetris->tet.play.level)
    tetris->tet.play.level++;
  if (tetris->tet.play.score >= tetris->tet.play.high_score)
    tetris->tet.play.high_score = tetris->tet.play.score;
  tetris->tet.play.sec = (new_time - init) % 60;
  tetris->tet.play.min = (new_time - init) / 60;
  score(tetris, &tetris->tet);
  wrefresh(tetris->tet.score.game);
}
