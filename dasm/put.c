/*
** put.c for corewar in /u/all/botton_v/cu/projects/corewar/dasm
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Mon Mar 29 07:33:02 2010 vivien botton
** Last update Mon Mar 29 07:33:02 2010 vivien botton
*/

#include <stdlib.h>
#include "lib.h"
#include "dasm.h"

void		put_msg_completed(char *src, char *dest)
{
  my_putstr("Decompilation of ");
  my_putstr(src);
  my_putstr(" in ");
  my_putstr(dest);
  my_putstr(" completed.\n");
}

int		put_usage(char *str)
{
  my_perror("**********************************************************\n\n");
  my_perror("          Usage : ");
  my_perror(str);
  my_perror(" file.cor (Corewar file)\n");
  my_perror("        [");
  my_perror(OUTPOUT);
  my_perror(" output_file]\n");
  my_perror("        [");
  my_perror(NO_LABEL);
  my_perror("] (To decompile without label and .code)\n");
  my_perror("\n**********************************************************\n");
  return (EXIT_FAILURE);
}
