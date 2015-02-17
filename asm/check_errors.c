/*
** check_errors.c for corewar in /u/all/botton_v/cu/test/corewar/asm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:22:19 2010 vivien botton
** Last update Fri Mar 26 11:22:20 2010 vivien botton
*/

#include <stdlib.h>
#include "compiler.h"
#include "op.h"
#include "lib.h"

extern t_option	gl_option;

int		check_indirect(char *str, int line)
{
  int		nb;

  if (str[0] == '\0')
    {
      put_msg_error(SYNTAXERROR, line);
      return (-1);
    }
  nb = my_getnbr(str);
  if (is_notnumeric(str))
    put_notnum_error(str, nb, line);
  if (nb > IDX_MOD || nb < -IDX_MOD)
    put_msg_error(WARIND, line);
  return (0);
}

int		check_direct(char *str, int line)
{
  int		i;
  int		nb;
  int		signe;

  if (str[0] == '\0')
    {
      put_msg_error(SYNTAXERROR, line);
      return (-1);
    }
  nb = my_getnbr((str[0] == ':') ? &str[1] : str);
  if (str[0] != ':' && is_notnumeric(str))
    put_notnum_error(str, nb, line);
  signe = 1;
  i = 0;
  while (str[i] == '-' || str[i] == '+')
    if (str[i++] == '-')
      signe *= -1;
  i = my_strlen(&str[i]);
  if ((nb > 0 && signe == -1) || (nb < 0 && signe == 1) || i > 10)
    put_msg_error(WARDIR, line);
  return (0);
}

int		check_register(char *str, int line)
{
  int		nb;

  nb = my_getnbr(str) + gl_option.old;
  if (is_notnumeric(str))
    put_notnum_error(str, nb - gl_option.old, line);
  if (nb == 0)
    {
      gl_option.old = 1;
      nb = 1;
    }
  if (nb < 1 || nb > REG_NUMBER)
    {
      my_putnbr(nb - gl_option.old);
      put_msg_error(NOSUCHREG, line);
      return (-1);
    }
  return (0);
}

int		check_error(char *str, int i, int pos, int line)
{
  if (str[0] == LABEL_CHAR)
    str++;
  if (str[0] == DIRECT_CHAR && (op_tab[pos].type[i] & T_DIR))
    return (check_direct(&str[1], line));
  if ((str[0] == 'R' || str[0] == 'r') && (op_tab[pos].type[i] & T_REG))
    return (check_register(&str[1], line));
  if ((op_tab[pos].type[i] & T_IND))
    return (check_indirect(str, line));
  put_msg_error(BADARG, line);
  return (-1);
}
