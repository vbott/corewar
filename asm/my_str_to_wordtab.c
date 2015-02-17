/*
** my_str_to_wordtab.c for minishell in /u/all/cerisi_m/cu/rendu/c/minishell
** 
** Made by mickael cerisier
** Login   <cerisi_m@epitech.net>
** 
** Started on  Sun Jan 10 14:20:33 2010 mickael cerisier
** Last update Sun Jan 10 14:20:34 2010 mickael cerisier
*/

#include <stdlib.h>
#include "lib.h"

int		my_isalphanumeric(char c, char s)
{
  if (c == '\0' || c == '\n' || c == s || (s == ' ' && c == '\t'))
    return (0);
  else
    return (1);
}

char		**my_write_tab(char *str, int taille, int lenmalloc, char c)
{
  int		i;
  int		e;
  int		a;
  char		**tab;

  i = 0;
  e = 1;
  a = 0;
  if (!(tab = xmalloc((lenmalloc + 1) * sizeof(char*))))
    return (0);
  while (i < taille)
    {
      if (e == 1 && my_isalphanumeric(str[i], c))
        {
          tab[a] = &str[i];
          a++;
          e = 0;
        }
      if (str[i] == '\0')
        e = 1;
      i++;
    }
  tab[a] = 0;
  return (tab);
}

char		**my_str_to_wordtab(char *str, char c)
{
  int		i;
  int		e;
  int		u;

  i = 0;
  e = 1;
  u = 0;
  while (str[i] != '\0')
    {
      if (!my_isalphanumeric(str[i], c))
	{
	  if (!u)
	    {
	      str[i] = '\0';
	      e++;
	    }
	  u = 1;
	}
      else
	u = 0;
      i++;
    }
  str[i] = '\0';
  return (my_write_tab(str, i, e, c));
}
