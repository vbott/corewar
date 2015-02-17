/*
** exit.c for corewar in /u/all/botton_v/cu/test/corewar/asm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:21:56 2010 vivien botton
** Last update Fri Mar 26 11:21:57 2010 vivien botton
*/

#include <stdlib.h>
#include "compiler.h"
#include "lib.h"

void		exit_fail(t_label *label, t_list *list, char *name)
{
  t_label	*memlabel;
  t_list	*memlist;

  while (label)
    {
      memlabel = label;
      label = label->next;
      free(memlabel->data);
      free(memlabel);
    }
  while (list)
    {
      memlist = list;
      list = list->next;
      free(memlist->tab);
      free(memlist->free);
      free(memlist);
    }
  xremove(name);
  free(name);
  exit(EXIT_FAILURE);
}
