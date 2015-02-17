/*
** my_putchar_fd.c for corewar in /u/all/botton_v/cu/test/corewar/dasm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>                       
** 
** Started on  Fri Mar 26 11:32:17 2010 vivien botton
** Last update Fri Mar 26 11:32:18 2010 vivien botton
*/

#if defined (WIN32)
# include <windows.h>
#else
# include <stdlib.h>
# include <unistd.h>
#endif
#include "lib.h"

void		my_putchar_fd(char c, int fd)
{
  if (write(fd, &c, 1) == -1)
    my_perror("Write error\n");
}
