/*
** my_putchar.c for corewar in /u/all/botton_v/cu/test/corewar/lib
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:17:23 2010 vivien botton
** Last update Fri Mar 26 11:17:25 2010 vivien botton
*/

#if defined (WIN32)
# include <windows.h>
#else
# include <stdlib.h>
# include <unistd.h>
#endif
#include "lib.h"

void		my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    my_perror("Write failure\n");
}
