/*
** get_name.c for corewar in /u/all/botton_v/cu/projects/corewar/dasm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Mon Mar 29 07:33:34 2010 vivien botton
** Last update Mon Mar 29 07:33:34 2010 vivien botton
*/

#include "lib.h"

char		*get_name(char *name)
{
  int		i;
  char		*new;

  i = 0;
  new = xmalloc((my_strlen(name) + 3) * sizeof(*new));
  while (name[i] != '\0')
    {
      new[i] = name[i];
      i++;
    }
  new[i++] = '.';
  new[i++] = 's';
  new[i] = '\0';
  return (new);
}
