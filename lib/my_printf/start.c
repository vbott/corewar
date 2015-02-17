/*
** start.c for my_printf in /u/all/botton_v/cu/rendu/c/my_printf
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

extern int	gl_total;

void		print(int *i, char *flags, va_list *args)
{
  t_flags	 cmd;
  void		 *data;

  data = 0;
  *i = *i + 1;
  cmd.type = get_flag(&flags[*i]);
  if (cmd.type == 'n')
    fill_n(va_arg(*args, int*), gl_total);
  else if (cmd.type == 'f')
    putfloat(va_arg(*args, double));
  else if (cmd.type == '%')
    data = "%";
  else
    data = va_arg(*args, void*);
  if ((cmd.type == 's' || cmd.type == 'S') && data == 0)
    data = "(null)";
  if (cmd.type != 'n' && cmd.type != 'f')
    aff_flag(&flags[*i], &cmd, data);
  while (flags[*i + 1] && flags[*i] != cmd.type)
    *i = *i + 1;
}

int		my_printf(char *flags, ...)
{
  va_list	args;
  int		i;

  i = 0;
  gl_total = 0;
  if (flags)
    {
      va_start(args, flags);
      while (flags[i] != '\0')
	{
	  if (flags[i] != '%')
	    put_char(flags[i]);
	  else if (flags[i] == '%' && flags[i + 1]  != '\0')
	    print(&i, flags, &args);
	  i++;
	}
      va_end(args);
    }
  return (gl_total);
}
