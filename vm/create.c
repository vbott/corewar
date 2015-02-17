/*
** create.c for  in /u/all/caille_c/cu/corewar/vm
** 
** Made by carole cailleux
** Login   <caille_c@epitech.net>
** 
** Started on  Mon Mar 22 11:54:29 2010 carole cailleux
** Last update Sun Mar 28 21:26:14 2010 vivien botton
*/


#if defined (WIN32)
# include <windows.h>
#else
# include <unistd.h>
# include <stdlib.h>
#endif
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <fcntl.h>
#include "lib.h"
#include "op.h"
#include "vm.h"

t_player	*file_error(t_player *players, char *name, int fd)
{
  t_player	*cpy;

  if (access(name, F_OK))
    {
      my_perror(name);
      my_perror(" : No such file.\n");
    }
  else if (access(name, R_OK))
    {
      my_perror(name);
      my_perror(" : Permission denied.\n");
    }
  else
    {
      my_perror(name);
      my_perror(WRONG_FILE);
      close(fd);
    }
  while (players)
    {
      cpy = players;
      players = players->next;
      free(cpy);
    }
  return (NULL);
}

int		get_decal(int ac, char **av)
{
  int		i;
  int		nb;

  i = 1;
  nb = 0;
  while (i < ac)
    {
      if (av[i][0] != '-' && dotcor(av[i]))
	nb++;
      i++;
    }
  if (!nb)
    nb = 1;
  return (MEM_SIZE / nb);
}

int		attribute_id(int *nb, int id, t_player *player)
{
  while (player && player->id != id)
    player = player->next;
  if (!player)
    *nb = id;
  else
    {
      my_putnbr(id);
      my_perror(NB_AUSED);
      *nb = -2;
      return (-1);
    }
  return (0);
}

t_prog			*create_proglist(int ac, char **av,
					 unsigned char *ram, t_player *players)
{
  t_prog	*progs;
  t_prog	*next;
  t_initprog	id;
  int		i;

  i = 1;
  init_create(&id, ac, av);
  next = 0;
  while (i < ac && id.pos >= 0)
    {
      if (av[i][0] != '-' && dotcor(av[i]))
	{
	  progs = xmalloc(sizeof(t_prog));
	  progs->header = players;
	  init_prog(progs, ram, &id);
	  players = players->next;
	  progs->next = next;
	  next = progs;
	}
      else if (av[i][0] == '-' && players)
	addr_id_option(&id, &av[i], players);
      i++;
    }
  return ((id.pos >= 0) ? next = rev_listp(next, 0) : NULL);
}

t_player		*create_playerlist(int ac, char **av)
{
  int			i;
  int			fd;
  t_player		*players;
  t_player		*next;

  i = 1;
  next = 0;
  while (i < ac)
    {
      if (av[i][0] != '-' && dotcor(av[i]))
	{
	  fd = open(av[i], O_RDONLY);
	  if (fd == -1 || !is_corexec(fd))
            return (file_error(next, av[i], fd));
	  players = xmalloc(sizeof(*players));
	  fill_player(players, fd);
	  players->next = next;
	  next = players;
	}
      i++;
    }
  if (next)
    return (rev_list(next, 0));
  return (0);
}
