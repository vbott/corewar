/*
** justify.c for my_printf in /u/all/botton_v/cu/rendu/c/printf3
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Thu Nov 26 13:46:41 2009 vivien botton
** Last update Thu Nov 26 13:46:48 2009 vivien botton
*/

char            is_in(char c, char *str)
{
  int           e;

  e = 0;
  while (str[e] != '\0')
    {
      if (c == str[e])
        return (c);
      e++;
    }
  return (0);
}

int             justify(char *str)
{
  int           i;

  i = 0;
  while (!is_in(str[i], "diouxXsScfbp") && str[i] != '\0')
    {
      if (str[i] == '-')
        return (1);
      i++;
    }
  return (0);
}

void            fill_n(int *nb, int total)
{
  if (nb)
    *nb = total;
}

