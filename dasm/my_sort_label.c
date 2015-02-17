/*
** my_sort_label.c for corewar in /u/all/botton_v/cu/projects/corewar/dasm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Mon Mar 29 07:34:54 2010 vivien botton
** Last update Mon Mar 29 07:34:55 2010 vivien botton
*/

#include "dasm.h"

static void	my_swap(int *nb1, int *nb2)
{
  int		mem;

  mem = *nb1;
  *nb1 = *nb2;
  *nb2 = mem;
}

void		my_sort_label(t_label **begin)
{
  t_label	*tri;
  t_label	*mem;

  mem = *begin;
  while (mem != 0)
    {
      tri = mem->next;
      while (tri != 0)
        {
          if (mem->pos > tri->pos)
            my_swap(&(mem->pos), &(tri->pos));
          tri = tri->next;
        }
      mem = mem->next;
    }
}
