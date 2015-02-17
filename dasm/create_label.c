/*
** create_label.c for corewar in /u/all/botton_v/cu/projects/corewar/dasm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Mon Mar 29 07:32:53 2010 vivien botton
** Last update Mon Mar 29 07:32:54 2010 vivien botton
*/

#include "op.h"
#include "lib.h"
#include "dasm.h"

int		exist_label(t_label *label, int pos)
{
  while (label)
    {
      if (label->pos == pos)
	return (1);
      label = label->next;
    }
  return (0);
}

t_label		*fill_label(t_list *list, t_label *label, int pos)
{
  t_label	*new;

  if (exist_label(label, pos) || pos < 0)
    return (label);
  while (list)
    {
      if (list->posarg == pos)
	{
	  new = xmalloc(sizeof(*new));
	  new->next = label;
	  new->pos = pos;
	  return (new);
	}
      list = list->next;
    }
  return (label);
}

int		command_with_label(char *cmd)
{
  if (!my_strcmp(cmd, "fork") || !my_strcmp(cmd, "zjmp") ||
      !my_strcmp(cmd, "sti") || !my_strcmp(cmd, "ldi"))
    return (1);
  return (0);
}

t_label		*create_label(t_list *list)
{
  int		i;
  t_list	*mem;
  t_label	*label;

  mem = list;
  label = 0;
  while (list)
    {
      if (list->posarg != -1 && command_with_label(op_tab[list->nb].mnemonique))
	{
	  i = 0;
	  while (i < op_tab[list->nb].nbr_args)
	    {
	      if ((list->types[i] == DIR_SIZE) && list->args[i] != 0)
		label = fill_label(mem, label, list->posarg + list->args[i]);
	      i++;
	    }
	}
      list = list->next;
    }
  return (label);
}
