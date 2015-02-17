/*
** my_strcmp.c for my_strcmp in /u/all/botton_v/cu/rendu/piscine/Jour_06
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Mon Oct 12 14:55:06 2009 vivien botton
** Last update Sun Mar 28 18:48:07 2010 mickael cerisier
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
    i++;
  return (s1[i] - s2[i]);
}
