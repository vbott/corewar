/*
** and.c for corewar in /u/all/botton_v/cu/test/corewar/vm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:13:31 2010 vivien botton
** Last update Fri Mar 26 11:13:33 2010 vivien botton
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "op.h"
#include "vm.h"
#include "graph.h"
#include "lib.h"

void		and(t_prog *prog, unsigned char *ram, t_param *para)
{
  unsigned int	a;
  unsigned int  b;
  unsigned int  res;
  int		param;
  int		pc;

  pc = prog->pc - 1;
  param = ram[prog->pc];
  prog->pc = (prog->pc + 1) % MEM_SIZE;
  a = get_value_param(prog, ram, param >> 6, 0);
  if (param >> 6 == 3)
    a = get_ramvalue(ram, pc + a % IDX_MOD, IND_SIZE);
  b = get_value_param(prog, ram, (param & MIDDLE) >> 4, 0);
  if ((param & MIDDLE) >> 4 == 3)
    b = get_ramvalue(ram, pc + b % IDX_MOD, IND_SIZE);
  res = a & b;
  write_in_reg(prog, ram[prog->pc], res);
  prog->carry = (res) ? 0 : 1;
  if (para->verbose)
    printf("[%6d %6d] : and %d,%d,r%d <- %d (carry = %d)\n",
	 para->cycles, pc, a, b, ram[prog->pc], res, prog->carry);
  prog->pc = (prog->pc + 1) % MEM_SIZE;
}

void		or(t_prog *prog, unsigned char *ram, t_param *para)
{
  unsigned int  a;
  unsigned int  b;
  unsigned int  res;
  int           param;
  int		pc;

  pc = prog->pc - 1;
  param = ram[prog->pc];
  prog->pc = (prog->pc + 1) % MEM_SIZE;
  a = get_value_param(prog, ram, param >> 6, 0);
  if (param >> 6 == 3)
    a = get_ramvalue(ram, pc + a % IDX_MOD, IND_SIZE);
  b = get_value_param(prog, ram, (param & MIDDLE) >> 4, 0);
  if ((param & MIDDLE) >> 4 == 3)
    b = get_ramvalue(ram, pc + b % IDX_MOD, IND_SIZE);
  res = a | b;
  write_in_reg(prog, ram[prog->pc], res);
  prog->carry = (res) ? 0 : 1;
  if (para->verbose)
    printf("[%6d %6d] : or %d,%d,r%d <- %d (carry = %d)\n",
	      para->cycles, pc, a, b, ram[prog->pc], res, prog->carry);
  prog->pc = (prog->pc + 1) % MEM_SIZE;
}

void		xor(t_prog *prog, unsigned char *ram, t_param *para)
{
  unsigned int  a;
  unsigned int  b;
  unsigned int  res;
  int           param;
  int		pc;

  pc = prog->pc - 1;
  param = ram[prog->pc];
  prog->pc = (prog->pc + 1) % MEM_SIZE;
  a = get_value_param(prog, ram, param >> 6, 0);
  if (param >> 6 == 3)
    a = get_ramvalue(ram, pc + a % IDX_MOD, IND_SIZE);
  b = get_value_param(prog, ram, (param & MIDDLE) >> 4, 0);
  if ((param & MIDDLE) >> 4 == 3)
    b = get_ramvalue(ram, pc + b % IDX_MOD, IND_SIZE);
  res = a ^ b;
  write_in_reg(prog, ram[prog->pc], res);
  prog->carry = (res) ? 0 : 1;
  if (para->verbose)
    printf("[%6d %6d] : xor %d,%d,r%d <- %d (carry = %d)\n",
	      para->cycles, pc, a, b, ram[prog->pc], res, prog->carry);
  prog->pc = (prog->pc + 1) % MEM_SIZE;
}

