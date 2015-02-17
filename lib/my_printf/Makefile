##
## Makefile for libmy in /u/all/botton_v/cu/rendu/lib/my
## 
## Made by vivien botton
## Login   <botton_v@epitech.net>
## 
## Started on  Mon Oct 19 10:49:56 2009 vivien botton
## Last update Fri Nov 27 17:03:38 2009 vivien botton
##

NAME 	= libmy_printf.a
SRCS 	=	get.c \
		justify.c \
		my_printf.c \
		my_getnbr.c \
		my_nbrlen.c \
		my_nbrlen_base.c \
		my_put_nbr.c \
		my_putnbr_base.c \
		my_putstr.c \
	        start.c     \
		my_putstrimp.c \
		gere.c \
		my_strlen.c

OBJS	= $(SRCS:.c=.o)

CC 	= gcc

AR	= ar r

RM 	= rm -f

CFLAGS += -Wall -Wextra -ansi -pedantic -O2

RANLIB	= ranlib

INCLUDE	= my.h

CP	= cp

all	: $(OBJS)
	$(AR) $(NAME) $(OBJS)
	$(RANLIB) $(NAME)
	$(CP) $(NAME) ..

clean	: 
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all
	 