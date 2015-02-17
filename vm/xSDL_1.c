/*
** xSDL_1.c for corewar in /u/all/botton_v/cu/projects/corewar/vm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Sun Mar 28 20:53:59 2010 vivien botton
** Last update Mon Mar 29 08:08:59 2010 vivien botton
*/

#if defined (WIN32)
# include <windows.h>
#else
# include <stdlib.h>
#endif
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "lib.h"

void		my_swap(int *x, int *y)
{
  int		t;

  t = *x;
  *x = *y;
  *y = t;
}

SDL_Surface	*ximg_load(const char *file)
{
  SDL_Surface	*surface;

  surface = IMG_Load(file);
  if (surface == NULL)
    {
      my_perror(SDL_GetError());
      exit(EXIT_FAILURE);
    }
  return (surface);
}

int		xsdl_flip(SDL_Surface *screen)
{
  int		res;

  res = SDL_Flip(screen);
  if (res == -1)
    my_perror("SDL_Flip failure.\n");
  return (res);
}

int		xsdl_blitsurface(SDL_Surface *src, SDL_Rect *srcrect,
				 SDL_Surface *dst, SDL_Rect *dstrect)
{
  int		res;

  res = SDL_BlitSurface(src, srcrect, dst, dstrect);
  if (res == -1 || res == -2)
    {
      my_perror(SDL_GetError());
      my_perror("\n");
    }
  return (res);
}

int		xsdl_fillrect(SDL_Surface *dst, SDL_Rect *dstrect,
			      Uint32 color)
{
  int		i;

  i = SDL_FillRect(dst, dstrect, color);
  if (i == -1)
    {
      my_perror("SDL_FillRect failure.\n");
      exit(EXIT_FAILURE);
    }
  return (i);
}
