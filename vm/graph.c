/*
** graph.c for corewar in /u/all/botton_v/cu/projects/corewar/vm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Sun Mar 28 20:55:51 2010 vivien botton
** Last update Mon Mar 29 08:06:37 2010 vivien botton
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <math.h>
#include "op.h"
#include "vm.h"
#include "graph.h"

void		load_right_blk(t_param *param)
{
  SDL_Surface	*frame;
  SDL_Rect      pos;
  SDL_Rect	to_clip;

  frame = ximg_load("frame.jpg");
  pos.x = 960;
  pos.y = 0;
  to_clip.x = 14;
  to_clip.y = 66;
  to_clip.w = 211;
  to_clip.h = 150;
  param->graphic->clip = SDL_CreateRGBSurface(SDL_SRCCOLORKEY | SDL_SRCALPHA,
					      211, 150, 32, RM, GM, BM, AM);
  xsdl_blitsurface(frame, &to_clip, param->graphic->clip, NULL);
  xsdl_blitsurface(frame, NULL, param->graphic->screen, &pos);
  SDL_FreeSurface(frame);
  param->graphic->door = ximg_load("closed.jpg");
}

void   		calc_block_pos(int pc, t_param *para, SDL_Rect *pos)
{
  pos->x = (pc % para->graphic->nb_grid) * para->graphic->size_block;
  pos->y = (pc / para->graphic->nb_grid) * para->graphic->size_block;
  /*pos->x = (int)(pc * para->graphic->size_block) % WINY;
    pos->y = (pc * para->graphic->size_block) / WINY;*/
}

void		calc_grid(t_param *param)
{
  param->graphic->size_block = sqrt((WINY * WINY) / MEM_SIZE);
  param->graphic->halfsize_blk = param->graphic->size_block / 2;
  param->graphic->nb_grid = WINY / param->graphic->size_block;
}

void		aff_zjump(t_prog *prog, t_param *para, int *co)
{
  int		coord[4];
  SDL_Rect	pos;
  int		colour;

  colour = prog->header->color + 0xFF000000;
  coord[0] = co[0] + para->graphic->halfsize_blk;
  coord[1] = co[1] + para->graphic->halfsize_blk;
  calc_block_pos(prog->pc, para, &pos);
  coord[2] = pos.x + para->graphic->halfsize_blk;
  coord[3] = pos.y + para->graphic->halfsize_blk;
  any_line(coord, para->graphic->screen, colour);
}
