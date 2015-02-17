/*
** my_strcat.c for corewar in /u/all/botton_v/cu/test/corewar/lib
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:16:45 2010 vivien botton
** Last update Fri Mar 26 11:16:49 2010 vivien botton
*/

#if defined (WIN32)
# include <windows.h>
#else
# include <stdlib.h>
# include <unistd.h>
#endif
#include "lib.h"

char		*my_strcat(char *str1, char *str2)
{
  int		i;
  int		j;
  char		*res;

  i = 0;
  j = 0;
  if (str1 == NULL)
    res = str2;
  else
    {
      res = xmalloc(sizeof(*res) * (my_strlen(str1) + my_strlen(str2) + 1));
      while (str1[i])
        {
          res[i] = str1[i];
          i++;
        }
      while (str2[j])
        {
          res[i] = str2[j];
          j++;
          i++;
        }
      res[i] = '\0';
    }
  return (res);
}
