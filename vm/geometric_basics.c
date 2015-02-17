/*
** geometric_basics.c for corewar in /u/all/bereng_p/cu/rendu/SVN/corewar/vm/visuals
** 
** Made by philippe berenguel
** Login   <bereng_p@epitech.net>
** 
** Started on  Fri Mar 26 00:26:56 2010 philippe berenguel
** Last update Sun Mar 28 20:59:03 2010 vivien botton
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <math.h>
#include "visuals.h"

void		circle(int *center, int rad, SDL_Surface *surface, int color)
{
  int		d;
  int		y;
  int		x;

  x = 0;
  y = rad;
  d = 3 - (2 * rad);
  while (y >= x)
    {
      pixel_set(center[0] + x, center[1] + y, surface, color);
      pixel_set(center[0] + y, center[1] + x, surface, color);
      pixel_set(center[0] - x, center[1] + y, surface, color);
      pixel_set(center[0] - y, center[1] + x, surface, color);
      pixel_set(center[0] + x, center[1] - y, surface, color);
      pixel_set(center[0] + y, center[1] - x, surface, color);
      pixel_set(center[0] - x, center[1] - y, surface, color);
      pixel_set(center[0] - y, center[1] - x, surface, color);
      if (d < 0)
	d = d + (4 * x) + 6;
      else
	d = d + 4 * (x - y--) + 10;
      x++;
    }
}

void		disk(int *center, int rad, SDL_Surface *surface, int color)
{
  int		coord[2];
  int		x;
  int		y;
  int		d;

  x = 0;
  y = rad;
  d = 3 - (2 * rad);
  while (y >= x)
    {
      coord[0] = center[0] - x;
      coord[1] = center[1] - y;
      hline(coord, 2 * x + 1, surface, color);
      coord[1] = center[1] + y;
      hline(coord, 2 * x + 1, surface, color);
      coord[0] = center[0] - y;
      coord[1] = center[1] - x;
      hline(coord, 2 * y + 1, surface, color);
      coord[1] = center[1] + x;
      hline(coord, 2 * y + 1, surface, color);
      if (d < 0)
	d = d + (4 * x++) + 6;
      else
	d = d + 4 * (x++ - y--) + 10;
    }
}

static void		v_axis(t_calc *calc, int *coord,
			       SDL_Surface *sfce, int color)
{
  if (coord[1] > coord[3])
    {
      my_swap(&coord[0], &coord[2]);
      my_swap(&coord[1], &coord[3]);
    }
  calc->xincr = coord[2] > coord[0] ? 1 : -1;
  calc->dy = coord[3] - coord[1];
  calc->dx = abs(coord[2] - coord[0]);
  calc->d = 2 * calc->dx - calc->dy;
  calc->aincr = 2 * (calc->dx - calc->dy);
  calc->bincr = 2 * calc->dx;
  calc->x = coord[0];
  calc->y = coord[1];
  pixel_set(calc->x, calc->y++, sfce, color);
  while (calc->y <= coord[3])
    {
      if (calc->d >= 0)
	{
	  calc->x += calc->xincr;
	  calc->d += calc->aincr;
	}
      else
	calc->d += calc->bincr;
      pixel_set(calc->x, calc->y++, sfce, color);
    }
}

static void		h_axis(t_calc *calc, int *coord,
			       SDL_Surface *sfce, int color)
{
  if (coord[0] > coord[2])
    {
      my_swap(&coord[0], &coord[2]);
      my_swap(&coord[1], &coord[3]);
    }
  calc->yincr = coord[3] > coord[1] ? 1 : -1;
  calc->dx = coord[2] - coord[0];
  calc->dy = abs(coord[3] - coord[1]);
  calc->d = 2 * calc->dy - calc->dx;
  calc->aincr = 2 * (calc->dy - calc->dx);
  calc->bincr = 2 * calc->dy;
  calc->x = coord[0];
  calc->y = coord[1];
  pixel_set(calc->x++, calc->y, sfce, color);
  while (calc->x <= coord[2])
    {
      if (calc->d >= 0)
	{
	  calc->y += calc->yincr;
	  calc->d += calc->aincr;
	}
      else
	calc->d += calc->bincr;
      pixel_set(calc->x++, calc->y, sfce, color);
    }
}

void		any_line(int *coord, SDL_Surface *surface, int color)
{
  t_calc	calc;
  int		co[4];

  co[0] = coord[0];
  co[1] = coord[1];
  co[2] = coord[2];
  co[3] = coord[3];
  if (abs(coord[2] - coord[0]) < abs(coord[3] - coord[1]))
    v_axis(&calc, co, surface, color);
  else
    h_axis(&calc, co, surface, color);
}
