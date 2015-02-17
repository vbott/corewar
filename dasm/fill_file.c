/*
** fill_file.c for corewar in /u/all/botton_v/cu/projects/corewar/dasm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Mon Mar 29 07:35:12 2010 vivien botton
** Last update Mon Mar 29 07:35:13 2010 vivien botton
*/

#include <stdlib.h>
#include "op.h"
#include "lib.h"
#include "dasm.h"

void		write_with_label(int arg, int pos, int fd, t_label *label)
{
  int		nb;

  nb = pos + arg;
  while (label && arg != 0)
    {
      if (label->pos == nb)
	{
	  my_putchar_fd(LABEL_CHAR, fd);
	  my_putstr_fd(LABEL_NAME, fd);
	  my_putnbr_fd(label->nbr, fd);
	  return ;
	}
      label = label->next;
    }
  my_putnbr_fd(arg, fd);
}

void		write_list(t_list *list, int fd, t_label *label)
{
  int		i;

  i = 0;
  my_putstr_fd(op_tab[list->nb].mnemonique, fd);
  my_putchar_fd('\t', fd);
  while (i < op_tab[list->nb].nbr_args)
    {
      if (i)
	my_putchar_fd(SEPARATOR_CHAR, fd);
      if (list->types[i] == 1)
	{
	  my_putchar_fd('r', fd);
	  my_putnbr_fd(list->args[i], fd);
	}
      else if (list->types[i] == DIR_SIZE)
	{
	  my_putchar_fd(DIRECT_CHAR, fd);
	  write_with_label(list->args[i], list->posarg, fd, label);
	}
      else
	write_with_label(list->args[i], list->posarg, fd, label);
      i++;
    }
}

t_list		*handle_dotcode(int fd, t_list *list)
{
  t_list	*mem;

  my_putstr_fd(CODE_CMD_STRING, fd);
  my_putchar_fd('\t', fd);
  while (list && list->posarg == -1)
    {
      if (list->nb < 16)
	my_putchar_fd('0', fd);
      my_putnbr_base(list->nb, "0123456789ABCDEF", fd);
      my_putchar_fd(' ', fd);
      mem = list;
      list = list->next;
      free(mem);
    }
  my_putchar_fd('\n', fd);
  return (list);
}

void		fill_file(int fd, t_list *list, t_label *label)
{
  t_list	*mem;
  t_label	*memlab;

  memlab = label;
  while (list)
    {
      if (list->posarg == -1 && !(list = handle_dotcode(fd, list)))
	return ;
      if (label && list->posarg == label->pos)
	{
	  my_putchar_fd('\n', fd);
	  my_putstr_fd(LABEL_NAME, fd);
	  my_putnbr_fd(label->nbr, fd);
	  my_putchar_fd(LABEL_CHAR, fd);
	  label = label->next;
	}
      my_putchar_fd('\t', fd);
      write_list(list, fd, memlab);
      my_putchar_fd('\n', fd);
      mem = list;
      list = list->next;
      free(mem);
    }
}
