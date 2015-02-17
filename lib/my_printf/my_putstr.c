/*
** my_putstr.c for my_putstr.c in /u/all/botton_v/cu/rendu/c/my_printf
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Tue Nov 17 14:27:40 2009 vivien botton
** Last update Fri Dec 18 10:34:00 2009 vivien botton
*/

#include <unistd.h>
#include "my.h"

void		putstr(char *str)
{
  extern int	gl_total;

  gl_total += write(1, str, strlenp(str, -1));
}

void		putstrp(char *str, int precision)
{
  int		i;
  extern int    gl_total;

  i = 0;
  if (precision >= 0)
    gl_total += write(1, str, precision);
  else
    gl_total += write(1, str, strlenp(str, -1));
}
