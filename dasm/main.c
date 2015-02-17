/*
** main.c for corewar in /u/all/botton_v/cu/test/corewar/dasm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:32:37 2010 vivien botton
** Last update Mon Mar 29 07:34:21 2010 vivien botton
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "op.h"
#include "lib.h"
#include "dasm.h"

void		decompil_with_label(int fd, int newfd)
{
  t_list	*list;
  t_label	*label;

  list = create_list(0, fd, 0, 0);
  list = rev_list(list, 0);
  handle_extend(newfd, list);
  label = create_label(list);
  my_sort_label(&label);
  num_label(label);
  fill_file(newfd, list, label);
  free_label(label);
}

int		begin_decompil(char *name, char *output, int no_label)
{
  int		nb;
  int		fd;
  int		newfd;

  fd = xopen(name, O_RDONLY, 0);
  newfd = xopen(output, O_CREAT | O_TRUNC | O_WRONLY, 0644);
  nb = fill_header(fd, newfd);
  if (nb != -1)
    {
      if (!no_label)
	decompil_with_label(fd, newfd);
      else
	fill_file_nolab(fd, newfd);
    }
  else
    {
      my_perror("The file ");
      my_perror(name);
      my_perror(" is not a corewar file\n");
    }
  close(fd);
  close(newfd);
  if (nb == -1)
    return (EXIT_FAILURE);
  put_msg_completed(name, output);
  return (EXIT_SUCCESS);
}

char		*get_argument(int ac, char **av, char **name, int *no_label)
{
  int		i;
  char		*mem;

  i = 1;
  mem = 0;
  while (i < ac)
    {
      if (!(*name) && !my_strcmp(av[i], OUTPOUT))
	{
	  if (++i >= ac)
	    return (0);
	  *name = av[i];
	}
      else if (!my_strcmp(av[i], NO_LABEL))
	*no_label = 1;
      else if (!mem)
	mem = av[i];
      i++;
    }
  return (mem);
}

int		verif(char *str, char *name, char *mem, int no_label)
{
  int		nb;

  if (!mem)
    return (put_usage(str));
  else
    {
      if (!name)
	{
	  name = get_name(mem);
	  nb = begin_decompil(mem, name, no_label);
	  free(name);
	}
      else
	nb = begin_decompil(mem, name, no_label);
      return (nb);
    }
}

int		main(int ac, char **av)
{
  int		no_label;
  char		*mem;
  char		*name;

  if (ac > 1)
    {
      name = 0;
      no_label = 0;
      mem = get_argument(ac, av, &name, &no_label);
      return (verif(av[0], name, mem, no_label));
    }
  else
    return (put_usage(av[0]));
}
