/*
** xlseek.c for corewar in /u/all/botton_v/cu/test/corewar/lib
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:15:50 2010 vivien botton
** Last update Fri Mar 26 11:15:51 2010 vivien botton
*/

#if defined (WIN32)
# include <windows.h>
#else
# include <stdlib.h>
# include <unistd.h>
#endif
#include <sys/types.h>

off_t		xlseek(int fd, off_t offset, int whence)
{
  off_t		check;

  check = lseek(fd, offset, whence);
  if (check == -1)
    {
      write(2, "Error with lseek.\n", 19);
      exit(EXIT_FAILURE);
    }
  return (check);
}
