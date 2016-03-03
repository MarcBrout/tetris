/*
** program.h for  in /home/brout_m/RENDU/PSU/PSU_2015_tetris
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu Feb 25 17:29:28 2016 marc brout
** Last update Thu Mar  3 11:34:59 2016 marc brout
*/

#ifndef PROGRAM_H_
# define PROGRAM_H_

# include <sys/types.h>
# include <dirent.h>
# include <stdlib.h>
# include "disp.h"

# define UNUSED __attribute__((__unused__))
# define USAGE
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
  int			color;
  struct s_tetrimino	*next;
}			t_tetrimino;

typedef struct		s_program
{
  t_tetrimino		*tminos;
  t_tet			tet;
  int			nb_tminos;
}			t_program;

/*
** tri.c
*/

void		swap_tetriminos(t_tetrimino *current,
				t_tetrimino *current_prev,
				t_tetrimino *target);
void		tri_tetriminos(t_tetrimino *root);
int		purify_tetriminos(t_tetrimino *root);

/*
** Debug : debug.c
*/

void		debug_tetriminos_list(t_tetrimino *tminos,
				      int nb_tminos);
void		debug_working_tetrimino(t_tetrimino *tmino);
void		debug_not_working_tetrimino(t_tetrimino *tmino);

/*
** Load tetriminos : tetris_load_tetriminos.c
*/

t_tetrimino	*load_tetriminos(const char *folderpath,
				 int *nb_tminos);
t_tetrimino	*read_folder(DIR *dir, int *nb_tminos);
int		get_size(const char *firstline,
			 t_tetrimino *tmino,
			 int fd);
int		check_file(const char *file,
			   t_tetrimino *tmino,
			   int fd);
t_tetrimino	*get_tetrimino(const char *file);

/*
** Arrays : tabs.c
*/

int	**tab(t_tetrimino *tmino);
int	fill_line(const char *str,
		  int *line, int width, int color);
int	check_empty_col(int **tab, int width, int height);
void	fill_tab(t_tetrimino *tmino,
		 int color, int fd);

/*
** errors : error.c
*/

int	my_puterror(const char *str, int error);
void	*my_puterror_null(const char *str);

/*
** misc : misc.c , my_getnbr.c
*/

int	my_strlencst(const char *str);
int	my_strcmpcst(const char *str1, const char *str2);
int	my_revstrncmpcst(const char *str1, const char *str2, int n);
char	*my_strcatcst(const char *str1, const char *str2);
char	*get_name(const char *str1, const char *str2);
int	net(const char *str);
int	my_getnbrcst(const char *str);
double	my_getdouble(const char *str);
int	my_getnbr_i(const char *str, int *i);

/*
** free.c
*/

void	free_tab(int **tab, int height);
void	free_list(t_tetrimino *root);

/*
** create_and_win.c
*/

int	max_wtetriminos(t_tetrimino *);
int	max_htetriminos(t_tetrimino *);
int	create_win(t_tet *, int, int);

/*
** tab_game.c
*/

int	malloc_game(t_tet *, int);
int	malloc_next(t_tet *, int, int);

/*
** aff_tot.c
*/

int	disp(t_program *);

/*
** aff_score.c
*/

void	padding_tab(int **);
void	score(t_tet *);
void	size_file(t_tet *, int, int);

/*
** disp.c
*/

int	my_disp(t_program *);

#endif /* !PROGRAM_H_ */
