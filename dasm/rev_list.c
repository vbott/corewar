/*
** rev_list.c for corewar in /u/all/botton_v/cu/projects/corewar/dasm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Mon Mar 29 07:34:46 2010 vivien botton
** Last update Mon Mar 29 07:35:43 2010 vivien botton
*/

#include "dasm.h"

t_list		*rev_list(t_list *list, t_list *next)
{
  t_list	*mem;

  mem = list;
  list = list->next;
  mem->next = next;
  if (list)
    return (rev_list(list, mem));
  return (mem);
}
