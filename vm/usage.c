/*
** usage.c for corewar in /u/all/botton_v/cu/test/corewar/vm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:11:48 2010 vivien botton
** Last update Fri Mar 26 11:11:52 2010 vivien botton
*/

#if defined (WIN32)
# include <windows.h>
#else
# include <stdlib.h>
#endif
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "op.h"
#include "vm.h"
#include "lib.h"

int		usage()
{
  printf("Usage : ./corewar [-%s] [-%s] [-%s] [-%s] [-%s nb] "
  "[-%s nb] [-%s nb] [-%s nb] [-%s nb] [-%s nb] prog.cor ...\n",
	    VERBOSE, X, FULLSCREEN, COMMENT, DUMP, NOX, CTMO, POURCENT, ADDR, ID);
  return (EXIT_FAILURE);
}

