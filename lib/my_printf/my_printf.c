/*
** my_printf.c for my_printf in /u/all/botton_v/cu/rendu/c/my_printf
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Mon Nov  9 11:47:46 2009 vivien botton
** Last update Mon Mar 29 07:49:47 2010 vivien botton
*/

#include <stdarg.h>
#include <unistd.h>
#include "my.h"

t_func  gl_func[14] = {
  {'d', put_nbrp, nbrlenp, ""},
  {'i', put_nbrp, nbrlenp, ""},
  {'u', putnbr_basep, nbrlen_basep, "0123456789"},
  {'o', putnbr_basep, nbrlen_basep, "01234567"},
  {'x', putnbr_basep, nbrlen_basep, "0123456789abcdef"},
  {'X', putnbr_basep, nbrlen_basep, "0123456789ABCDEF"},
  {'p', putnbr_basep, nbrlen_basep, "0123456789abcdef"},
  {'b', putnbr_basep, nbrlen_basep, "01"},
  {'f', putfloat, charlen, ""},
  {'s', putstrp , strlenp, ""},
  {'S', putstrimp, strimplen, ""},
  {'c', put_char, charlen, ""},
  {'%', putstrp, charlen, ""},
  {0, 0, 0, 0}
};

int	gl_total = 0;

void	put_char(int ch)
{
  int	test;

  test = write(1, &ch, 1);
  if (test == -1)
    write(2, "Could not write", 17);
  else
    gl_total += test;
}

void            putfloat(double f)
{
  int           entier;
  int           e;

  if (f < 0)
    {
      f *= -1;
      put_char('-');
    }
  e = 1000000;
  entier = f;
  put_nbr(entier);
  put_char('.');
  f -= entier;
  entier = f * 10000000;
  if (entier % 10 == 9)
    entier++;
  while (entier < e && e > 1)
    {
      put_char('0');
      e /= 10;
    }
  if (entier != 0)
    put_nbr(entier / 10);
}

void            aff_type(t_flags *cmd, void *data)
{
  int           i;

  i = 0;
  while (gl_func[i].type != 0)
    {
      if (gl_func[i].type == cmd->type)
        {
          if (gl_func[i].show == putnbr_basep)
            gl_func[i].show(data, gl_func[i].base, cmd->precision);
	  else
	    gl_func[i].show(data, cmd->precision);
	}
      i++;
    }
}

void            aff_space(t_flags *cmd, char carac, void *data)
{
  int           l;
  int		i;
  int		n;

  n = cmd->len;
  l = n;
  i = 0;
  while (gl_func[i].type != 0)
    {
      if (gl_func[i].type == cmd->type)
        {
          if (gl_func[i].len == nbrlen_basep)
            l = gl_func[i].len(data, gl_func[i].base, cmd->precision);
	  else
            l = gl_func[i].len(data, cmd->precision);
	}
      i++;
    }
  while (n > l)
    {
      put_char(carac);
      n--;
    }
}
