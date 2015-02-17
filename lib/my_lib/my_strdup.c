/*
** my_strdup.c for corewar in /u/all/botton_v/cu/test/corewar/lib
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:16:24 2010 vivien botton
** Last update Fri Mar 26 11:16:26 2010 vivien botton
*/

#if defined (WIN32)
# include <windows.h>
#else
# include <stdlib.h>
# include <unistd.h>
#endif
#include "lib.h"

char		*my_strdup(char *str)
{
  char		*copy;
  int		i;

  copy = xmalloc((my_strlen(str) + 1) * sizeof(str));
  if (copy == NULL)
    return (NULL);
  i = 0;
  while (str[i])
    {
      copy[i] = str[i];
      i++;
    }
  copy[i] = '\0';
  return (copy);
}
