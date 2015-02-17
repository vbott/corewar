/*
** get_arg.c for corewar in /u/epitech_2014/cerisi_m/public/group/corewar/forcarole
** 
** Made by carole cailleux
** Login   <caille_c@epitech.net>
** 
** Started on  Sun Jan 31 19:48:32 2010 carole cailleux
** Last update Wed Feb 17 15:58:25 2010 mickael cerisier
*/

#include <stdlib.h>
#include <unistd.h>
#include "op.h"
#include "compiler.h"
#include "lib.h"

extern t_option	gl_option;

void		write_nbr(int fd, unsigned int nb, int size)
{
  unsigned char	res;
  int		puissance;

  puissance = 8 * (size - 1);
  while (puissance >= 0)
    {
      res = (nb >> puissance) & 255;
      write(fd, &res, 1);
      puissance -= 8;
    }
}

void		get_arg2(char *str, t_list *list, t_label *label, t_file *file)
{
  int		nb;

  nb = 0;
  if (str[0] == DIRECT_CHAR)
    {
      if (get_calc(&str[1], list, label, &nb) == -1)
	exit_fail(label, list, file->name);
      if (op_tab[get_positiontab(list->command)].indirect)
	write_nbr(file->fd, nb, IND_SIZE);
      else
	write_nbr(file->fd, nb, DIR_SIZE);
    }
  else
    {
      if (get_calc(str, list, label, &nb) == -1)
	exit_fail(label, list, file->name);
      write_nbr(file->fd, nb, IND_SIZE);
    }
}

void		get_arg(t_list *list, t_label *label, t_file *file)
{
  int		i;
  int		e;
  int		nb;

  i = 0;
  while (list->tab[i] != 0)
    {
      e = 0;
      while (list->tab[i][e] == ' ' || list->tab[i][e] == '\t')
        e++;
      if (list->tab[i][e] == 'r' || list->tab[i][e] == 'R')
	{
	  nb = my_getnbr(&(list->tab[i][e + 1])) + gl_option.old;
	  write_nbr(file->fd, nb, 1);
	}
      else
	get_arg2(&(list->tab[i][e]), list, label, file);
      i++;
    }
}

int		get_octet(char **tab)
{
  int		i;
  int		e;
  int		puissance;
  unsigned char	res;

  i = 0;
  res = 0;
  puissance = 64;
  while (tab[i] != 0)
    {
      e = 0;
      while (tab[i][e] && (tab[i][e] == ' ' || tab[i][e] == '\t'))
	e++;
      if (tab[i][e] == 'r' || tab[i][e] == 'R')
	res += puissance;
      else if (tab[i][e] == DIRECT_CHAR)
	res += puissance * 2;
      else
	res += puissance * 2 + puissance;
      puissance /= 4;
      i++;
    }
  return (res);
}
