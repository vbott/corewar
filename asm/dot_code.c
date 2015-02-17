/*
** dot_code.c for corewar in /u/all/botton_v/cu/test/corewar/asm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:23:04 2010 vivien botton
** Last update Fri Mar 26 11:23:05 2010 vivien botton
*/

#include <unistd.h>
#include "compiler.h"
#include "lib.h"

int			dot_code(char **tab, int fd)
{
  int			i;
  int			decimal_nb;
  extern t_option	gl_option;

  if (!gl_option.extend)
    return (-1);
  i = 0;
  while (tab[i])
    {
      decimal_nb = my_getnbr_base(tab[i], "0123456789ABCDEF");
      write(fd, &decimal_nb, 1);
      i++;
    }
  return (0);
}
