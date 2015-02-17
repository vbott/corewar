/*
** get_calc.c for corewar in /u/all/botton_v/cu/projects/corewar/asm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Mon Mar 29 07:27:58 2010 vivien botton
** Last update Mon Mar 29 07:27:58 2010 vivien botton
*/

#include "op.h"
#include "lib.h"
#include "compiler.h"

extern t_option	gl_option;

int		get_calc_2(char *str, t_list *list, t_label *label, int *nb)
{
  int		e;

  e = 0;
  while (str[e] != '\0' && str[e] != ' ' && str[e] != '\t' &&
         str[e] != '+' && str[e] != '-')
    e++;
  while (str[e] == ' ' || str[e] == '\t')
    e++;
  if (str[e] && str[e] != COMMENT_CHAR && str[e] != ';')
    {
      if (!gl_option.extend)
        {
          put_msg_error(NUMNOEXT, list->line);
          return (-1);
        }
      return (get_calc(&str[e], list, label, nb));
    }
  return (0);
}

int		calc_signe(char *str, int *signe)
{
  int		e;

  e = 0;
  *signe = 1;
  while (str[e] == ' ' || str[e] == '\t' || str[e] == '+' || str[e] == '-')
    {
      if (str[e] == '-')
        *signe *= -1;
      e++;
    }
  return (e);
}

int		get_calc(char *str, t_list *list, t_label *label, int *nb)
{
  int		e;
  int		signe;
  t_label	*mem;

  e = calc_signe(str, &signe);
  if (str[e] == LABEL_CHAR)
    {
      if (!(mem = get_label(&str[e + 1], label, list->line)))
        return (-1);
      *nb += (mem->nbr_arg - list->nbarg) * signe;
    }
  else if (str[e] == '0' && (str[e + 1] == 'x' || str[e + 1] == 'X'))
    {
      if (!gl_option.extend)
        {
          put_msg_error(HEXNOEXT, list->line);
          return (-1);
        }
      *nb += my_getnbr_base(&str[e + 2], "0123456789ABCDEF") * signe;
    }
  else
    *nb += my_getnbr(&str[e]) * signe;
  return (get_calc_2(&str[e], list, label, nb));
}
