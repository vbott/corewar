/*
** get_params.c for corewar in /u/all/botton_v/cu/test/corewar/asm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:23:28 2010 vivien botton
** Last update Fri Mar 26 11:23:29 2010 vivien botton
*/

#include <stdlib.h>
#include <unistd.h>
#include "op.h"
#include "compiler.h"
#include "lib.h"

char		get_tab_nbr(char *str)
{
  int		i;

  i = 0;
  while (op_tab[i].mnemonique && my_strcmp(str, op_tab[i].mnemonique))
    i++;
  return (op_tab[i].code);
}

void		put_in_file(char *str, int fd)
{
  char		number;

  if (str[0] && str[0] != '.')
    {
      number = get_tab_nbr(str);
      write(fd, &number, 1);
    }
}

char		*get_params(char *str, char **str2)
{
  int		i;

  i = 0;
  if (str[0] == '.')
    return (0);
  while (str[i] && (str[i] == '\t' || str[i] == ' '))
    i++;
  while (str[i] && str[i] != '\t' && str[i] != ' ')
    i++;
  if (str[i - 1] != LABEL_CHAR)
    i = 0;
  while (str[i] && (str[i] == '\t' || str[i] == ' '))
    i++;
  if (!str[i])
    return (0);
  str = &str[i];
  i = 0;
  while (str[i] && str[i] != '\t' && str[i] != ' ')
    i++;
  str[i++] = '\0';
  while (str[i] && (str[i] == '\t' || str[i] == ' '))
    i++;
  *str2 = &str[i];
  return (str);
}

void		fill_file(t_list *list, t_label *label, t_file *file)
{
  t_list	*mem;

  while (list)
    {
      if (!my_strcmp(list->command, CODE_CMD_STRING))
	{
	  if (dot_code(list->tab, file->fd) == -1)
	    {
	      put_msg_error(CODENOEXT, list->line);
	      exit_fail(label, list, file->name);
	    }
	}
      else
	{
	  put_in_file(list->command, file->fd);
	  if (list->octetparam)
	    write(file->fd, &(list->octetparam), 1);
	  get_arg(list, label, file);
	}
      mem = list;
      list = list->next;
      free(mem->tab);
      free(mem->free);
      free(mem);
    }
}
