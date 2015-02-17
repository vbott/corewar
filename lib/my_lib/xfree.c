/*
** xfree.c for corewar in /u/all/botton_v/cu/test/corewar/lib
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:15:57 2010 vivien botton
** Last update Fri Mar 26 11:15:59 2010 vivien botton
*/

#if defined (WIN32)
# include <windows.h>
#else
# include <stdlib.h>
# include <unistd.h>
#endif

void		xfree(void *data)
{
  if (data != NULL)
    free(data);
}
