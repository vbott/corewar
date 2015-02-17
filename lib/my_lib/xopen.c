/*
** xopen.c for corewar in /u/all/botton_v/cu/test/corewar/lib
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:15:14 2010 vivien botton
** Last update Fri Mar 26 11:15:32 2010 vivien botton
*/

#if defined (WIN32)
# include <windows.h>
#else
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
#endif
#include <fcntl.h>

int		xopen(char *path, int droit, int mode)
{
  int		fd;

  fd = open(path, droit, mode);
  if (fd == -1)
    {
      write(2, "No such file or directory\n", 26);
      exit(EXIT_FAILURE);
    }
  return (fd);
}
