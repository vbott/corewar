/*
** xread.c for corewar in /u/all/botton_v/cu/test/corewar/lib
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:15:03 2010 vivien botton
** Last update Fri Mar 26 11:16:10 2010 vivien botton
*/

#if defined (WIN32)
# include <windows.h>
#else
# include <stdlib.h>
# include <unistd.h>
#endif
#include "lib.h"

int		xread(int fd, void *buf, int count)
{
  int		nb;

  nb = read(fd, buf, count);
  if (nb == -1)
    {
      my_perror("Read failure\n");
      exit(EXIT_FAILURE);
    }
  return (nb);
}
