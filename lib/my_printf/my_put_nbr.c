/*
** my_put_nbr.c for my_put_nbr in /u/all/botton_v/cu/rendu/piscine
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Thu Oct  8 18:56:50 2009 vivien botton
** Last update Mon Mar 29 07:45:41 2010 vivien botton
*/

#include "my.h"

void                    put_nbr(int nb)
{
  unsigned int          nbr;

  if (nb < 0)
    nbr = nb * (-1);
  else
    nbr = nb;
  if (nbr / 10 > 0)
    put_nbr(nbr / 10);
  put_char(nbr % 10 + '0');
}

void			put_nbrp(int nb, int precision)
{
  int			zero;
  int			i;

  if (precision != -1)
    {
      zero = precision - nbrlenp(nb, -1);
      if (nb < 0)
	zero++;
      i = 0;
      while (i < zero)
	{
	  put_char('0');
	  i++;
	}
    }
  put_nbr(nb);
}
