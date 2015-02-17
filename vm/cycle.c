/*
** cycle.c for  in /u/epitech_2014/cerisi_m/public/group/corewar/vm
** 
** Made by carole cailleux
** Login   <caille_c@epitech.net>
** 
** Started on  Mon Feb  1 14:16:41 2010 carole cailleux
** Last update Mon Mar 29 08:02:13 2010 vivien botton
*/

#if defined (WIN32)
# include <windows.h>
#else
# include <unistd.h>
# include <stdlib.h>
#endif
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "op.h"
#include "vm.h"
#include "lib.h"
#include "graph.h"

void		fight(t_prog *progs, unsigned char *ram,
		      int *nblive, t_param *params)
{
  t_prog	*all;

  all = progs;
  while (progs)
    {
      (progs->cycle)--;
      if (!(progs->cycle))
	{
	  if (ram[progs->pc] != op_tab[0].code)
	    do_cmd(progs, ram, params);
	  else
	    {
	      progs->pc = (progs->pc + 1) % MEM_SIZE;
	      live(progs, ram, all, params);
	      *nblive = *nblive + 1;
	    }
	  progs->cycle = find_next_cycle(ram[progs->pc]);
	}
      progs = progs->next;
    }
}

void		close_door(t_player *players, t_param *para, int i)
{
  para->graphic->to_close.x = 974;
  para->graphic->to_close.y = 212 + i * 52;
  para->graphic->close_door.x = 212 - 28;
  para->graphic->close_door.y = 0;
  para->graphic->close_door.w = 28;
  para->graphic->close_door.h = 52;
  para->graphic->closing = 0;
  players->nbprocess = -1;
}

void		who_isalive(t_player *players, t_param *params)
{
  int		nbprocess;
  char		buf[10];
  int		i;

  nbprocess = 0;
  i = 1;
  while (players)
    {
      nbprocess += players->nbprocess;
      if (!players->nbprocess)
	close_door(players, params, i);
      players = players->next;
      i++;
    }
  int_to_str(nbprocess, buf);
  aff_text(params, buf, 1053, 182);
}

void		handle_options(t_param *params, t_player *players,
			       t_prog *progs, int nbrlive)
{
  char		buf[10];
  SDL_Rect	fade;

  if (params->bystep)
    by_step(params);
  if (params->ctmo)
    (params->ctmo)--;
  if (params->nox)
    (params->nox)--;
  if (params->sdl && progs != NULL && progs->cycle % 10 == 0)
    {
      fade.x = 974;
      fade.y = 60;
      fade.w = 211;
      fade.h = 59;
      /*SDL_mutexP(params->lock);*/
      xsdl_blitsurface(params->graphic->clip, NULL, params->graphic->screen,
		       &fade);
      int_to_str(params->cycles, buf);
      aff_text(params, buf, 1045, 87);
      int_to_str(params->todie, buf);
      aff_text(params, buf, 1083, 150);
      int_to_str(nbrlive, buf);
      aff_text(params, buf, 1053, 117);
      who_isalive(players, params);
      /*SDL_mutexV(params->lock);*/
    }
  /*if (params->sdl && progs != NULL && progs->cycle % 100 == 0)
    timer_func(0, params);*/
}

void		cycle(t_prog *progs, t_player *players,
		      unsigned char *ram, t_param *params)
{
  int		i;
  int		e;
  int		max;

  i = 0;
  e = 0;
  max = (params->dump > 0) ? params->dump : MAX_CYCLES;
  while (params->cycles < max && progs && params->quit)
    {
      fight(progs, ram, &i, params);
      if (i >= NBR_LIVE)
	{
	  i = 0;
	  params->todie -= CYCLE_DELTA;
	}
      if (e >= params->todie)
	reset_live(&progs, players, &e);
      handle_options(params, players, progs, i);
      (params->cycles)++;
      e++;
    }
}
