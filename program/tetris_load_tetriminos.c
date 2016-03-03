/*
** tetris_load_tetriminos.c for tetris
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu Feb 25 17:27:16 2016 marc brout
** Last update Thu Mar  3 11:33:54 2016 marc brout
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "program.h"
#include "my.h"

t_tetrimino		*load_tetriminos(const char *folderpath,
					 int *nb_tminos)
{
  DIR*			dir;
  t_tetrimino		*tminos;

  *nb_tminos = 0;
  if (!(dir = opendir(folderpath)))
    return (my_puterror_null(FOLDER_MISSING));
  if (!(tminos = read_folder(dir, nb_tminos)))
    return (NULL);
  if (!*nb_tminos)
    return (my_puterror_null(FOLDER_EMPTY));
  return (tminos);
}

t_tetrimino		*read_folder(DIR *dir, int *nb_tminos)
{
  t_tetrimino		*tminos;
  t_tetrimino		*tmp;
  struct dirent		*file;

  if (!(tminos = malloc(sizeof(t_tetrimino))))
    return (my_puterror_null(MALLOC_ERR));
  tminos->next = NULL;
  while ((file = readdir(dir)))
    {
      if (my_strcmpcst(file->d_name, ".") &&
	  my_strcmpcst(file->d_name, "..") &&
	  !my_revstrncmpcst(file->d_name, ".tetrimino", 10))
	{
	  /* my_printf("file = %s\n", file->d_name); */
	  if (!(tmp = get_tetrimino(file->d_name)))
	    return (NULL);
	  *nb_tminos += 1;
	  tmp->next = tminos->next;
	  tminos->next = tmp;
	}
    }
  closedir(dir);
  return (tminos);
}

int			get_size(const char *firstline,
				 t_tetrimino *tmino,
				 int fd)
{
  char			*tmp;
  int			color;
  int			i;

  i = 0;
  tmino->width = my_getnbr_i(&firstline[i], &i);
  if (firstline[i] != ' ')
    tmino->working = 0;
  tmino->height = my_getnbr_i(&firstline[i], &i);
  if (firstline[i + 1] != ' ')
    tmino->working = 0;
  color = my_getnbr_i(&firstline[i], &i);
  if (!tmino->working)
    while ((tmp = get_next_line(fd)))
      free(tmp);
  if ((tmino->width <= 0 || tmino->height <= 0 || color <= 0 ||
       !tmino->working) && !(tmino->working = 0))
    return (0);
  return (color);
}

int			check_file(const char *file,
				   t_tetrimino *tmino,
				   int fd)
{
  char			*tmp;

  if (!(tmino->name = get_name(file, ".tetrimino")))
    return (1);
  /* my_printf("first line = "); */
  if ((tmp = get_next_line(fd)))
    {
      /* my_printf("%s\n", tmp); */
      if (!(tmino->color = get_size(tmp, tmino, fd)))
	tmino->working = 0;
      if (!(tmino->tmino = tab(tmino)))
	return (1);
      fill_tab(tmino, tmino->color, fd);
      free(tmp);
    }
  else
    tmino->working = 0;
  return (0);
}

t_tetrimino		*get_tetrimino(const char *file)
{
  int			fd;
  char			*path;
  t_tetrimino		*tmino;

  if (!(tmino = malloc(sizeof(t_tetrimino))) ||
      !(path = my_strcatcst("./tetriminos/", file)))
    return (my_puterror_null(MALLOC_ERR));
  if ((fd = open(path, O_RDONLY)) < 0)
    return (my_puterror_null(FILE_ERR));
  free(path);
  tmino->working = 1;
  if (check_file(file, tmino, fd))
    return (my_puterror_null(MALLOC_ERR));
  if (fd > 2)
    close(fd);
  return (tmino);
}
