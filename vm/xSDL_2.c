/*
** xSDL_2.c for corewar in /u/all/botton_v/cu/projects/corewar/vm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Sun Mar 28 20:54:11 2010 vivien botton
** Last update Sun Mar 28 20:54:12 2010 vivien botton
*/

#if defined (WIN32)
# include <windows.h>
#else
# include <stdlib.h>
#endif
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "lib.h"

SDL_Surface	*xttf_rendertext_blended(TTF_Font *font, const char *text,
					 SDL_Color fg)
{
  SDL_Surface	*surface;

  surface = TTF_RenderText_Blended(font, text, fg);
  if (surface == NULL)
    {
      my_perror(SDL_GetError());
      my_perror("\n");
    }
  return (surface);
}

TTF_Font	*xttf_openfont(const char *file, int ptsize)
{
  TTF_Font	*font;

  font = TTF_OpenFont(file, ptsize);
  if (font == NULL)
    {
      my_perror("TTF_Openfont failure.\n");
      exit(EXIT_FAILURE);
    }
  return (font);
}

int		xttf_init()
{
  int		i;

  i = TTF_Init();
  if (i == -1)
    {
      my_perror("TTF_Init failure.\n");
      exit(EXIT_FAILURE);
    }
  return (i);
}

SDL_Surface	*xsdl_setvideomode(int width, int height, int bpp,
				   Uint32 flags)
{
  SDL_Surface	*surface;

  surface = SDL_SetVideoMode(width, height, bpp, flags);
  if (surface == NULL)
    {
      my_perror("SDL_SetVideoMode failure.\n");
      exit(EXIT_FAILURE);
    }
  return (surface);
}

int		xsdl_init(Uint32 flags)
{
  int		i;

  i = SDL_Init(flags);
  if (i == -1)
    {
      my_perror("SDL_Init failure.\n");
      exit(EXIT_FAILURE);
    }
  return (i);
}
