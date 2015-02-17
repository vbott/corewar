/*
** find_place.c for corewar in /u/all/botton_v/cu/projects/corewar/vm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Sun Mar 28 20:54:36 2010 vivien botton
** Last update Sun Mar 28 20:59:34 2010 vivien botton
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "op.h"
#include "vm.h"

int	      is_putable(unsigned char *ram, int pos, int size)
{
  int	      i;
  int	      sum;

  i = pos % MEM_SIZE;
  sum = i + size;
  while (i < sum)
    {
      if (ram[i] != 0)
	return (0);
      i++;
    }
  return (1);
}

