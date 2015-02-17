/*
** my_nbrlen_base.c for my_nbrlen_base in /u/all/botton_v/cu/rendu/c/my_printf
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Tue Nov 17 14:22:49 2009 vivien botton
** Last update Fri Nov 27 17:10:29 2009 vivien botton
*/

#include "my.h"

int    nbrlen_basep(unsigned int nbr, char *base, int precision)
{
  int	i;
  int	l;

  i = 1;
  l = strlenp(base, -1);
  if (l < 2)
    return (0);
  while (nbr / l > 0)
    {
      nbr /= l;
      i++;
    }
  if (precision != -1 && i < precision)
    i = precision;
  return (i);
}

