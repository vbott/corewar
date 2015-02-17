/*
** my_getnbr_base.c for corewar in /u/all/botton_v/cu/projects/corewar/lib/my_lib
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Mon Mar 29 07:44:32 2010 vivien botton
** Last update Mon Mar 29 07:44:32 2010 vivien botton
*/

#include "lib.h"

static int	is_base(char c, char *base)
{
  int		i;

  i = 0;
  while (base[i] != '\0')
    {
      if (base[i] == c)
	return (i);
      i++;
    }
  return (-1);
}

static int	my_strlen_base(char *str, char *base)
{
  int		i;

  i = 0;
  while (is_base(str[i], base) != -1)
    i++;
  return (i);
}

int		my_getnbr_base(char *str, char *base)
{
  int		i;
  int		size;
  int		nb;
  int		sizebase;

  i = 0;
  nb = 0;
  sizebase = my_strlen(base);
  size = my_strlen_base(str, base) - 1;
  while (size >= 0)
    {
      nb += is_base(str[i], base) * my_power_rec(sizebase, size);
      size--;
      i++;
    }
  return (nb);
}
