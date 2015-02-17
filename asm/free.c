/*
** free.c for corewar in /u/all/botton_v/cu/test/corewar/asm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:23:16 2010 vivien botton
** Last update Fri Mar 26 11:23:17 2010 vivien botton
*/

#include <stdlib.h>
#include "compiler.h"

void		free_label(t_label *label)
{
  t_label	*mem;

  while (label)
    {
      mem = label;
      label = label->next;
      free(mem->data);
      free(mem);
    }
}

void		free_list(t_list *list)
{
  t_list	*mem;

  while (list)
    {
      mem = list;
      list = list->next;
      free(mem->tab);
      free(mem->free);
      free(mem);
    }
}

void		free_when_error(t_label *label, t_list *list, char *str)
{
  free(str);
  free_label(label);
  free_list(list);
  exit(EXIT_FAILURE);
}
