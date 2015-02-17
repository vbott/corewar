/*
** main.c for corewar in /u/all/botton_v/cu/test/corewar/asm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:23:48 2010 vivien botton
** Last update Fri Mar 26 11:23:50 2010 vivien botton
*/

#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include "op.h"
#include "compiler.h"
#include "lib.h"

t_option	gl_option;

char		*find_name(char *init)
{
  int		last;
  char		*res;

  last = my_strlen(init) - 1;
  while (last >= 0 && init[last] != '.')
    last--;
  if (last == 0 || !my_strcmp(&init[last], ".cor"))
    res = my_strcat(init, ".cor");
  else
    {
      init[last] = '\0';
      res = my_strcat(init, ".cor");
      init[last] = '.';
    }
  return (res);
}

void		fill_header(int fd, int fdcor, int size)
{
  write_nbr(fdcor, COREWAR_EXEC_MAGIC, 4);
  search_dotstr(NAME_CMD_STRING, PROG_NAME_LENGTH, fd, fdcor);
  write_nbr(fdcor, 0, 4);
  write_nbr(fdcor, size, 4);
  xlseek(fd, 0, SEEK_SET);
  search_dotstr(COMMENT_CMD_STRING, COMMENT_LENGTH, fd, fdcor);
  write_nbr(fdcor, 0, 4);
  xlseek(fd, 0, SEEK_SET);
  if (search_dotstr(EXTEND_CMD_STRING, 0, fd, fdcor))
    gl_option.extend = 1;
  else
    gl_option.extend = 0;
  xlseek(fd, 0, SEEK_SET);
}

void		put_msg_completed(char *src, char *dest)
{
  my_putstr("Compilation of ");
  my_putstr(src);
  my_putstr(" in ");
  my_putstr(dest);
  my_putstr(" completed.\n");
}

void		begin_compil(char *name)
{
  int           fd;
  int           size;
  t_label       *label;
  t_list        *list;
  t_file        file;

  list = 0;
  size = 0;
  gl_option.old = 0;
  fd = xopen(name, O_RDONLY, 0);
  label = create_list(&list, &size, fd);
  file.name = find_name(name);
  file.fd = xopen(file.name, O_CREAT | O_TRUNC | O_WRONLY, 0644);
  fill_header(fd, file.fd, size);
  close(fd);
  if (list)
    {
      list = my_rev_list(list, 0);
      fill_file(list, label, &file);
    }
  close(file.fd);
  free_label(label);
  put_msg_completed(name, file.name);
  free(file.name);
}

int		main(int ac, char **av)
{
  if (ac > 1)
    begin_compil(av[1]);
  else
    {
      my_perror("******************************************************\n\n");
      my_perror("               Usage : ");
      my_perror(av[0]);
      my_perror(" file.s (Asm file)\n\n");
      my_perror("\n******************************************************\n");
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
