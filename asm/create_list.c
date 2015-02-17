/*
** create_list.c for corewar in /u/epitech_2014/cerisi_m/public/group/corewar/forcarole
** 
** Made by carole cailleux
** Login   <caille_c@epitech.net>
** 
** Started on  Sun Jan 31 20:38:31 2010 carole cailleux
** Last update Wed Feb 17 18:57:09 2010 mickael cerisier
*/

#include <stdlib.h>
#include <unistd.h>
#include "compiler.h"
#include "op.h"
#include "lib.h"

int		label_already_exist(t_label *label, char *name, int line)
{
  while (label)
    {
      if (!my_strcmp(label->data, name))
	{
	  put_msg_error("Label already exist line ", line);
	  return (1);
	}
      label = label->next;
    }
  return (0);
}

t_label		*create_label(char *line, int nbr_arg, t_label *label, int i)
{
  char		*name;
  t_label	*new;

  name = my_alt_strdup(line);
  if (!syntax_label(name))
    {
      free(name);
      free_label(label);
      put_msg_error("Syntax error line ", i);
      return (0);
    }
  if (label_already_exist(label, name, i))
    {
      free(name);
      free_label(label);
      return (0);
    }
  new = xmalloc(sizeof(*new));
  new->data = name;
  new->nbr_arg = nbr_arg;
  new->next = label;
  return (new);
}

int		code_in_list(char *str, t_list **list, int nbr_arg, int line)
{
  int		i;
  t_list	*mem;

  i = 0;
  mem = xmalloc(sizeof(*mem));
  mem->free = str;
  mem->line = line;
  while (str[i] == '\t' || str[i] == ' ')
    i++;
  str = &str[i];
  i = 0;
  while (str[i] && str[i] != '\t' && str[i] != ' ')
    i++;
  str[i++] = '\0';
  mem->command = str;
  while (str[i] == '\t' || str[i] == ' ')
    i++;
  mem->tab = my_str_to_wordtab(&str[i], ' ');
  i = 0;
  while (mem->tab[i] != 0)
    i++;
  mem->next = *list;
  *list = mem;
  return (nbr_arg + i);
}

t_label		*get_info(char *str, int *size, t_label *label, t_list **list)
{
  static int	i;
  int		e;
  t_list	*mem;

  i++;
  e = 0;
  while (str[e] == ' ' || str[e] == '\t')
    e++;
  if (str[e] != '\0' && str[e] != '.' && str[e] != COMMENT_CHAR)
    {
      if (label_on_line(str) && !(label = create_label(str, *size, label, i)))
	free_when_error(0, *list, str);
      mem = *list;
      if ((*size = fill_arg_info(str, list, i, *size)) == -1)
	free_when_error(label, *list, str);
      if (mem == *list)
	free(str);
    }
  else if (str[e] != '\0' && my_strncmp_cw(&str[e], CODE_CMD_STRING))
    *size = code_in_list(str, list, *size, i);
  else
    free(str);
  return (label);
}

t_label		*create_list(t_list **list, int *size, int fd)
{
  char		*str;
  t_label	*label;

  label = 0;
  while ((str = get_next_line(fd)))
    label = get_info(str, size, label, list);
  xlseek(fd, 0, SEEK_SET);
  return (label);
}
