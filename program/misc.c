/*
** misc.c for tetris in /home/brout_m/RENDU/PSU/PSU_2015_tetris/program
**
** Made by marc brout
** Login   <brout_m@epitech.net>
**
** Started on  Thu Feb 25 17:43:44 2016 marc brout
** Last update Thu Feb 25 20:53:51 2016 marc brout
*/

int	my_strlen(const char *str)
{
  int	i;

  i = 0;
  while (str && str[i])
    i++;
  return (i);
}

int	my_strcmp(const char *str1, const char *str2)
{
  int	i;

  if (!str1 || !str2)
    return (-1);
  i = 0;
  while (str1[i] && str2[i] && str1[i] == str2[i])
    i++;
  return (str1[i] - str2[i]);
}

int	my_revstrncmp(const char *str1, const char *str2, int n)
{
  int	i;
  int	j;

  if (!str1 || !str2 || !n)
    return (-1);
  i = my_strlen(str1);
  j = my_strlen(str2);
  while (i > 0 && j > 0 && str1[i] == str2[j])
    {
      i--;
      j--;
    }
  return (str1[i] - str2[j]);
}

char	*my_strcat(const char *str1, const char *str2)
{
  int	i;
  int	j;
  char	*res;

  if (!str1 || !str2)
    return (NULL);
  if ((res = malloc(my_strlen(str1) + my_strlen(str2) + 1)) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (str1[i])
    res[i] = str1[i++];
  while (str2[j])
    res[i++] = str2[j++];
  res[i] = 0;
  return (res);
}

char	*get_name(const char *str1, const char *str2)
{
  int	i;
  int	j;
  char	*res;

  if (!str1 || !str2)
    return (NULL);
  j = my_strlen(str2);
  i = my_strlen(str1) - j;
  if (!(res = malloc(i + 1)))
    return (NULL);
  j = -1;
  while (++j < i)
    res[j] = str1[j];
  res[j] = 0;
  return (res);
}
