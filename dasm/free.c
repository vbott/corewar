/*
** free.c for corewar in /u/all/botton_v/cu/projects/corewar/dasm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Mon Mar 29 07:33:48 2010 vivien botton
** Last update Mon Mar 29 07:33:48 2010 vivien botton
*/

#include <stdlib.h>
#include "dasm.h"

void		free_label(t_label *label)
{
  t_label	*mem;

  while (label)
    {
      mem = label;
      label = label->next;
      free(mem);
    }
}
