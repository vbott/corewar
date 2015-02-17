/*
** my_putstrimp.c for my_printf in /u/all/botton_v/cu/rendu/c/printf3
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Thu Nov 26 13:47:49 2009 vivien botton
** Last update Fri Nov 27 17:04:19 2009 vivien botton
*/

#include "my.h"

void            octal(char nb)
{
  static int    b;

  if (b < 3)
    {
      b++;
      octal(nb / 8);
      put_char(nb % 8 + '0');
    }
}

void            putstrimp(char *str)
{
  int           i;

  i = 0;
  if (str)
    {
      while (str[i] != '\0')
        {
          if (str[i] < 32 || str[i] >= 127)
            {
              put_char('\\');
              octal(str[i]);
            }
          else
            put_char(str[i]);
          i++;
        }
    }
  else
    putstr("(null)");
}
