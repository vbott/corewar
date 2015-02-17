/*
** num_label.c for corewar in /u/all/botton_v/cu/projects/corewar/dasm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Mon Mar 29 07:29:40 2010 vivien botton
** Last update Mon Mar 29 07:29:41 2010 vivien botton
*/

#include "dasm.h"

void		num_label(t_label *label)
{
  int		i;

  i = 1;
  while (label)
    {
      label->nbr = i;
      label = label->next;
      i++;
    }
}
