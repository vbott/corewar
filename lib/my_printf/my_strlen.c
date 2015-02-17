/*
** my_strlen.c for my_strlen in /u/all/botton_v/cu/rendu/piscine/Jour_04
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Thu Oct  8 11:14:48 2009 vivien botton
** Last update Mon Mar 29 07:51:22 2010 vivien botton
*/

int	strlenp(char *str, int precision)
{
  int	i;

  i = 0;
  if (precision >= 0)
    while (str[i] != '\0' && i < precision)
      i++;
  else
    while (str[i] != '\0')
      i++;
  return (i);
}

int	charlen(int ch)
{
  if (ch)
    return (1);
  return (0);
}

int     strimplen(char *str)
{
  int   i;
  int	e;

  i = 0;
  e = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 32 || str[i] >= 127)
	e += 3;
      i++;
      e++;
    }
  return (e);
}
