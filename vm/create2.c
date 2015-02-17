/*
** create2.c for corewar in /u/all/botton_v/cu/projects/corewar/vm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Sun Mar 28 21:18:02 2010 vivien botton
** Last update Mon Mar 29 08:01:26 2010 vivien botton
*/

#if defined (WIN32)
# include <windows.h>
#else
# include <unistd.h>
#endif
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "lib.h"
#include "op.h"
#include "vm.h"

int		dotcor(char *name)
{
  int		i;

  i = 0;
  while (name[i])
    i++;
  if (i < 5)
    return (0);
  if (!my_strcmp(&name[i - 4], ".cor"))
    return (1);
  return (0);
}

int		is_corexec(int fd)
{
  int		nb;
  unsigned char buffer[4];
  int		magic;

  nb = read(fd, buffer, 4);
  magic = (nb == 4) ? get_ramvalue(buffer, 0, 4) : 0;
  return (magic == COREWAR_EXEC_MAGIC);
}

void		addr_id_option(t_initprog *id, char **av, t_player *player)
{
  if (!my_strcmp(&av[0][1], ID))
    attribute_id(&(id->nb), my_getnbr(av[1]), player);
  else if (!my_strcmp(&av[0][1], ADDR))
    {
      id->automode = 0;
      id->pos = my_getnbr(av[1]);
    }
}

void		init_prog(t_prog *prog, unsigned char *ram, t_initprog *id)
{
  prog->header->id = id->nb;
  if (!(id->automode))
    if (!is_putable(ram, id->pos, prog->header->prog_size))
      my_putstr(ERASE_WARNING);
  prog->pc = id->pos;
  prog->header->start = id->pos;
  prog->alive = 0;
  prog->carry = 0;
  if (id->pos + prog->header->prog_size >= MEM_SIZE)
    id->pos = 0;
  xread(prog->header->nbprocess, &ram[id->pos], prog->header->prog_size);
  close(prog->header->nbprocess);
  prog->header->nbprocess = 1;
  prog->cycle = find_next_cycle(ram[prog->pc]);
  clean_regs(prog);
  write_in_reg(prog, 1, id->nb);
  id->pos = (id->pos + id->decal) % MEM_SIZE;
  (id->nb)++;
}

void			init_create(t_initprog *id, int ac, char **av)
{
  id->nb = 1;
  id->pos = 0;
  id->automode = 1;
  id->decal = get_decal(ac, av);
}
