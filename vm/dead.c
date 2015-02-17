/*
** dead.c for corewar in /u/all/botton_v/cu/projects/corewar/vm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Sun Mar 28 21:02:43 2010 vivien botton
** Last update Mon Mar 29 08:02:31 2010 vivien botton
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "op.h"
#include "vm.h"

void		check_last_player(t_prog **prog, t_player *players)
{
  int		alone;

  alone = 0;
  while (players)
    {
      if (players->nbprocess > 0)
	alone++;
      if (alone > 1)
	return ;
      players = players->next;
    }
  free_progs(*prog);
  *prog = 0;
}

void		change_ptr(t_prog **old, t_prog **progs)
{
  *old = *progs;
  *progs = (*progs)->next;
}

void		ctrl_if_dead(t_prog *progs, t_prog **prog)
{
  t_prog	*cpy;
  t_prog	*old;

  old = 0;
  while (progs)
    {
      if ((*prog)->alive == 0)
	{
	  cpy = progs;
	  progs = progs->next;
	  *prog = (*prog)->next;
	  (cpy->header->nbprocess)--;
	  free(cpy);
	}
      else if (progs->alive == 0)
	{
	  old->next = progs->next;
	  cpy = progs;
	  progs = progs->next;
	  (cpy->header->nbprocess)--;
	  free(cpy);
	}
      else
	change_ptr(&old, &progs);
    }
}

void		reset_live(t_prog **progs, t_player *players, int *e)
{
  t_prog	*cpy;

  ctrl_if_dead(*progs, progs);
  check_last_player(progs, players);
  cpy = *progs;
  while (cpy)
    {
      cpy->alive = 0;
      cpy = cpy->next;
    }
  *e = 0;
}
