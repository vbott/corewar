/*
** xmalloc.c for corewar in /u/all/botton_v/cu/test/corewar/lib
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:15:43 2010 vivien botton
** Last update Fri Mar 26 11:15:45 2010 vivien botton
*/

#if defined (WIN32)
# include <windows.h>
#else
# include <stdlib.h>
# include <unistd.h>
#endif

void		*xmalloc(int size)
{
  void		*data;

  data = malloc(size);
  if (data == NULL)
    {
      write(2, "Malloc failure.\n", 16);
      exit(EXIT_FAILURE);
    }
  return (data);
}
