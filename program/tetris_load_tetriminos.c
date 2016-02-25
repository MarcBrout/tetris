/*
** tetris_load_tetriminos.c for tetris
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu Feb 25 17:27:16 2016 marc brout
** Last update Thu Feb 25 20:01:12 2016 marc brout
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>

t_tetriminos		*load_tetriminos(const char	*folderpath,
					 int		*nb_tminos)
{
  DIR*			dir;
  t_tetriminos		*tminos;

  *nb_tminos = 0;
  if (!(dir = opendir(folderpath)))
    return(my_puterror_null(FOLDER_MISSING));
  if (!(tminos = read_folder(dir, nb_tminos)))
    return (NULL);
  if (!*nb_tminos)
    return (my_puterror_null(FOLDER_EMPTY));
  return (tminos);
}

t_tetriminos		*read_folder(DIR *dir, int *nb_tminos)
{
  t_tetriminos		*tminos;
  t_tetriminos		*tmp;
  struct dirent		*file;
  char			*path;

  if (!tminos = malloc(sizeof(t_tetriminos)))
    return (my_puterror_null(MALLOC_ERR));
  tminos->next = NULL;
  while (!(file = readdir(dir)))
    {
      if (my_strcmp(file->d_name, ".") && my_strcmp(file->d_name, "..") &&
	  !my_revstrncmp(file->d_name, ".tetrimino"))
	{
	  if (!(tmp = get_tetrimino(file->d_name)))
	    return (NULL);
	  *nb_tminos += 1;
	  tmp->next = tminos->next;
	  tminos->next = tmp;
	}
    }
  return (tminos);
}

int			check_file(const char		*file,
				   t_tetriminos		*tmino,
				   int			fd)
{
  char			*tmp;
  int			i;
  int			color;

  if (tmp = get_next_line(fd))
    {
      i = 0;
      tmino->width = my_getnbr_i(&tmp[i++], &i);
      tmino->height = my_getnbr_i(&tmp[i++], &i);
      color = my_getnbr_i(&tmp[i], &i);
      if (tmino->width <= 0 || tmino->height <= 0 || color <= 0)
	{
	  tmino->working = 0;
	  return (0);
	}
      if (!(tmino->tab = create_tetrimino_tab(tmino)))
	return (my_puterror(MALLOC_ERR, 1));
      free(tmp);
    }
  else
    tmino->working = 0;
  return (0);
}

t_tetriminos		*get_tetrimino(const char *file)
{
  int			fd;
  char			*path;
  t_tetriminos		*tmino;

  if (!tmino = malloc(sizeof(t_tetriminos)) ||
      !(path = my_strcat("./tetriminos/", file)))
    return (my_puterror_null(MALLOC_ERR));
  if ((fd = open(path, O_RDONLY)) < 0)
    return (my_puterror_null(FILE_ERR));
  if (check_file(check_file(file, tmino, fd)))
    return (my_puterror_null(MALLOC_ERR));
  if (fd > 2)
    close(fd);
  return (tminos);
}
