/*
** my_putnbr_base.c for corewar in /u/all/botton_v/cu/projects/corewar/dasm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Mon Mar 29 07:33:12 2010 vivien botton
** Last update Mon Mar 29 07:33:12 2010 vivien botton
*/

#include "lib.h"

void		my_putnbr_base(int nb, char *base, int fd)
{
  char		c;
  int		size;

  size = my_strlen(base);
  if (nb / size > 0)
    my_putnbr_base(nb / size, base, fd);
  c = base[nb % size];
  my_putchar_fd(c, fd);
}
