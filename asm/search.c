/*
** search.c for corewar in /u/all/botton_v/cu/test/corewar/asm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:20:36 2010 vivien botton
** Last update Fri Mar 26 11:20:39 2010 vivien botton
*/

#include <stdlib.h>
#include <unistd.h>
#include "op.h"
#include "compiler.h"
#include "lib.h"

void		fill_str_in_header(char *str, int size, int fd)
{
  int		i;

  i = 0;
  if (str && size)
    {
      while (str[0] == ' ' || str[0] == '\t')
	str++;
      str++;
      i = my_strlen(str) - 1;
      if (i >= size)
	i = size;
      write(fd, str, i);
    }
  while (i++ < size)
    write(fd, "\0", 1);
}

int		search_dotstr(char *dotstr, int size, int fd, int fdcor)
{
  int		i;
  char		*str;

  while ((str = get_next_line(fd)))
    {
      i = 0;
      while (str[i] == ' ' || str[i] == '\t')
        i++;
      if (my_strncmp_cw(&str[i], dotstr))
        {
          while (str[i] && str[i] != ' ' && str[i] != '\t')
            i++;
	  fill_str_in_header(&str[i], size, fdcor);
	  free(str);
          return (1);
        }
      free(str);
    }
  fill_str_in_header(0, size, fdcor);
  return (0);
}
