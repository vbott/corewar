##
## Makefile for corewar in /u/all/botton_v/cu/test/corewar/vm
## 
## Made by vivien botton
## Login   <botton_v@epitech.net>
## 
## Started on  Fri Mar 26 11:25:13 2010 vivien botton
## Last update Mon Mar 29 07:52:55 2010 vivien botton
##

NAME 	= corewar

SRCS 	= ../op.c		\
	  addsub.c		\
	  aff_actions.c		\
	  aff_text.c		\
	  and.c			\
	  base_funcs.c		\
	  bystep.c		\
	  create.c		\
	  create2.c		\
	  cycle.c		\
	  dump.c		\
	  find_place.c		\
	  free.c		\
	  fork.c		\
	  geometric_basics.c	\
	  dead.c		\
	  get_header.c		\
	  graph.c		\
	  init.c		\
	  init_sdl.c		\
	  instructions1.c	\
	  int_to_str.c		\
	  ld.c			\
	  ldi.c			\
	  lib_1.c		\
	  main.c		\
	  quit.c		\
	  ramutils.c		\
	  specialinst.c		\
	  st.c			\
	  usage.c		\
	  verbose.c		\
	  vmfuncs.c		\
	  xSDL_1.c		\
	  xSDL_2.c		\
	  xSDL_3.c		\

OBJS	= $(SRCS:.c=.o)

CC 	= clang

RM 	= rm -f

CFLAGS  += -Wall -Wextra -ansi -pedantic -O2 -pipe `sdl-config --cflags` -I../headers

LDFLAGS = `sdl-config --libs` -lSDL -lSDL_image -lSDL_ttf -L../lib -lmy -lmy_printf

all	: $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) 

clean	: 
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all
	 
.c.o	:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
