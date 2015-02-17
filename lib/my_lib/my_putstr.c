/*
** my_putstr.c for corewar in /u/all/botton_v/cu/test/corewar/lib
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:17:08 2010 vivien botton
** Last update Fri Mar 26 11:17:09 2010 vivien botton
*/

#if defined (WIN32)
# include <windows.h>
#else
# include <stdlib.h>
# include <unistd.h>
#endif
#include "lib.h"

void		my_putstr(char *str)
{
  if (write(1, str, my_strlen(str)) == -1)
    my_perror("Write failure\n");
}
