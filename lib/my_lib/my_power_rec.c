/*
** my_power_rec.c for corewar in /u/all/botton_v/cu/projects/corewar/lib/my_lib
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Mon Mar 29 07:44:43 2010 vivien botton
** Last update Mon Mar 29 07:44:44 2010 vivien botton
*/

#include "lib.h"

int		my_power_rec(int nb, int power)
{
  if (power < 0)
    return (0);
  if (power == 0)
    return (1);
  if (power > 1)
    nb = nb * my_power_rec(nb, power - 1);
  return (nb);
}
