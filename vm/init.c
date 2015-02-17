/*
** init.c for  in /u/all/caille_c/cu/corewar/vm
** 
** Made by carole cailleux
** Login   <caille_c@epitech.net>
** 
** Started on  Mon Mar 22 11:54:57 2010 carole cailleux
** Last update Mon Mar 22 11:54:58 2010 carole cailleux
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "op.h"
#include "vm.h"
#include "lib.h"

int		get_param(int ac, int *arg, char **av, int index)
{
  if (index >= ac)
    return (-1);
  if (av[index] && arg)
    *arg = my_getnbr(av[index]);
  if (arg && *arg <= 0)
    return (-1);
  if (!av[index] || dotcor(av[index]))
    return (-1);
  return (0);
}

int		load_params(int ac, char **av, int e, t_param *params)
{
  int		res;

  res = 0;
  if (!my_strcmp(&av[e][1], DUMP))
    res = get_param(ac, &(params->dump), av, e + 1);
  else if (!my_strcmp(&av[e][1], NOX))
    res = get_param(ac, &(params->nox), av, e + 1);
  else if (!my_strcmp(&av[e][1], CTMO))
    res = get_param(ac, &(params->ctmo), av, e + 1);
  else if (!my_strcmp(&av[e][1], ID))
    res = get_param(ac, NULL, av, e + 1);
  else if (!my_strcmp(&av[e][1], ADDR))
    res = get_param(ac, NULL, av, e + 1);
  else if (!my_strcmp(&av[e][1], FULLSCREEN))
    params->fullscreen = 1;
  else
    res = -2;
  return (res);
}

int		handle_params(int ac, char **av, t_param *params)
{
  int		e;
  int		res;

  e = 1;
  res = 0;
  while (e < ac && !res)
    {
      if (av[e][0] == '-')
	{
	  if (load_params(ac, av, e, params) != -2)
	    res = 0;
	  else if (!my_strcmp(&av[e][1], STEP))
	    params->bystep = 1;
	  else if (!my_strcmp(&av[e][1], VERBOSE))
	    (params->verbose)++;
	  else if (!my_strcmp(&av[e][1], COMMENT))
	    params->comment = 1;
	  else if (!my_strcmp(&av[e][1], X))
	    params->sdl = 0;
	  else
	    res = -1;
	}
      e++;
    }
  return (res);
}

void		init_params(t_param *params)
{
  params->sdl = 1;
  params->aff = 0;
  params->fullscreen = 0;
  params->ctmo = 0;
  params->bystep = 0;
  params->verbose = 0;
  params->dump = -1;
  params->nox = 0;
  params->comment = 0;
  params->quit = 1;
  params->cycles = 1;
  params->todie = CYCLE_TO_DIE;
  params->lastlive = NULL;
  params->lock = SDL_CreateMutex();
}

void		init_ram(unsigned char *ram)
{
  int		i;

  i = 0;
  while (i < MEM_SIZE)
    ram[i++] = 0;
}
