/*
** my_strlen.c for corewar in /u/all/botton_v/cu/test/corewar/lib
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:16:06 2010 vivien botton
** Last update Fri Mar 26 11:16:07 2010 vivien botton
*/

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
