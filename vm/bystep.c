/*
** bystep.c for corewar in /u/all/botton_v/cu/test/corewar/vm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:13:23 2010 vivien botton
** Last update Fri Mar 26 11:13:25 2010 vivien botton
*/

#if defined (WIN32)
# include <windows.h>
#else
# include <unistd.h>
# include <termios.h>
# include <sys/ioctl.h>
# include "termcaps.h"
#endif
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "op.h"
#include "vm.h"


void			no_echo()
{
#ifndef WIN32
  struct termios        t;

  ioctl(0, TIOCGETA, &t);
  t.c_lflag &= ~(ECHO);
  ioctl(0, TIOCSETA, &t);
#endif 
}

void			list_keys(t_param *params, int c, int *cont)
{
  if (c == ' ' || c == SDLK_RETURN)
    *cont = 0;
  else if (c == 's')
    params->bystep = !params->bystep;
  else if (c == 'v')
    params->verbose = !params->verbose;
  else if (c == SDLK_ESCAPE)
    {
      *cont = 0;
      params->quit = 0;
    }
}

void			handle_keys(t_param *params, int wait)
{
  SDL_Event		event;
  int			cont;
  int			res;
  int			(*eventmanager)(SDL_Event*);

  eventmanager = (wait) ? SDL_WaitEvent : SDL_PollEvent;
  cont = 1;
  while (cont > 0)
    {
      if ((res = eventmanager(&event)))
	{
	  if (event.type == SDL_QUIT)
	    {
	      params->quit = 0;
	      cont = 0;
	    }
	  else if (event.type == SDL_KEYDOWN)
	    list_keys(params, event.key.keysym.sym, &cont);
	}
      if (!wait)
	cont = res;
    }
}

void			key_start()
{
  SDL_Event		event;
  int			cont;
 
  cont = 1;
  while (cont)
    {
      if (SDL_WaitEvent(&event) && event.type == SDL_KEYDOWN)
	cont = 0;
      while (SDL_PollEvent(&event));
    }
}

void			by_step(t_param *params)
{
  char		 	c;

  if (params->sdl)
    handle_keys(params, 1);
  else
    {
      c = 0;
      while (c != '\n' && c != ' ')
	read(0, &c, 1);
    }
}

