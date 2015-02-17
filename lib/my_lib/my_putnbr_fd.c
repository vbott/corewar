/*
** my_putnbr_fd.c for corewar in /u/all/botton_v/cu/test/corewar/dasm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:32:17 2010 vivien botton
** Last update Fri Mar 26 11:32:18 2010 vivien botton
*/

#include "lib.h"

void		my_putnbr_fd(int nb, int fd)
{
  unsigned int	mem;

  if (nb < 0)
    {
      mem = nb * -1;
      my_putchar_fd('-', fd);
    }
  else
    mem = nb;
  if (mem / 10 > 0)
    my_putnbr_fd(mem / 10, fd);
  my_putchar_fd((mem % 10) + '0', fd);
}
