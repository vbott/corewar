/*
** fill_file.c for corewar in /u/all/botton_v/cu/test/corewar/dasm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:32:57 2010 vivien botton
** Last update Fri Mar 26 11:32:58 2010 vivien botton
*/

#include "op.h"
#include "lib.h"
#include "dasm.h"

int		fill_header(int fd, int newfd)
{
  int		nb;
  char		buffer[COMMENT_LENGTH + 1];

  nb = get_arg(fd, 4);
  if (nb == COREWAR_EXEC_MAGIC)
    {
      my_putstr_fd(NAME_CMD_STRING, newfd);
      my_putstr_fd("\t\t\"", newfd);
      xread(fd, buffer, PROG_NAME_LENGTH + 1);
      my_putstr_fd(buffer, newfd);
      xread(fd, buffer, 7);
      xread(fd, buffer, COMMENT_LENGTH + 1);
      if (buffer[0] != '\0')
	{
	  my_putstr_fd("\"\n", newfd);
	  my_putstr_fd(COMMENT_CMD_STRING, newfd);
	  my_putstr_fd("\t\"", newfd);
	  my_putstr_fd(buffer, newfd);
	}
      my_putstr_fd("\"\n", newfd);
      xread(fd, buffer, 3);
      return (0);
    }
  return (-1);
}

void		handle_extend(int fd, t_list *list)
{
  while (list)
    {
      if (list->posarg == -1)
        {
          my_putstr_fd(EXTEND_CMD_STRING, fd);
	  my_putstr_fd("\n\n", fd);
          return ;
        }
      list = list->next;
    }
  my_putchar_fd('\n', fd);
}
