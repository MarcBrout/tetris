/*
** program.h for  in /home/brout_m/RENDU/PSU/PSU_2015_tetris
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu Feb 25 17:29:28 2016 marc brout
** Last update Thu Feb 25 19:14:43 2016 marc brout
*/

#ifndef PROGRAM_H_
# define PROGRAM_H_

# define FOLDER_MISSING "\"./tetriminos\" folder missing or protected.\n"
# define FOLDER_EMPTY "\"./tetriminos\" containing no working tetrimino.\n"
# define MALLOC_ERR "Memory allocation error, program aborted.\n"
# define FILE_ERR "Error while opening tetrimino file\n."

typedef struct		s_tetrimino
{
  const char		*name;
  int			working;
  int			**tmino;
  int			width;
  int			height;
  struct s_tetrimino	*next;
}			t_tetrimino;

typedef struct		s_program
{
  t_tetrimino		*tminos;
  int			nb_tminos;
}			t_program;

#endif /* !PROGRAM_H_ */
