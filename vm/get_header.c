/*
** get_header.c for  in /u/epitech_2014/cerisi_m/public/group/corewar/vm
** 
** Made by carole cailleux
** Login   <caille_c@epitech.net>
** 
** Started on  Mon Feb  1 14:27:37 2010 carole cailleux
** Last update Mon Mar 29 08:05:55 2010 vivien botton
*/

#if defined (WIN32)
# include <windows.h>
#else
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
#endif
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "lib.h"
#include "op.h"
#include "vm.h"

void		clean_regs(t_prog *prog)
{
  int		i;
  int		e;

  i = 1;
  while (i < REG_NUMBER)
    {
      e = 0;
      while (e < REG_SIZE)
	{
	  prog->regs[i][e] = 0;
	  e++;
	}
      i++;
    }
}

int		find_color()
{
  static int	i;
  int		color[14] = {
    0x00FFFFFF,
    0x00D53B3B,
    0x0049C18A,
    0x0076d4f6,
    0x00F974DB,
    0x00FFFA70,
    0x00A875F4,
    0x00E88D6A,
    0x00AAE763,
    0x00797BF4,
    0x00E38C00,
    0x0084B3D7,
    0x00DEB5D7,
    0
  };
  i++;
  if (i > 13)
    i = 13;
  return (color[i]);
}

void		fill_player(t_player *player, int fd)
{
  int		nb;
  unsigned char buffer[4096];

  nb = xread(fd, buffer, PROG_NAME_LENGTH + 12 + COMMENT_LENGTH);
  if (nb < PROG_NAME_LENGTH + 12 + COMMENT_LENGTH)
	return ;
  player->prog_name = my_strdup((char*)buffer);
  player->prog_size = get_ramvalue(buffer, PROG_NAME_LENGTH + 4, 4);
  player->comment = my_strdup((char*)&buffer[PROG_NAME_LENGTH + 8]);
  player->color = find_color();
  player->nbprocess = fd;
}

