/*
** ld.c for corewar in /u/all/botton_v/cu/test/corewar/vm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:12:46 2010 vivien botton
** Last update Mon Mar 29 08:07:07 2010 vivien botton
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "op.h"
#include "vm.h"
#include "graph.h"
#include "lib.h"

void		load(t_prog *prog, unsigned char *ram,
		     int isshort, t_param *para)
{
  int		pos;
  int		value;
  int		param;
  int		pc;

  pc = prog->pc - 1;
  param = ram[prog->pc];
  prog->pc = (prog->pc + 1) % MEM_SIZE;
  value = get_value_param(prog, ram, param >> 6, 0);
  if (param >> 6 == 3)
    {
      if (isshort)
	pos = pc + (value % IDX_MOD);
      else
	pos = pc + value;
      value = get_ramvalue(ram, pos, REG_SIZE);
    }
  write_in_reg(prog, ram[prog->pc], value);
  prog->carry = (value) ? 0 : 1;
  if (para->verbose)
    printf("[%6d %6d] : ld %d,r%d (carry = %d)\n",
	    para->cycles, pc, value, ram[prog->pc], prog->carry);
  prog->pc = (prog->pc + 1) % MEM_SIZE;
}

void		ld(t_prog *prog, unsigned char *ram, t_param *para)
{
  load(prog, ram, 1, para);
}

void		lld(t_prog *prog, unsigned char *ram, t_param *para)
{
  load(prog, ram, 0, para);
}

