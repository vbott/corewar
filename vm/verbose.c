/*
** verbose.c for corewar in /u/all/botton_v/cu/projects/corewar/vm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Sun Mar 28 20:55:11 2010 vivien botton
** Last update Sun Mar 28 20:55:13 2010 vivien botton
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "op.h"
#include "vm.h"
#include "lib.h"

void		print_live(t_prog *wholive)
{
  printf("Le joueur %d (%s) est en vie.\n",
	    wholive->header->id, wholive->header->prog_name);
}

void		print_win(t_param *params)
{
  if (params->lastlive)
    {
      printf("Le joueur %d (%s) a gagne",
       params->lastlive->id, params->lastlive->prog_name);
      if (params->comment)
		printf(" : %s", params->lastlive->comment);
      printf(".\n");
    }
}

void		bad_arg(char *instruction, int pos, int cycles)
{
  printf("[%6d %6d] : %s%s", cycles, pos, instruction, BAD_ARG);
}

void		invalid_cmd(int pos, int cycles)
{
  printf("[%6d %6d] : %s", cycles, pos, INVALID_OPCODE);
}
