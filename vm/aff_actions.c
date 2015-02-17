/*
** aff_actions.c for corewar in /u/all/botton_v/cu/projects/corewar/vm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Mon Mar 29 07:52:18 2010 vivien botton
** Last update Mon Mar 29 08:00:07 2010 vivien botton
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "op.h"
#include "vm.h"
#include "graph.h"

static void	aff_fork(t_prog *prog, t_param *para, int pc)
{
  int		center[2];
  SDL_Rect	pos;

  calc_block_pos(pc, para, &pos);
  center[0] = para->graphic->halfsize_blk + pos.x;
  center[1] = para->graphic->halfsize_blk + pos.y;
  circle(center, para->graphic->halfsize_blk + 3, para->graphic->screen,
         prog->header->color);
}

static void	aff_st(t_prog *prog, t_param *para, int pc)
{
  int		coord[4];
  SDL_Rect	pos;
  int		i;
  int		colour;

  i = 0;
  colour = prog->header->color + 0xFF000000;
  while (i < REG_SIZE)
    {
      calc_block_pos(pc, para, &pos);
      coord[0] = pos.x + para->graphic->halfsize_blk;
      coord[1] = pos.y;
      coord[2] = coord[0];
      coord[3] = pos.y + para->graphic->size_block;
      any_line(coord, para->graphic->screen, colour);
      coord[0] = pos.x;
      coord[1] = pos.y + para->graphic->halfsize_blk;
      coord[2] = pos.x + para->graphic->size_block;
      coord[3] = coord[1];
      any_line(coord, para->graphic->screen, colour);
      pc = (pc + 1) % MEM_SIZE;
      i++;
    }
}

static void	aff_sti(t_prog *prog, t_param *para, int pc)
{
  int		coord[4];
  SDL_Rect	pos;
  int		i;
  int		colour;

  i = 0;
  colour = prog->header->color + 0xFF000000;
  while (i < REG_SIZE)
    {
      calc_block_pos(pc, para, &pos);
      coord[0] = pos.x;
      coord[1] = pos.y;
      coord[2] = pos.x + para->graphic->size_block;
      coord[3] = pos.y + para->graphic->size_block;
      any_line(coord, para->graphic->screen, colour);
      coord[0] = coord[2];
      coord[1] = pos.y;
      coord[2] = pos.x;
      coord[3] = coord[3];
      any_line(coord, para->graphic->screen, colour);
      pc = (pc + 1) % MEM_SIZE;
      i++;
    }
}

static void	aff_live(t_prog *prog, t_param *para, int pc)
{
  SDL_Rect	pos;
  int		center[2];
  int		i;
  int		colormod;
  int		color;

  i = 0;
  colormod = (0xFF / 4) << 24;
  color = (prog) ? prog->header->color : 0x00E6E8FA;
  while (i < 4)
    {
      calc_block_pos(pc, para, &pos);
      center[0] = para->graphic->halfsize_blk + pos.x;
      center[1] = para->graphic->halfsize_blk + pos.y;
      if (i == 1 || i == 2)
        disk(center, para->graphic->halfsize_blk -1, para->graphic->screen,
             color + colormod * 4);
      else
        disk(center, para->graphic->halfsize_blk - 1, para->graphic->screen,
             color + colormod);
      pc = (pc + 1) % MEM_SIZE;
      i++;
    }
}

void		aff_actions(t_prog *prog, int mode, t_param *para, int pc)
{
  if (para->sdl)
    {
      /*SDL_mutexP(para->lock);*/
      if (mode == X_LIVE)
        aff_live(prog, para, pc);
      else if (mode == X_ST)
        aff_st(prog, para, pc);
      else if (mode == X_STI)
        aff_sti(prog, para, pc);
      else if (mode == X_FORK)
	aff_fork(prog, para, pc);
      /*SDL_mutexV(para->lock);*/
    }
}
