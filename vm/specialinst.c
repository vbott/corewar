/*
** func_3.c for  in /u/epitech_2014/cerisi_m/public/group/corewar/vm
** 
** Made by carole cailleux
** Login   <caille_c@epitech.net>
** 
** Started on  Mon Feb  1 15:01:54 2010 carole cailleux
** Last update Mon Mar 29 08:08:14 2010 vivien botton
*/

#if defined (WIN32)
# include <windows.h>
#else
# include <stdlib.h>
#endif
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "op.h"
#include "vm.h"
#include "graph.h"
#include "lib.h"

void		zjmp(t_prog *prog, unsigned char *ram, t_param *para)
{
  int		pc;
  int		value;
  int           coord[2];
  SDL_Rect	pos;

  pc = prog->pc - 1;
  value = get_ramvalue(ram, prog->pc, IND_SIZE) - 1;
  if (prog->carry)
    set_pci(prog, value % IDX_MOD);
  else
    prog->pc = (prog->pc + IND_SIZE) % MEM_SIZE;
  if (para->verbose)
    printf("[%6d %6d] : zjmp (%d) (carry = %d)\n",
	      para->cycles, pc, value + 1, prog->carry);
  if (para->sdl && prog->carry)
    {
      calc_block_pos(pc, para, &pos);
      coord[0] = pos.x;
      coord[1] = pos.y;
      aff_zjump(prog, para, coord);
    }
}

void		live(t_prog *prog, unsigned char *ram,
		     t_prog *all, t_param *para)
{
  int		id;
  t_prog	*wholive;

  id = get_ramvalue(ram, prog->pc, 4);
  wholive = NULL;
  if (id == prog->header->id)
    wholive = prog;
  else
    {
      while (all && all->header->id != id)
	all = all->next;
      wholive = all;
    }
  if (wholive)
    {
      para->lastlive = wholive->header;
      wholive->alive = 1;
    }
  if (para->verbose)
    printf("[%6d %6d] : live (%d)\n",
	      para->cycles, prog->pc - 1, id);
  if (para->sdl)
    aff_actions(wholive, X_LIVE, para, prog->pc);
  prog->pc = (prog->pc + 4) % MEM_SIZE;
}

