/*
** get_arg.c for corewar in /u/all/botton_v/cu/test/corewar/dasm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:32:50 2010 vivien botton
** Last update Fri Mar 26 11:32:50 2010 vivien botton
*/

#include "op.h"
#include "lib.h"

int		get_arg(int fd, int size)
{
  int		i;
  int		nb;
  int		mem;
  unsigned char	buffer[32];

  mem = size;
  i = xread(fd, buffer, size);
  if (i != size)
    return (0);
  i = 0;
  nb = 0;
  while (--size >= 0)
    {
      nb += buffer[i] << (size * 8);
      i++;
    }
  if (mem == IND_SIZE && nb >> (IND_SIZE * 8 - 1))
    {
      nb = nb << ((sizeof(nb) - IND_SIZE) * 8);
      nb = nb >> ((sizeof(nb) - IND_SIZE) * 8);
    }
  return (nb);
}
