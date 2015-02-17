/*
** addsub.c for corewar in /u/all/botton_v/cu/test/corewar/vm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:13:44 2010 vivien botton
** Last update Mon Mar 29 08:00:51 2010 vivien botton
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "op.h"
#include "vm.h"
#include "graph.h"
#include "lib.h"

void		add(t_prog *prog, unsigned char *ram, t_param *para)
{
  int		a;
  int		b;
  int		sum;

  a = get_regvalue(prog, ram[(prog->pc + 1) % MEM_SIZE]);
  b = get_regvalue(prog, ram[(prog->pc + 2) % MEM_SIZE]);
  sum = a + b;
  write_in_reg(prog, ram[(prog->pc + 3) % MEM_SIZE], sum);
  prog->carry = (sum) ? 0 : 1;
  if (para->verbose)
    {
      printf("[%6d %6d] : add ", para->cycles, prog->pc - 1);
      printf("r%d=%d,r%d=%d,r%d", ram[(prog->pc + 1) % MEM_SIZE], a,
		ram[(prog->pc + 2) % MEM_SIZE], b,
		ram[(prog->pc + 3) % MEM_SIZE]);
      printf(" <- %d (carry = %d)\n", sum, prog->carry);
    }
  prog->pc = (prog->pc + 4) % MEM_SIZE;
}

void		sub(t_prog *prog, unsigned char *ram, t_param *para)
{
  int		a;
  int		b;
  int		sum;

  a = get_regvalue(prog, ram[(prog->pc + 1) % MEM_SIZE]);
  b = get_regvalue(prog, ram[(prog->pc + 2) % MEM_SIZE]);
  sum = a - b;
  write_in_reg(prog, ram[(prog->pc + 3) % MEM_SIZE], sum);
  prog->carry = (sum) ? 0 : 1;
  if (para->verbose)
    {
      printf("[%6d %6d] : sub ", para->cycles, prog->pc - 1);
      printf("r%d=%d,r%d=%d,r%d", ram[(prog->pc + 1) % MEM_SIZE], a,
		ram[(prog->pc + 2) % MEM_SIZE], b,
		ram[(prog->pc + 3) % MEM_SIZE]);
      printf(" <- %d (carry = %d)\n", sum, prog->carry);
    }
  prog->pc = (prog->pc + 4) % MEM_SIZE;
}
