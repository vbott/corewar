/*
** main.c for corewar in /u/all/botton_v/cu/projects/corewar/vm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Sun Mar 28 21:00:27 2010 vivien botton
** Last update Sun Mar 28 21:30:50 2010 vivien botton
*/

#if defined (WIN32)
# include <windows.h>
#else
# include <stdlib.h>
# include <unistd.h>
#endif
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "op.h"
#include "vm.h"
#include "lib.h"
#include "graph.h"

const t_func      	gl_function[] = {
  {live},
  {ld},
  {st},
  {add},
  {sub},
  {and},
  {or},
  {xor},
  {zjmp},
  {ldi},
  {sti},
  {vmfork},
  {lld},
  {lldi},
  {lfork},
  {aff},
  {gtmd}
};

int		find_next_cycle(int value)
{
  int		i;

  i = 0;
  while (op_tab[i].mnemonique)
    {
      if (op_tab[i].code == value)
	return (op_tab[i].nbr_cycles);
      i++;
    }
  return (1);
}

int		verif_arg(unsigned char param, int e)
{
  int		value;

  value = (param) >> 6;
  if (!(op_tab[e].type[0] & value))
    return (1);
  if (op_tab[e].nbr_args == 1)
    return (0);
  value = (param & MIDDLE) >> 4;
  if (!(op_tab[e].type[1] & value))
    return (1);
  if (op_tab[e].nbr_args == 2)
    return (0);
  value = (param & LAST) >> 2;
  if (!(op_tab[e].type[2] & value))
    return (1);
  return (0);
}

void		do_cmd(t_prog *progs, unsigned char *ram, t_param *params)
{
  int		e;

  e = 0;
  while (op_tab[e].mnemonique != 0)
    {
      if (op_tab[e].code == ram[progs->pc])
	{
	  progs->pc = (progs->pc + 1) % MEM_SIZE;
	  if (op_tab[e].needoctetparam && verif_arg(ram[progs->pc], e))
	    {
	      if (params->verbose)
		bad_arg(op_tab[e].mnemonique, progs->pc, params->cycles);
	      return ;
	    }
	  gl_function[e].func(progs, ram, params);
	  return ;
	}
      e++;
    }
  if (params->verbose)
    invalid_cmd(progs->pc, params->cycles);
  progs->pc = (progs->pc + 1) % MEM_SIZE;
  progs->cycle = 1;
}

void		init_main(t_glstruct *glstruct, unsigned char *ram)
{
  if (glstruct->params.bystep && !(glstruct->params.sdl))
    no_echo();
  if (glstruct->params.sdl)
    my_graph(glstruct, ram);
  else
    cycle(glstruct->progs, glstruct->players, ram, &(glstruct->params));
  if (glstruct->params.dump > 0)
    dump(ram);
  if (!glstruct->params.sdl)
    print_win(&(glstruct->params));
  if (glstruct->players)
    free_list(glstruct->players);
}

int		main(int ac, char **av)
{
  unsigned char	ram[MEM_SIZE];
  t_glstruct	glstruct;

  init_params(&(glstruct.params));
  if (handle_params(ac, av, &(glstruct.params)) || ac == 1)
    return (usage());
  glstruct.players = create_playerlist(ac, av);
  if (check_mem_space(glstruct.players) || grph_mode(&glstruct))
    return (EXIT_FAILURE);
  init_ram(ram);
  glstruct.progs = NULL;
  if (glstruct.players)
    glstruct.progs = create_proglist(ac, av, ram, glstruct.players);
  if (glstruct.progs == NULL || glstruct.players == NULL)
    return (EXIT_FAILURE);
  init_main(&glstruct, ram);
  return (EXIT_SUCCESS);
}

# if defined (WIN32)
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
  char	**args;

  args = malloc(4 * sizeof(*args));
  args[0] = "corewar.exe";
  args[1] = "42.cor";
  args[2] = "42.cor";
  args[3] =  NULL;
  main(3, args);
}
# endif
