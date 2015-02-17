/*
** ramutils.c for corewar in /u/all/botton_v/cu/test/corewar/vm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:12:11 2010 vivien botton
** Last update Fri Mar 26 11:12:13 2010 vivien botton
*/

#if defined (WIN32)
# include <windows.h>
#else
# include <unistd.h>
#endif
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "op.h"
#include "vm.h"
#include "graph.h"
#include "lib.h"

int		get_regvalue(t_prog *prog, int id)
{
  unsigned int	res;
  int		decal;
  int		index;
  unsigned char *reg;

  if (id < 1 || id > 16)
    return (0);
  reg = prog->regs[id - 1];
  decal = 0;
  res = 0;
  index = REG_SIZE - 1;
  while (index >= 0)
    {
      res += reg[index] << decal;
      index--;
      decal += 8;
    }
  return (res);
}

void		write_in_reg(t_prog *prog, int id, int nb)
{
  unsigned char	*reg;
  int		i;
  int		size;

  if (id < 1 || id > 16)
    return ;
  reg = prog->regs[id - 1];
  i = 0;
  size = REG_SIZE;
  while (--size >= 0)
    {
      reg[size] = (nb >> (i * 8)) & 255;
      i++;
    }
}

int		get_ramvalue(unsigned char *ram, int pos, int size)
{
  int		nb;
  int		i;
  int		mem;

  mem = size;
  nb = 0;
  if (pos < 0)
    pos = pos / MEM_SIZE * MEM_SIZE + MEM_SIZE;
  i = 0;
  while (--size >= 0)
    {
      nb += ram[(pos + i) % MEM_SIZE] << (size * 8);
      i++;
    }
  if (mem == IND_SIZE && nb >> (IND_SIZE * 8 - 1))
    nb -= (1 << (IND_SIZE * 8));
  return (nb);
}

void		set_pci(t_prog *prog, int jump)
{
  prog->pc += jump;
  if (prog->pc < 0)
    prog->pc += MEM_SIZE;
  else if (prog->pc >= MEM_SIZE)
    prog->pc %= MEM_SIZE;
}

int		check_mem_space(t_player *players)
{
  int		sum;
  t_player	*cpy;

  sum = 0;
  cpy = players;
  while (players)
    {
      sum += players->prog_size;
      players = players->next;
    }
  if (sum < MEM_SIZE)
    return (0);
  while (cpy)
    {
      players = cpy;
      close(players->nbprocess);
      free(players->prog_name);
      free(players->comment);
      cpy = cpy->next;
      free(players);
    }
  my_perror(MEM_ERROR);
  return (1);
}
