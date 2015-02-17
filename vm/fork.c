/*
** fork.c for corewar in /u/all/botton_v/cu/projects/corewar/vm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Sun Mar 28 21:13:47 2010 vivien botton
** Last update Mon Mar 29 08:02:57 2010 vivien botton
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "op.h"
#include "vm.h"
#include "lib.h"
#include "graph.h"

void		copy_regs(t_prog *src, t_prog *dest)
{
  int		i;
  int		e;

  i = 0;
  while (i < REG_NUMBER)
    {
      e = 0;
      while (e < REG_SIZE)
	{
	  dest->regs[i][e] = src->regs[i][e];
	  e++;
	}
      i++;
    }
}

void		insert_prog(t_prog *prog, unsigned char *ram,
			    t_param *para, int mode)
{
  t_prog        *cpy;
  int		pc;
  int		value;

  pc = prog->pc - 1;
  cpy = prog->next;
  prog->next = xmalloc(sizeof(*prog));
  prog->next->carry = prog->carry;
  value = get_ramvalue(ram, prog->pc, IND_SIZE);
  if (mode)
    value %= IDX_MOD;
  copy_regs(prog, prog->next);
  prog->next->pc = (pc + value) % MEM_SIZE;
  prog->next->header = prog->header;
  prog->header->nbprocess += 1;
  prog->next->alive = 1;
  prog->next->cycle = find_next_cycle(ram[prog->next->pc]);
  prog->next->next = cpy;
  if (para->sdl)
    aff_actions(prog->next, X_FORK, para, prog->next->pc);
  if (para->verbose)
    printf("[%6d %6d] : %s (%d)\n",
	     para->cycles, pc, ((mode) ? "fork" : "lfork"), value);
  prog->pc = (prog->pc + IND_SIZE) % MEM_SIZE;
}

void		vmfork(t_prog *prog, unsigned char *ram, t_param *para)
{
  insert_prog(prog, ram, para, 1);
}

void		lfork(t_prog *prog, unsigned char *ram, t_param *para)
{
  insert_prog(prog, ram, para, 0);
}
