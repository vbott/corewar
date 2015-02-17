/*
** func.c for corewar in /u/all/botton_v/cu/test/corewar/asm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:21:23 2010 vivien botton
** Last update Fri Mar 26 11:21:25 2010 vivien botton
*/

#include "op.h"
#include "lib.h"

int		get_positiontab(char *command)
{
  int		i;

  i = 0;
  while (op_tab[i].code && my_strcmp(command, op_tab[i].mnemonique))
    i++;
  return (i);
}

void		separe_comment(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0' && str[i] != ';' && str[i] != COMMENT_CHAR)
    i++;
  if (str[i] == ';' || str[i] == COMMENT_CHAR)
    {
      i--;
      while (str[i] == ' ' || str[i] == '\t')
        i--;
      str[++i] = '\0';
    }
}
