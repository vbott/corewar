/*
** instructions1.c for corewar in /u/epitech_2014/botton_v/public/philippelevegetarien/backup2
** 
** Made by philippe berenguel
** Login   <bereng_p@epitech.net>
** 
** Started on  Thu Jan 28 10:51:52 2010 philippe berenguel
** Last update Tue Feb 16 15:57:02 2010 vivien botton
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "op.h"
#include "vm.h"

void		write_in_ram(unsigned char *ram, int pos, int value)
{
  if (pos < 0)
    pos = pos / MEM_SIZE * MEM_SIZE + MEM_SIZE;
  ram[pos % MEM_SIZE] = value >> 24;
  ram[(pos + 1) % MEM_SIZE] = (value >> 16) & 255;
  ram[(pos + 2) % MEM_SIZE] = (value >> 8) & 255;
  ram[(pos + 3) % MEM_SIZE] = value & 255;
}
