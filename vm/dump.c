/*
** dump.c for corewar in /u/epitech_2014/cerisi_m/public/group/corewar/vm
** 
** Made by carole cailleux
** Login   <caille_c@epitech.net>
** 
** Started on  Mon Feb  1 17:36:24 2010 carole cailleux
** Last update Wed Feb 10 17:03:29 2010 vivien botton
*/

#if defined (WIN32)
# include <windows.h>
#else
# include <unistd.h>
# include <fcntl.h>
#endif
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "op.h"
#include "vm.h"
#include "lib.h"

void		my_putnbr_base(int nb, char *base, int fd)
{
  char		c;

  if (nb / 16 > 0)
    my_putnbr_base(nb / 16, base, fd);
  c = base[nb % 16];
  write(fd, &c, 1);
}

void		dump(unsigned char *ram)
{
  int		fd;
  int		i;
  int		line;

  i = 0;
  fd = 1;
  while (i < MEM_SIZE)
    {
      line = 0;
      my_printf("%4X : ", i);
      while (line < 16 && i < MEM_SIZE)
	{
	  my_printf("%02X", ram[i]);
	  if (line < 15)
	    write(fd, " ", 1);
	  line++;
	  i++;
	}
      write(fd, "\n", 1);
    }
}
