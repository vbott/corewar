/*
** my_getnbr.c for corewar in /u/all/botton_v/cu/test/corewar/lib
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:19:58 2010 vivien botton
** Last update Fri Mar 26 11:20:00 2010 vivien botton
*/

#include "lib.h"

int		my_getnbr(char *str)
{
  int		res;

  if (*str == '-')
    return (-my_getnbr(str + 1));
  if (*str == '+' || *str == ' ' || *str == '\t')
    return (my_getnbr(str + 1));
  res = 0;
  while (*str >= '0' && *str <= '9')
    {
      res = res * 10;
      res = res + *str - '0';
      str = str + 1;
    }
  return (res);
}
