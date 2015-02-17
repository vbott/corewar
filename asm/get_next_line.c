/*
** get_next_line.c for get_next_line in /u/all/cerisi_m/cu/rendu/c/get_next_line
** 
** Made by mickael cerisier
** Login   <cerisi_m@epitech.net>
** 
** Started on  Thu Nov 12 10:16:01 2009 mickael cerisier
** Last update Sun Jan 24 23:13:41 2010 mickael cerisier
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "compiler.h"
#include "lib.h"

int		strlen_gnl(char *str)
{
  int		i;

  if (str == 0)
    return (0);
  i = 0;
  while (str[i] != '\n' && str[i] != '\0')
    i++;
  return (i);
}

char		*strconcate_gnl(char *str, char *buffer, int size)
{
  int		i;
  int		e;
  char		*copy;

  i = 0;
  e = 0;
  copy = xmalloc((strlen_gnl(str) + size + 1) * sizeof(*copy));
  if (copy == NULL)
    exit(1);
  while (str != NULL && str[i] != '\0')
    {
      copy[i] = str[i];
      i++;
    }
  while (e < size)
    {
      copy[i] = buffer[e];
      i++;
      e++;
    }
  copy[i] = '\0';
  xfree(str);
  return (copy);
}

char		*get_next_line2(int nb,
				char buffer[BUFF_SIZE], int *i, char **str)
{
  int		e;

  e = 0;
  while (nb && buffer[(*i)++] != '\n')
    nb--;
  if (*i + 1 + READ_SIZE >= BUFF_SIZE && buffer[*i - 1] != '\n')
    {
      *str = strconcate_gnl(*str, buffer, *i);
      *i = 0;
    }
  else if (buffer[(*i) - 1] == '\n')
    *str = strconcate_gnl(*str, buffer, *i - 1);
  while (nb-- > 0)
    buffer[e++] = buffer[(*i)++];
  if (e != 0)
    {
      *i = e - 1;
      return (*str);
    }
  return (0);
}

char		*get_next_line(const int fd)
{
  static char	buffer[BUFF_SIZE];
  static int	i;
  char		*str;
  int		nb;
  int		a;
  int		read_size;

  str = 0;
  nb = 0;
  while (nb <= i && i != 0)
    if (buffer[nb++] == '\n')
      {
	a = 0;
	str = strconcate_gnl(str, buffer, nb - 1);
	while (nb <= i)
	  buffer[a++] = buffer[nb++];
	i = a - 1;
	return (str);
      }
  read_size = (i + READ_SIZE >= BUFF_SIZE) ? BUFF_SIZE - (i + 1) : READ_SIZE;
  while ((nb = xread(fd, &buffer[i], read_size)))
    if ((get_next_line2(nb, buffer, &i, &str)))
      return (str);
  return (str);
}
