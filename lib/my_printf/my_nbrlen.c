/*
** my_nbrlen.c for my_nbrlen in /u/all/botton_v/cu/rendu/c/my_printf
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Tue Nov 17 14:26:08 2009 vivien botton
** Last update Mon Mar 29 07:47:37 2010 vivien botton
*/

void		modif(int precision, int neg, int *i)
{
  if (*i < precision)
    *i = precision;
  if (neg)
    *i = *i + 1;
}

int		nbrlenp(int nbr, int precision)
{
  int		i;
  int		neg;
  unsigned	nb;

  i = 1;
  neg = 0;
  if (nbr < 0)
    {
      nb = nbr * (-1);
      i++;
      neg = 1;
    }
  else
    nb = nbr;
  while (nb / 10 > 0)
    {
      nb /= 10;
      i++;
    }
  if (precision != -1)
    modif(precision, neg, &i);
  return (i);
}
