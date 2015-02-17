/*
** get.c for my_printf in /u/all/botton_v/cu/rendu/c/printf2
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Thu Nov 19 21:18:17 2009 vivien botton
** Last update Mon Mar 29 07:46:12 2010 vivien botton
*/

#include "my.h"

char            get_flag(char *cmd)
{
  int           i;
  int           e;
  char          *str;

  str = "diouxXnsScfbp%";
  i = 0;
  while (cmd[i] != '\0')
    {
      e = 0;
      while (str[e] != '\0')
        {
          if (cmd[i] == str[e])
            return (str[e]);
          e++;
        }
      i++;
    }
  return (0);
}

int             get_nb(char *str, t_flags *cmd, void *data)
{
  int           i;
  int           nb;

  i = 0;
  nb = 0;
  while (!is_in(str[i], "diouxXnsScfbp%") && str[i] != '\0')
    {
      if ((str[i] >= '0' && str[i] <= '9') && str[i - 1] != '.'
	  && !(str[i - 1] >= '0' && str[i - 1] <= '9'))
	nb = getnbr(&str[i]);
      i++;
    }
  if (cmd->flag == '#' || cmd->type == 'p')
    {
      if (cmd->type == 'o')
        nb--;
      if (cmd->type == 'x' || cmd->type == 'X' || cmd->type == 'p')
        nb -= 2;
    }
  if (cmd->flag == '+')
    if ((cmd->type == 'd' || cmd->type == 'i') && (int)data > 0)
      nb--;
  return (nb);
}

char            get_carac(char *str)
{
  int           i;
  char          d;

  d = ' ';
  i = 0;
  while (str[i] != '\0' && (str[i] < '0' || str[i] > '9'))
    i++;
  if (str[i] == '0')
    d = '0';
  return (d);
}

char            get_drap(char *str, char type)
{
  int           i;
  char          d;

  i = 0;
  d = ' ';
  while (str[i] != '\0' && !is_in(str[i], "diouxXnsScfbp%"))
    {
      if (is_in(str[i] , "+-#"))
        {
          if (d == '#' && is_in(type, "xXo"))
            {}
	  else if (d == '+' && str[i] == '-')
	    {}
          else
            d = str[i];
        }
      i++;
    }
  return (d);
}

int		get_precision(char *str)
{
  int		i;
  int		nb;

  i = 0;
  nb = -1;
  while (str[i] != '\0' && !is_in(str[i], "diouxXnsScfbp%"))
    {
      if (str[i] == '.')
	nb = getnbr(&str[i + 1]);
      i++;
    }
  return (nb);
}
