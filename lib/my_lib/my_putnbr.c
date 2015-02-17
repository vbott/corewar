/*
** my_putnbr.c for corewar in /u/all/botton_v/cu/test/corewar/lib
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:17:15 2010 vivien botton
** Last update Fri Mar 26 11:17:16 2010 vivien botton
*/

#include "lib.h"

void		my_putnbr(int nb)
{
  if (nb < 0)
    {
      nb *= (-1);
      my_putchar('-');
    }
  if (nb / 10 > 0)
    my_putnbr(nb / 10);
  my_putchar((nb % 10) + '0');
}
