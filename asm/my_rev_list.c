/*
** my_rev_list.c for my_rev_list in /u/all/cerisi_m/cu/rendu/piscine/Jour_11
** 
** Made by mickael cerisier
** Login   <cerisi_m@epitech.net>
** 
** Started on  Tue Oct 20 11:16:47 2009 mickael cerisier
** Last update Sun Jan 31 18:20:33 2010 mickael cerisier
*/

#include "compiler.h"

t_list		*my_rev_list(t_list *list, t_list *next)
{
  t_list	*mem;

  mem = list->next;
  list->next = next;
  if (mem)
    return (my_rev_list(mem, list));
  return (list);
}
