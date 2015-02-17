##
## Makefile for corewar in /u/all/botton_v/cu/test/corewar/dasm
## 
## Made by vivien botton
## Login   <botton_v@epitech.net>
## 
## Started on  Fri Mar 26 11:33:06 2010 vivien botton
## Last update Mon Mar 29 07:56:25 2010 vivien botton
##

NAME	= dasm

SRCS	= ../op.c		\
	  create_list.c		\
	  create_label.c	\
	  fill_file.c		\
	  fill_file_nolab.c	\
	  fill_header.c		\
	  free.c		\
	  get_arg.c		\
	  get_name.c		\
	  main.c		\
	  my_putnbr_base.c	\
	  my_sort_label.c	\
	  num_label.c		\
	  put.c			\
	  rev_list.c		\
	  write_arg.c

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
