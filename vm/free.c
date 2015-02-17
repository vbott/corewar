/*
** free.c for  in /u/all/caille_c/cu/corewar/vm
** 
** Made by carole cailleux
** Login   <caille_c@epitech.net>
** 
** Started on  Mon Mar 22 11:54:43 2010 carole cailleux
** Last update Mon Mar 22 11:54:44 2010 carole cailleux
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

void		free_list(t_player *list)
{
  t_player	*cpy;

  while (list)
    {
      cpy = list;
      free(list->prog_name);
      free(list->comment);
      list = list->next;
      free(cpy);
    }
}

void		free_progs(t_prog *list)
{
  t_prog	*cpy;

  while (list)
    {
      cpy = list;
      list = list->next;
      free(cpy);
    }
}
