/*
** write_arg.c for corewar in /u/all/botton_v/cu/projects/corewar/dasm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Mon Mar 29 07:33:55 2010 vivien botton
** Last update Mon Mar 29 07:33:56 2010 vivien botton
*/

#include "op.h"
#include "lib.h"
#include "dasm.h"

int		special_write_arg(char *param, int fd, int *nbarg)
{
  if (!my_strcmp(param, "live"))
    {
      *nbarg += 4;
      return (get_arg(fd, 4));
    }
  *nbarg += IND_SIZE;
  return (get_arg(fd, IND_SIZE));
}

int		write_arg(char param, int nb, int fd, int *type)
{
  if ((param & 3) == 1)
    {
      *type = 1;
      return (get_arg(fd, 1));
    }
  else if ((param & 3) == 2)
    {
      *type = DIR_SIZE;
      if (op_tab[nb].indirect)
        return (get_arg(fd, IND_SIZE));
      return (get_arg(fd, DIR_SIZE));
    }
  else
    {
      *type = IND_SIZE;
      return (get_arg(fd, IND_SIZE));
    }
}
