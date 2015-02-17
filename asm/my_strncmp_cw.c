/*
** my_strncmp_cw.c for corewar in /u/all/botton_v/cu/test/corewar/asm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:21:07 2010 vivien botton
** Last update Mon Mar 29 07:29:09 2010 vivien botton
*/

int		my_strncmp_cw(char *s1, char *s2)
{
  int		i;

  i = 0;
  while (s2[i] && s1[i] && s1[i] == s2[i])
    i++;
  if (s1[i] == ' ' || s1[i] == '\t' || s2[i] == '\0')
    return (1);
  return (0);
}
