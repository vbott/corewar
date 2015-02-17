/*
** lib_1.c for  in /u/epitech_2014/cerisi_m/public/group/corewar/vm
** 
** Made by carole cailleux
** Login   <caille_c@epitech.net>
** 
** Started on  Mon Feb  1 19:18:26 2010 carole cailleux
** Last update Mon Mar 29 08:07:57 2010 vivien botton
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "op.h"
#include "vm.h"

t_player	*rev_list(t_player *list, t_player *next)
{
  t_player	*mem;

  mem = list;
  list = list->next;
  mem->next = next;
  if (list)
    return (rev_list(list, mem));
  return (mem);
}

t_prog		*rev_listp(t_prog *list, t_prog *next)
{
  t_prog	*mem;

  mem = list;
  list = list->next;
  mem->next = next;
  if (list)
    return (rev_listp(list, mem));
  return (mem);
}
