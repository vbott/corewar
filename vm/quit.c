/*
** quit.c for corewar in /u/all/botton_v/cu/projects/corewar/vm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Sun Mar 28 20:55:26 2010 vivien botton
** Last update Sun Mar 28 20:55:28 2010 vivien botton
*/

#if defined (WIN32)
# include <windows.h>
#else
# include <stdlib.h>
#endif
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "op.h"
#include "vm.h"
#include "lib.h"

void		quit(t_prog *progs, t_player *players, t_param *params)
{
  free_list(players);
  free_progs(progs);
  TTF_CloseFont(params->graphic->font);
  TTF_Quit();
  SDL_Quit();
  exit(EXIT_SUCCESS);
}

int		grph_mode(t_glstruct *data)
{
  t_player	*players;
  int		i;

  players = data->players;
  i = 0;
  while (players)
    {
      i++;
      players = players->next;
    }
  if (!i)
    return (usage());
  if (i > 12 && data->params.sdl)
    {
      my_perror(GRPH_ERROR);
      free_list(data->players);
      return (1);
    }
  return (0);
}
