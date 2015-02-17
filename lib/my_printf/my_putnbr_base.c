/*
** my_putnbr_base.c for my_putnbr_base in /u/all/botton_v/cu/rendu/c/my_printf
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Tue Nov 17 14:21:34 2009 vivien botton
** Last update Thu Nov 26 20:02:05 2009 vivien botton
*/

#include "my.h"

void    putnbr_base(unsigned int nbr, char *base)
{
  int   l;

  l = strlenp(base, -1);
  if (l < 2)
    return ;
  if (nbr / l > 0)
    putnbr_base(nbr / l, base);
  put_char(base[nbr % l]);
}

void    putnbr_basep(unsigned int nbr, char *base, int precision)
{
  int                   zero;
  int                   i;

  if (precision != -1)
    {
      zero = precision - nbrlen_basep(nbr, base, -1);
      i = 0;
      while (i < zero)
        {
          put_char('0');
          i++;
        }
    }
  putnbr_base(nbr, base);
}
