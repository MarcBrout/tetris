/*
** options.c for tetris in ~/RENDU/PSU/PSU_2015_tetris/program
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu Mar  3 14:00:14 2016 marc brout
** Last update Fri Mar 18 17:10:13 2016 marc brout
*/

#include "program.h"
#include "my.h"

int		add_arg_to_list(const char *str,
				const char *lstr,
				t_args *first,
				t_func function)
{
  t_args	*elem;

  if (!(elem = malloc(sizeof(t_args))))
    return (1);
  if (!str)
    elem->arg = NULL;
  else
    if (!(elem->arg = my_strdup((char *)str)))
      return (1);
  if (!(elem->long_arg = my_strdup((char *)lstr)))
    return (1);
  elem->func = function;
  elem->next = first->next;
  first->next = elem;
  return (0);
}

t_args		*init_arg_list()
{
  t_args	*args;

  if (!(args = malloc(sizeof(t_args))) ||
      !(args->long_arg = my_strdup("--help")))
    return (NULL);
  args->func = &help;
  args->arg = NULL;
  args->next = NULL;
  if (add_arg_to_list("-l", "--level=", args, &level) ||
      add_arg_to_list("-kl", "--key-left=", args, &keyleft) ||
      add_arg_to_list("-kr", "--key-right=", args, &keyright) ||
      add_arg_to_list("-kt", "--key-turn=", args, &keyturn) ||
      add_arg_to_list("-kd", "--key-drop=", args, &keydrop) ||
      add_arg_to_list("-kq", "--key-quit=", args, &keyquit) ||
      add_arg_to_list("-kp", "--key-pause=", args, &keypause) ||
      add_arg_to_list(NULL, "--map-size=", args, &mapsize) ||
      add_arg_to_list("-w", "--without-next", args, &withoutnext) ||
      add_arg_to_list("-d", "--debug", args, &debugmode))
    return (NULL);
  return (args);
}

int		check_args(t_program *prog, t_args *root,
			   const char **av, int *i)
{
  t_args	*tmp;

  tmp = root->next;
  while (tmp)
    {
      if (tmp->arg && !(my_strcmp((char *)av[*i], tmp->arg)))
	{
	  if (tmp->func(&prog->start, (char **)av, i, 0))
	    return (1);
	  return (0);
	}
      if (!(my_strncmp((char *)av[*i], tmp->long_arg,
		       my_strlen(tmp->long_arg) - 1)))
	return ((tmp->func(&prog->start, (char **)av, i, 1)));
      tmp = tmp->next;
    }
  return (1);
}

int		init_start(t_start *start)
{
  if (my_set_term() == 1)
    return (1);
  start->level = 1;
  my_bzero(start->keyalloc, 7);
  if (!(start->keys = malloc(sizeof(char *) * 7)) ||
      (start->keys[K_LEFT] = tigetstr("kcub1")) == (char *)-1 ||
      (start->keys[K_RIGHT] = tigetstr("kcuf1")) == (char *)-1 ||
      (start->keys[K_TURN] = tigetstr("kcuu1")) == (char *)-1 ||
      (start->keys[K_DROP] = tigetstr("kcud1")) == (char *)-1 ||
      !(start->keys[K_QUIT] = my_strdup("q")) ||
      !(start->keys[K_PAUSE] = my_strdup(" ")))
    return (1);
  start->keys[6] = NULL;
  start->keyalloc[K_QUIT] = 1;
  start->keyalloc[K_PAUSE] = 1;
  start->row = 20;
  start->col = 10;
  start->hide = 0;
  start->debug = 0;
  return (0);
}

int		parse_args(t_program *prog, const char **av)
{
  t_args	root;
  int		ret;
  int		i;

  if (!(root.next = init_arg_list()))
    return (1);
  i = 1;
  while (av[i])
    {
      if ((ret = check_args(prog, &root, av, &i)) ==  2)
	return (2);
      else if (ret)
	{
	  display_help((char **)av);
	  return (1);
	}
      i += 1;
    }
  free_args(&root);
  return (0);
}
