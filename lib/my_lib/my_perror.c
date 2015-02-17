/*
** my_perror.c for corewar in /u/all/botton_v/cu/test/corewar/lib
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:19:48 2010 vivien botton
** Last update Fri Mar 26 11:19:50 2010 vivien botton
*/

#if defined (WIN32)
# include <windows.h>
#else
# include <stdlib.h>
# include <unistd.h>
#endif
#include "lib.h"

void		my_perror(char *str)
{
  if (str != NULL)
    write(2, str, my_strlen(str));
}
