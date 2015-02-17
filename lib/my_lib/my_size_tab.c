/*
** my_size_tab.c for corewar in /u/all/botton_v/cu/test/corewar/lib
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:17:00 2010 vivien botton
** Last update Fri Mar 26 11:17:02 2010 vivien botton
*/

int		my_size_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}
