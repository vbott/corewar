/*
** xremove.c for corewar in /u/all/botton_v/cu/test/corewar/lib
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:14:49 2010 vivien botton
** Last update Fri Mar 26 11:14:51 2010 vivien botton
*/

#if defined (WIN32)
# include <windows.h>
#else
# include <stdlib.h>
# include <unistd.h>
#endif
#include <stdio.h>
#include "lib.h"

void		xremove(const char *str)
{
  if (remove(str))
    my_putstr("Remove failed\n");
}
