/*
** st.c for corewar in /u/all/botton_v/cu/test/corewar/vm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:11:59 2010 vivien botton
** Last update Mon Mar 29 08:08:32 2010 vivien botton
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "op.h"
#include "vm.h"
#include "graph.h"
#include "lib.h"

int		is_validctmo(t_prog *prog, int pos)
{
  if ((pos >= prog->header->start
       && pos <= prog->header->start + prog->header->prog_size))
    return (1);
  return (0);
}

void		sti(t_prog *prog, unsigned char *ram, t_param *para)
{
  int		pos[2];
  int		r;
  int		param;
  int		pc;

  pc = prog->pc - 1;
  param = ram[prog->pc];
  prog->pc = (prog->pc + 1) % MEM_SIZE;
  r = get_regvalue(prog, ram[prog->pc]);
  if (para->verbose)
    printf("[%6d %6d] : sti r%d=%d,", para->cycles, pc, ram[prog->pc], r);
  prog->pc = (prog->pc + 1) % MEM_SIZE;
  pos[0] = get_value_param(prog, ram, (param & MIDDLE) >> 4, 1);
  if ((param & MIDDLE) >> 4 == 3)
    pos[0] = get_ramvalue(ram, pc + pos[0] % IDX_MOD, IND_SIZE);
  pos[1] = get_value_param(prog, ram, (param & LAST) >> 2, 1);
  if (para->verbose)
    printf("%d, %d\n", pos[0], pos[1]);
  pos[0] = (pc + (pos[1] + pos[0]) % IDX_MOD);
  if (!(para->ctmo) || is_validctmo(prog, pos[0]))
    write_in_ram(ram, pos[0], r);
  if (para->sdl)
    aff_actions(prog, X_STI, para, pos[0]);
}

void		st_reg(t_prog *prog, unsigned char *ram,
		       t_param *para, int value)
{
  write_in_reg(prog, ram[prog->pc], value);
  if (para->verbose)
    printf("r%d <- %d\n", ram[prog->pc], value);
  prog->pc = (prog->pc + 1) % MEM_SIZE;
}

void		st(t_prog *prog, unsigned char *ram, t_param *para)
{
  int		pos;
  int		value;
  int		param;
  int		pc;

  pc = prog->pc - 1;
  param = ram[prog->pc];
  prog->pc = (prog->pc + 1) % MEM_SIZE;
  value = get_regvalue(prog, ram[prog->pc]);
  if (para->verbose)
    printf("[%6d %6d] : st r%d=%d,", para->cycles, pc, ram[prog->pc], value);
  prog->pc = (prog->pc + 1) % MEM_SIZE;
  if ((param & MIDDLE) >> 4 == 3)
    {
      pos = pc + get_ramvalue(ram, prog->pc, IND_SIZE) % IDX_MOD;
      if (!(para->ctmo) || is_validctmo(prog, pos))
	write_in_ram(ram, pos, value);
      if (para->verbose)
	printf("%%%d\n", pos - pc);
      if (para->sdl)
	aff_actions(prog, X_ST, para, pos);
      prog->pc = (prog->pc + IND_SIZE) % MEM_SIZE;
    }
  else
    st_reg(prog, ram, para, value);
}

