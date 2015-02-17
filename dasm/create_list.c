/*
** create_list.c for corewar in /u/all/botton_v/cu/projects/corewar/dasm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Mon Mar 29 07:29:29 2010 vivien botton
** Last update Mon Mar 29 07:29:30 2010 vivien botton
*/

#include "op.h"
#include "lib.h"
#include "dasm.h"

int		verif_dotcode(char c, int nb)
{
  int		i;
  int		size;
  char		mem;

  i = 0;
  size = 3;
  while (i < op_tab[nb].nbr_args)
    {
      mem = (c >> (size * 2)) & 3;
      if (mem == 0)
	return (i);
      if (mem == 3 && !(op_tab[nb].type[i] & T_IND))
	return (-1);
      if (mem == 2 && !(op_tab[nb].type[i] & T_DIR))
	return (-1);
      if (mem == 1 && !(op_tab[nb].type[i] & T_REG))
	return (-1);
      i++;
      size--;
    }
  return (i);
}

int		fill_arg_next(char c, int fd, int nb, t_list **list)
{
  int		i;
  int		nbarg;
  char		param;

  if (verif_dotcode(c, nb) != op_tab[nb].nbr_args)
    {
      i = (*list)->posarg + 1;
      (*list)->posarg = -1;
      (*list)->nb += 1;
      *list = create_list(*list, fd, i, c);
      return (-1);
    }
  nbarg = 2;
  i = 0;
  while (i < op_tab[nb].nbr_args)
    {
      param = c >> ((3 - i) * 2);
      (*list)->args[i] = write_arg(param, nb, fd, &((*list)->types[i]));
      if ((*list)->types[i] == 4 && op_tab[nb].indirect)
	nbarg += IND_SIZE;
      else
	nbarg += (*list)->types[i];
      i++;
    }
  return (nbarg);
}

int		fill_arg(int fd, int nb, int posarg, t_list **list)
{
  unsigned char	buffer[1];

  (*list)->nb = nb;
  (*list)->posarg = posarg;
  if (op_tab[nb].needoctetparam)
    {
      if (xread(fd, buffer, 1))
	{
	  nb = fill_arg_next(buffer[0], fd, nb, list);
	  if (nb == -1)
	    return (-1);
	  return (posarg + nb);
	}
    }
  else
    {
      (*list)->types[0] = 4;
      (*list)->args[0] = special_write_arg(op_tab[nb].mnemonique, fd, &posarg);
    }
  return (posarg + 1);
}

t_list		*create_list(t_list *list, int fd, int posarg, char c)
{
  int		nb;
  unsigned char	buffer[1];
  t_list	*new;

  if (c || xread(fd, buffer, 1))
    {
      if (c)
	buffer[0] = c;
      nb = 0;
      while (op_tab[nb].code && op_tab[nb].code != buffer[0])
        nb++;
      new = xmalloc(sizeof(*new));
      new->next = list;
      if (op_tab[nb].code && (posarg = fill_arg(fd, nb, posarg, &new)) == -1)
	return (new);
      else if (!op_tab[nb].code)
	{
	  new->posarg = -1;
	  new->nb = buffer[0];
	  posarg += 1;
	}
      return (create_list(new, fd, posarg, 0));
    }
  return (list);
}
