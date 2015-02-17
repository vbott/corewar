/*
** check_label.c for corewar in /u/epitech_2014/cerisi_m/public/group/corewar/forcarole
** 
** Made by carole cailleux
** Login   <caille_c@epitech.net>
** 
** Started on  Sat Jan 30 14:03:03 2010 carole cailleux
** Last update Wed Feb 17 14:18:59 2010 mickael cerisier
*/

#include <stdlib.h>
#include "compiler.h"
#include "op.h"
#include "lib.h"

char		*my_alt_strdup(char *str)
{
  int		i;
  int		j;
  int		size;
  char		*copy;

  i = 0;
  j = 0;
  while (str[i] == '\t' || str[i] == ' ')
    i++;
  size = i;
  while (str[size] && str[size] != LABEL_CHAR && str[size] != '\t')
    size++;
  copy = xmalloc((size + 1 - i) * sizeof(*str));
  while (str[i] != LABEL_CHAR && str[i] != '\t')
    copy[j++] = str[i++];
  copy[i] = '\0';
  return (copy);
}

void		label_error(char *name_lab, int line)
{
  my_perror("label '");
  my_perror(name_lab);
  my_perror("' undefine line ");
  my_putnbr_fd(line, 2);
  my_putchar_fd('\n', 2);
}

t_label		*get_label(char *str, t_label *label, int line)
{
  int		i;
  char		mem;

  i = 0;
  mem = 0;
  while (str[i] && str[i] != '-' && str[i] != '+' &&
         str[i] != ' ' && str[i] != '\t')
    i++;
  if (str[i])
    {
      mem = str[i];
      str[i] = '\0';
    }
  while (label)
    {
      if (!my_strcmp(str, label->data))
	{
	  if (mem)
	    str[i] = mem;
	  return (label);
	}
      label = label->next;
    }
  label_error(str, line);
  return (0);
}

int		label_on_line(char *str)
{
  int		i;

  i = 0;
  while (str[i] && (str[i] == '\t' || str[i] == ' '))
    i++;
  while (str[i] && str[i] != '\t' && str[i] != ' ')
    {
      if (str[i] == LABEL_CHAR)
        return (1);
      i++;
    }
  return (0);
}

int		syntax_label(char *name)
{
  int		i;
  int		j;

  i = 0;
  while (name[i] != '\0')
    {
      j = 0;
      while (LABEL_CHARS[j] != '\0' && name[i] != LABEL_CHARS[j])
        j++;
      if (LABEL_CHARS[j] == '\0')
        return (0);
      i++;
    }
  return (1);
}
