/*
** ldi.c for corewar in /u/all/botton_v/cu/test/corewar/vm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:12:28 2010 vivien botton
** Last update Mon Mar 29 08:07:26 2010 vivien botton
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "op.h"
#include "vm.h"
#include "graph.h"
#include "lib.h"

void		loadi(t_prog *prog, unsigned char *ram,
		      int isshort, t_param *para)
{
  int		pc;
  int		param;
  int		pos;
  int		value;

  pc = prog->pc - 1;
  param = ram[prog->pc];
  set_pci(prog, 1);
  pos = get_value_param(prog, ram, param >> 6, 1);
  if (param >> 6 == 3)
    pos = get_ramvalue(ram, pc + pos % IDX_MOD, IND_SIZE);
  if (para->verbose)
    my_printf("[%6d %6d] : ldi %d,", para->cycles, pc, pos);
  pos += get_value_param(prog, ram, (param & MIDDLE) >> 4, 1);
  if (isshort)
    value = get_ramvalue(ram, (pc + (pos % IDX_MOD)), REG_SIZE);
  else
    value = get_ramvalue(ram, pc + pos, REG_SIZE);
  write_in_reg(prog, ram[prog->pc], value);
  prog->carry = (value) ? 0 : 1;
  if (para->verbose)
    my_printf("%d,r%d S = %d (carry = %d)\n",
       pos, ram[prog->pc], value, prog->carry);
  set_pci(prog, 1);
}

void		lldi(t_prog *prog, unsigned char *ram, t_param *para)
{
  loadi(prog, ram, 0, para);
}

void		ldi(t_prog *prog, unsigned char *ram, t_param *para)
{
  loadi(prog, ram, 1, para);
}
