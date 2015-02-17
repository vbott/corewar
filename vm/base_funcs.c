/*
** base_funcs.c for corewar in /u/all/bereng_p/cu/rendu/SVN/corewar/vm/visuals
** 
** Made by philippe berenguel
** Login   <bereng_p@epitech.net>
** 
** Started on  Fri Mar 26 00:26:46 2010 philippe berenguel
** Last update Sun Mar 28 20:56:51 2010 vivien botton
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "visuals.h"

static Uint32	getpixel(SDL_Surface *surface, int x, int y)
{
  int		bpp;
  Uint8		*p;

  bpp = surface->format->BytesPerPixel;
  p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
  if (bpp == 1)
    return (*p);
  else if (bpp == 2)
    return (*(Uint16 *)p);
  else if (bpp ==  3)
    {
      if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
	return (p[0] << 16 | p[1] << 8 | p[2]);
      else
	return (p[0] | p[1] << 8 | p[2] << 16);
    }
  else if (bpp == 4)
    return (*(Uint32 *)p);
  else
    return (0);
}

static void	putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
  int		bpp;
  Uint8		*p;

  bpp = surface->format->BytesPerPixel;
  p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
  if (bpp == 1)
    *p = pixel;
  else if (bpp == 2)
    *(Uint16 *)p = pixel;
  else if (bpp == 3 && SDL_BYTEORDER == SDL_BIG_ENDIAN)
    {
      p[0] = (pixel >> 16) & 0xff;
      p[1] = (pixel >> 8) & 0xff;
      p[2] = pixel & 0xff;
    }
  else if (bpp == 3)
    {
      p[0] = pixel & 0xff;
      p[1] = (pixel >> 8) & 0xff;
      p[2] = (pixel >> 16) & 0xff;
    }
  else if (bpp == 4)
    *(Uint32 *)p = pixel;
}

void		vline(int *coord, int height, SDL_Surface *surface, int color)
{
  int		co[4];

  co[0] = coord[0];
  co[1] = coord[1];
  co[2] = coord[0];
  co[3] = coord[1] + height;
  any_line(co, surface, color);
}

void		hline(int *coord, int width, SDL_Surface *surface, int color)
{
  int		co[4];

  co[0] = coord[0];
  co[1] = coord[1];
  co[2] = coord[0] + width;
  co[3] = coord[1];
  any_line(co, surface, color);
}

void		pixel_set(int x, int y, SDL_Surface *surface, int color)
{
  Uint32	pixel;
  Uint8         cs[4];

  if (x >= 0 && x < WINX && y >= 0 && y < WINY)
    {
      pixel = getpixel(surface, x, y);
      SDL_GetRGBA(pixel, surface->format, &cs[0], &cs[1], &cs[2], &cs[3]);
      cs[0] = (color >> 16) & 255;
      cs[1] = (color >> 8) & 255;
      cs[2] = color & 255;
      cs[3] = color >> 24;
      pixel = SDL_MapRGBA(surface->format, cs[0], cs[1], cs[2], cs[3]);
      putpixel(surface, x, y, pixel);
    }
}
