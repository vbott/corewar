##
## Makefile for corewar in /u/all/botton_v/cu/test/corewar/lib
## 
## Made by vivien botton
## Login   <botton_v@epitech.net>
## 
## Started on  Fri Mar 26 11:24:25 2010 vivien botton
## Last update Sun Mar 28 09:55:04 2010 vivien botton
##

NAME	 = libmy.a

SRCS	 = my_getnbr_base.c	\
	   my_getnbr.c		\
	   my_perror.c		\
	   my_putchar.c		\
	   my_putnbr.c		\
	   my_putstr.c		\
	   my_putchar_fd.c	\
	   my_putnbr_fd.c	\
	   my_putstr_fd.c	\
	   my_power_rec.c	\
	   my_size_tab.c	\
	   my_strlen.c		\
	   my_strcmp.c		\
	   my_strcat.c		\
	   my_strdup.c		\
	   xfree.c		\
	   xlseek.c		\
	   xmalloc.c		\
	   xopen.c		\
	   xread.c		\
	   xremove.c

OBJS	 = $(SRCS:.c=.o)

AR	 = ar r

CC	 = gcc

CFLAGS   += -Wall -Wextra -pedantic -ansi -O2 -I ../../headers/

RM	 = rm -f

RANLIB	 = ranlib

CP	 = cp 

$(NAME)	: $(OBJS)
	$(AR) $(NAME) $(OBJS)
	$(RANLIB) $(NAME)
	$(CP) $(NAME) ..

all	: $(NAME)

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all