##
## Makefile for corewar in /u/all/botton_v/cu/test/corewar/asm
## 
## Made by vivien botton
## Login   <botton_v@epitech.net>
## 
## Started on  Fri Mar 26 11:22:26 2010 vivien botton
## Last update Mon Mar 29 07:55:20 2010 vivien botton
##

NAME	= asm

SRCS	= ../op.c		\
	  create_list.c		\
	  check_errors.c	\
	  check_label.c		\
	  dot_code.c		\
	  exit.c		\
	  fill_arg_info.c	\
	  free.c		\
	  func.c		\
	  get_arg.c		\
	  get_calc.c		\
	  get_next_line.c	\
	  get_params.c		\
	  is_notnumeric.c	\
	  main.c		\
	  my_strncmp_cw.c	\
	  my_str_to_wordtab.c	\
	  my_rev_list.c		\
	  put_msg_error.c	\
	  search.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	+= -Wall -Wextra -ansi -pedantic -I ../headers/

CC	= clang 

RM	= rm -f

$(NAME)	: $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -L ../lib -lmy

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all

all	: $(NAME)

.c.o	:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
