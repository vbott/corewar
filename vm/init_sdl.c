/*
** init_sdl.c for corewar in /u/all/botton_v/cu/projects/corewar/vm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Sun Mar 28 21:30:37 2010 vivien botton
** Last update Sun Mar 28 21:37:09 2010 vivien botton
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "op.h"
#include "vm.h"
#include "lib.h"
#include "graph.h"

Uint32			timer_func(Uint32 interv, void *param)
{
  t_param		*params;

  params = (t_param*)param;
  handle_keys(params, 0);
  /*SDL_mutexP(params->lock);*/
  if (!params->bystep)
    xsdl_blitsurface(params->graphic->disp, NULL, params->graphic->screen,
    NULL);
  if (params->graphic->closing < 8)
    {
      params->graphic->close_door.x -= 23;
      params->graphic->close_door.w += 23;
      xsdl_blitsurface(params->graphic->door,
		       &(params->graphic->close_door),
		       params->graphic->screen,
		       &(params->graphic->to_close));
      params->graphic->closing++;
    }
  xsdl_flip(params->graphic->screen);
  /*SDL_mutexV(params->lock);*/
  return (interv);
}

void		my_graph(t_glstruct *gl, unsigned char *ram)
{
  SDL_TimerID	timer_id;
  int		flag;

  flag = SDL_HWSURFACE | SDL_DOUBLEBUF;
  if (gl->params.fullscreen)
    flag |= SDL_FULLSCREEN;
  xsdl_init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
  gl->params.graphic = xmalloc(sizeof(*(gl->params.graphic)));
  calc_grid(&(gl->params));
  SDL_EnableKeyRepeat(20, 20);
  xttf_init();
  gl->params.graphic->font = xttf_openfont("radiof.ttf", 14);
  gl->params.graphic->screen = xsdl_setvideomode(WINX, WINY, BCOLOR, flag);
  gl->params.graphic->disp = SDL_CreateRGBSurface(
  SDL_SRCCOLORKEY | SDL_SRCALPHA, 960, 960, 32, RM, GM, BM, AM);
  xsdl_fillrect(gl->params.graphic->disp, NULL, FADING);
  SDL_WM_SetCaption(TITLE, NULL);
  load_right_blk(&(gl->params));
  aff_names(gl->progs, &(gl->params));
  timer_func(0, &(gl->params));
  key_start();
  timer_id = xsdl_addtimer(REFRESH_TIME, timer_func, &(gl->params));
  cycle(gl->progs, gl->players, ram, &(gl->params));
  SDL_RemoveTimer(timer_id);
  print_win(&(gl->params));
  if (gl->params.quit)
    handle_keys(&(gl->params), 1);
  SDL_FreeSurface(gl->params.graphic->door);
  TTF_CloseFont(gl->params.graphic->font);
  TTF_Quit();
  SDL_Quit();
}
