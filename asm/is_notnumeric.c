/*
** is_notnumeric.c for corewar in /u/all/botton_v/cu/projects/corewar/asm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Mon Mar 29 07:28:08 2010 vivien botton
** Last update Mon Mar 29 07:28:08 2010 vivien botton
*/

int		is_notnumeric(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if ((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '+')
	return (1);
      i++;
    }
  return (0);
}
