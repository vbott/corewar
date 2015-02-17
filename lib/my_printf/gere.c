/*
** gere.c for my_printf in /u/all/botton_v/cu/rendu/c/my_printf
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Thu Nov 26 20:34:15 2009 vivien botton
** Last update Mon Mar 29 07:47:15 2010 vivien botton
*/

#include "my.h"

void            gere_plus(t_flags *cmd, int droite, void *data)
{
  if (cmd->carac == ' '  && !droite)
    aff_space(cmd, cmd->carac, data);
  if ((cmd->type == 'd' || cmd->type == 'i') && (int)data >= 0)
    put_char('+');
  if ((cmd->type == 'd' || cmd->type == 'i') &&
      (int)data < 0 && cmd->carac == '0')
    put_char('-');
  if (cmd->carac == '0' && !droite)
    aff_space(cmd, cmd->carac, data);
  aff_type(cmd, data);
}

void            gere_diese(t_flags *cmd, int droite, void *data)
{
  if (cmd->type == 'o' && cmd->precision != -1)
    cmd->precision--;
  if (cmd->carac == ' ' && !droite)
    aff_space(cmd, cmd->carac, data);
  if (cmd->type == 'o')
    put_char('0');
  else if (cmd->type == 'x' || cmd->type == 'p')
    putstr("0x");
  else if (cmd->type == 'X')
    putstr("0X");
  if (cmd->carac == '0' && !droite)
    aff_space(cmd, cmd->carac, data);
  aff_type(cmd, data);
}

void            aff_flag(char *str, t_flags *cmd, void *data)
{
  int           droite;

  cmd->flag = get_drap(str, cmd->type);
  cmd->carac = get_carac(str);
  cmd->len = get_nb(str, cmd, data);
  cmd->precision = get_precision(str);
  droite = justify(str);
  if (cmd->flag == '+' && cmd->type != 'p')
    gere_plus(cmd, droite, data);
  else if (cmd->flag == '#' || cmd->type == 'p')
    gere_diese(cmd, droite, data);
  else
    {
      if (cmd->carac == ' '  && !droite)
        aff_space(cmd, cmd->carac, data);
      if ((cmd->type == 'd' || cmd->type == 'i') && (int)data < 0)
        put_char('-');
      if (cmd->carac == '0'  && !droite)
        aff_space(cmd, cmd->carac, data);
      aff_type(cmd, data);
    }
  if (droite)
    aff_space(cmd, ' ', data);
}
