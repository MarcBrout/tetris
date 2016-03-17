/*
** program.h for tetris
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu Feb 25 17:29:28 2016 marc brout
** Last update Thu Mar 17 17:19:44 2016 benjamin duhieu
*/

#ifndef PROGRAM_H_
# define PROGRAM_H_

# include <termios.h>
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

typedef enum		e_keys
  {
    K_LEFT		= 0,
    K_RIGHT		= 1,
    K_TURN		= 2,
    K_DROP		= 3,
    K_QUIT		= 4,
    K_PAUSE		= 5
  }			t_keys;

typedef struct		s_start
{
  int			level;
  char			*name;
  char			**keys;
  char			keyalloc[6];
  int			row;
  int			col;
  int			hide;
  int			debug;
}			t_start;

typedef struct		s_tetrimino
{
  const char		*name;
  int			working;
  int			**tmino;
  int			**tmino_aff;
  int			**tmino_rot;
  int			width;
  int			height;
  int			color;
  struct s_tetrimino	*next;
}			t_tetrimino;

typedef int (*t_func)(t_start *, char **, int *, char);

typedef struct		s_args
{
  char			*arg;
  char			*long_arg;
  t_func		func;
  struct s_args		*next;
}			t_args;

typedef struct		s_hscore
{
  char			*name;
  int			score;
}			t_hscore;

typedef struct		s_program
{
  t_start		start;
  char			hs;
  t_hscore		hscore[10];
  t_tetrimino		*tminos;
  t_tetrimino		*cur;
  t_tetrimino		*first;
  t_tet			tet;
  time_t		pause;
  char			piece;
  t_pos			posit;
  int			nb_tminos;
  struct termios        oldt;
  struct termios	newt;
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

void	free_args(t_args *rootarg);
int	**array(t_tetrimino *tmino);
int	fill_line(const char *str,
		  int *line, int width, int color);
int	check_empty_col(int **array, int width, int height);
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

void	free_keys(t_program *tetris);
void	free_high_score(t_program *tetris);
void	free_rot_tab(int **rot_tab, int w, int h);
void	free_tab(int **array, int height);
void	free_list(t_tetrimino *root);

/*
** create_and_win.c
*/

int	max_wtetriminos(t_tetrimino *);
int	max_htetriminos(t_tetrimino *);
int	create_win(t_program *, t_tet *, int, int);

/*
** tab_game.c
*/

int	malloc_game(t_program *, t_tet *);
int	malloc_next(t_tet *, int, int);

/*
** aff_tot.c
*/

int	game_over(t_program *, int, int);
int	disp(t_program *, int, int);

/*
** aff_score.c
*/

void	padding_tab(t_program *, int **);
void	score(t_program *, t_tet *);
void	size_file(t_tet *, int, int);

/*
** aff_next.c
*/

t_tetrimino	*next_form(t_program *, int *);

/*
** disp.c
*/

int	my_disp(t_program *);

/*
** option.c
*/

int	add_arg_to_list(const char *str,
			const char *lstr,
			t_args *first,
			t_func function);
t_args	*init_arg_list();
int	check_args(t_program *prog,
		   t_args *root,
		   const char **av,
		   int *i);
int	init_start(t_start *start);
int	parse_args(t_program *prog, const char **av);

/*
** help.c
*/

int	level(t_start *start, char **av, int *i, char arg);
int	mapsize(t_start *start, char **av, int *i, char arg);
int	withoutnext(t_start *start, char **av, int *i, char arg);
int	debugmode(t_start *start, char **av, int *i, char arg);
void	display_help(char **av);

/*
** get_keys.c
*/

int	keyleft(t_start *start, char **av, int *i, char arg);
int	keyright(t_start *start, char **av, int *i, char arg);
int	keyturn(t_start *start, char **av, int *i, char arg);
int	keydrop(t_start *start, char **av, int *i, char arg);
int	keyquit(t_start *start, char **av, int *i, char arg);

/*
** get_pause.c
*/

int	help(t_start *start, char **av, int *i, char arg);
int	keypause(t_start *start, char **av, int *i, char arg);

/*
** recup_env.c
*/

char	*recup_entry();
int	is_it_a_key(char **keys, char *input);
int	set_no_canonique_no_wait(struct termios *oldt,
				 struct termios *newt);
int	reset_terminal_to_default(struct termios *oldt);
int	my_set_term();

/*
** temp_tetriminos.c
*/

int	init_rotation_tabs(t_tetrimino *tmino);
void	copy_rotation_tabs(t_tetrimino *tmino);
void	my_bzero(void *data, int size);

/*
** get_high_scores.c
*/

void	init_high_scores(t_program *tetris);
int	load_high_scores(t_program *tetris);
void	my_putnbr_tofd(int nb, int fd);
int	save_high_scores(t_program *tetris);

#endif /* !PROGRAM_H_ */
