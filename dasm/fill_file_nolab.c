/*
** fill_file.c for corewar in /u/all/botton_v/cu/test/corewar/dasm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:32:57 2010 vivien botton
** Last update Fri Mar 26 11:32:58 2010 vivien botton
*/

#include "op.h"
#include "lib.h"
#include "dasm.h"

static void	special_write_arg_nolab(char *param, int fd, int newfd)
{
  my_putchar_fd(DIRECT_CHAR, newfd);
  if (!my_strcmp(param, "live"))
    my_putnbr_fd(get_arg(fd, 4), newfd);
  else
    my_putnbr_fd(get_arg(fd, IND_SIZE), newfd);
}

static void	write_arg_nolab(char param, int nb, int fd, int newfd)
{
  if ((param & 3) == 1)
    {
      my_putchar_fd('r', newfd);
      my_putnbr_fd(get_arg(fd, 1), newfd);
    }
  else if ((param & 3) == 2)
    {
      my_putchar_fd(DIRECT_CHAR, newfd);
      if (op_tab[nb].indirect)
	my_putnbr_fd(get_arg(fd, IND_SIZE), newfd);
      else
	my_putnbr_fd(get_arg(fd, DIR_SIZE), newfd);
    }
  else
    my_putnbr_fd(get_arg(fd, IND_SIZE), newfd);
}

static void	fill_arg_nolab(int fd, int newfd, int nb)
{
  int		i;
  char		buffer[32];

  if (op_tab[nb].needoctetparam)
    {
      xread(fd, buffer, 1);
      i = 0;
      while (i < op_tab[nb].nbr_args)
	{
	  if (i)
	    my_putchar_fd(',', newfd);
	  write_arg_nolab(buffer[0] >> ((3 - i) * 2), nb, fd, newfd);
	  i++;
	}
    }
  else
    special_write_arg_nolab(op_tab[nb].mnemonique, fd, newfd);
}

void		fill_file_nolab(int fd, int newfd)
{
  int		nb;
  char          buffer[32];

  if (xread(fd, buffer, 1))
    {
      my_putchar_fd('\t', newfd);
      nb = 0;
      while (op_tab[nb].code && op_tab[nb].code != buffer[0])
	nb++;
      if (op_tab[nb].code)
	{
	  my_putstr_fd(op_tab[nb].mnemonique, newfd);
	  my_putchar_fd('\t', newfd);
	  fill_arg_nolab(fd, newfd, nb);
	}
      my_putchar_fd('\n', newfd);
      fill_file_nolab(fd, newfd);
    }
}
