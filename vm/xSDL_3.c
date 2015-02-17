/*
** xSDL_3.c for corewar in /u/all/botton_v/cu/projects/corewar/vm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Mon Mar 29 07:52:28 2010 vivien botton
** Last update Mon Mar 29 07:52:28 2010 vivien botton
*/

#if defined (WIN32)
# include <windows.h>
#else
# include <stdlib.h>
#endif
#include <SDL/SDL.h>
#include "lib.h"

SDL_TimerID		xsdl_addtimer(Uint32 inter, SDL_NewTimerCallback cbk,
				      void *param)
{
  SDL_TimerID   timer_id;

  timer_id = SDL_AddTimer(inter, cbk, param);
  if (timer_id == NULL)
    {
      my_perror("SDL_AddTimer failure.\n");
      exit(EXIT_FAILURE);
    }
  return (timer_id);
}
