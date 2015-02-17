/*
** put_msg_error.c for corewar in /u/all/botton_v/cu/projects/corewar/asm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Mon Mar 29 07:28:17 2010 vivien botton
** Last update Mon Mar 29 07:28:17 2010 vivien botton
*/

#include "lib.h"
#include "compiler.h"

void		put_msg_error(char *str, int line)
{
  my_perror(str);
  my_perror(" line ");
  my_putnbr_fd(line, 2);
  my_putchar_fd('\n', 2);
}

void		put_notnum_error(char *str, int nb, int line)
{
  my_perror(WARNOTNUM);
  my_perror(" line ");
  my_putnbr_fd(line, 2);
  my_perror(WARNOTNUM2);
  my_perror(str);
  my_perror(WARNOTNUM3);
  my_putnbr_fd(nb, 2);
  my_perror("\n");
}
