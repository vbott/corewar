/*
** aff_text.c for corewar in /u/all/botton_v/cu/projects/corewar/vm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Sun Mar 28 20:56:20 2010 vivien botton
** Last update Sun Mar 28 20:56:21 2010 vivien botton
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "lib.h"
#include "op.h"
#include "vm.h"
#include "graph.h"

void		aff_name(t_param *param, char *str, int x, int y)
{
  SDL_Surface   *texte;
  SDL_Rect      pos;
  SDL_Color     color;

  color.r = 255;
  color.g = 255;
  color.b = 255;
  pos.x = x;
  pos.y = y;
  texte = xttf_rendertext_blended(param->graphic->font, str, color);
  xsdl_blitsurface(texte, NULL, param->graphic->screen, &pos);
  SDL_FreeSurface(texte);
}

void		aff_text(t_param *param, char *str, int x, int y)
{
  SDL_Surface	*texte;
  SDL_Rect	pos;
  SDL_Color	color;

  color.r = 255;
  color.g = 255;
  color.b = 255;
  pos.x = x + 15;
  pos.y = y - 7;
  texte = xttf_rendertext_blended(param->graphic->font, str, color);
  xsdl_blitsurface(texte, NULL, param->graphic->screen, &pos);
  SDL_FreeSurface(texte);
}

void		if_no_player(int *y, SDL_Surface *screen, int *i)
{
  SDL_Surface	*closed;
  SDL_Rect	pos;

  pos.x = 974;
  pos.y = *y;
  closed = ximg_load("../graphic/closed.jpg");
  xsdl_blitsurface(closed, NULL, screen, &pos);
  SDL_FreeSurface(closed);
  *y += 52;
  *i += 1;
}

void		aff_names(t_prog *prog, t_param *param)
{
  int		y;
  char		stock;
  int		i;

  y = 275;
  i = 0;
  stock = 0;
  while (prog)
    {
      if (my_strlen(prog->header->prog_name) > 17)
	{
	  stock = prog->header->prog_name[16];
	  prog->header->prog_name[16] = '\0';
	}
      aff_name(param, prog->header->prog_name, 980, y);
      prog->header->prog_name[16] = stock;
      y += 52;
      prog = prog->next;
      i++;
    }
  y -= 11;
  while (i < 12)
    if_no_player(&y, param->graphic->screen, &i);
}
