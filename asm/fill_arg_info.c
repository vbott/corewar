/*
** fill_arg_info.c for corewar in /u/all/botton_v/cu/test/corewar/asm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:21:50 2010 vivien botton
** Last update Fri Mar 26 11:21:52 2010 vivien botton
*/

#include <stdlib.h>
#include "compiler.h"
#include "op.h"
#include "lib.h"

int		calc_postab(char *command, int size, int line)
{
  int		pos;

  pos = get_positiontab(command);
  if (op_tab[pos].mnemonique == 0)
    {
      put_msg_error(DONTEXITINS, line);
      return (-1);
    }
  if (size > op_tab[pos].nbr_args)
    {
      put_msg_error(TOOMARG, line);
      return (-1);
    }
  if (size < op_tab[pos].nbr_args)
    {
      put_msg_error(TOOFARG, line);
      return (-1);
    }
  return (pos);
}

int		step2_arg(char **tab, int line, int pos)
{
  int		i;
  int		e;
  int		nb;

  i = 0;
  nb = 0;
  while (tab[i] != 0)
    {
      e = 0;
      while (tab[i][e] && (tab[i][e] == ' ' || tab[i][e] == '\t'))
        e++;
      if (check_error(&tab[i][e], i, pos, line))
        return (-1);
      if (tab[i][e] == 'r' || tab[i][e] == 'R')
	nb += 1;
      else if (tab[i][e] == DIRECT_CHAR && !op_tab[pos].indirect)
	nb += DIR_SIZE;
      else
	nb += IND_SIZE;
      i++;
    }
  return (nb);
}

int		step1_arg(t_list *list)
{
  int		nbarg;
  int		pos;

  pos = calc_postab(list->command, my_size_tab(list->tab), list->line);
  if (pos == -1)
    return (-1);
  nbarg = step2_arg(list->tab, list->line, pos);
  if (nbarg == -1)
    return (-1);
  if (op_tab[pos].needoctetparam)
    {
      list->octetparam = get_octet(list->tab);
      return (nbarg + 1);
    }
  else
    {
      list->octetparam = 0;
      return (nbarg);
    }
}

int		fill_arg_info(char *str, t_list **list, int line, int nbarg)
{
  int		nb;
  char		*arg;
  t_list	*mem;

  mem = xmalloc(sizeof(*mem));
  mem->command = get_params(str, &arg);
  if (mem->command)
    {
      mem->free = str;
      separe_comment(arg);
      mem->tab = my_str_to_wordtab(arg, SEPARATOR_CHAR);
      mem->line = line;
      mem->nbarg = nbarg;
      if ((nb = step1_arg(mem)) == -1)
        return (-1);
      nbarg += nb;
      mem->next = *list;
      *list = mem;
      return (nbarg + 1);
    }
  free(mem);
  return (nbarg);
}
