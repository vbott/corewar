/*
** vmfuncs.c for corewar in /u/epitech_2014/cerisi_m/public/group/corewar/vm
** 
** Made by carole cailleux
** Login   <caille_c@epitech.net>
** 
** Started on  Mon Feb  1 16:16:32 2010 carole cailleux
** Last update Tue Feb 16 15:31:48 2010 vivien botton
*/

#if defined (WIN32)
# include <windows.h>
#else
# include <unistd.h>
# include <stdlib.h>
#endif
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "op.h"
#include "vm.h"
#include "graph.h"
#include "lib.h"

int		get_value_param(t_prog *prog, unsigned char *ram,
					int param, int indirect)
{
  int		res;

  if (param == 1)
    {
      res = get_regvalue(prog, ram[prog->pc]);
      set_pci(prog, 1);
      return (res);
    }
  else if (param == 2)
    {
      res = get_ramvalue(ram, prog->pc, (indirect) ? IND_SIZE : DIR_SIZE);
      set_pci(prog, (indirect) ? IND_SIZE : DIR_SIZE);
      return (res);
    }
  else if (param == 3)
    {
      res = get_ramvalue(ram, prog->pc, IND_SIZE);
      set_pci(prog, IND_SIZE);
      return (res);
    }
  return (0);
}

void		aff(t_prog *prog, unsigned char *ram, t_param *para)
{
  int		c;
  int		pc;

  pc = prog->pc - 1;
  c = get_regvalue(prog, ram[(prog->pc + 1) % MEM_SIZE]) % 256;
  if (para->verbose)
    printf("[%6d %6d] : aff %d -> %c\n", para->cycles, pc, c, c);
  set_pci(prog, 2);
  write(1, &c, 1);
}

void		gtmd(t_prog *prog, unsigned char *ram, t_param *para)
{
  int		pc;

  pc = prog->pc - 1;
  if (para->verbose)
    printf("[%6d %6d] : gtmd %d -> r%d\n", para->cycles, pc, para->ctmo,
	      ram[(prog->pc + 1) % MEM_SIZE]);
  write_in_reg(prog, ram[(prog->pc + 1) % MEM_SIZE], para->ctmo);
  set_pci(prog, 2);
}
