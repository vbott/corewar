/*
** vm.h for corewar in /u/all/botton_v/cu/rendu/corewar
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Oct 16 14:40:23 2009 vivien botton
** Last update Mon Mar 29 08:12:59 2010 vivien botton
*/

#ifndef			_VM_H_
# define		_VM_H_

# define		MIDDLE 48
# define		LAST 12
# define		MAX_CYCLES 1000000

# define		WRONG_FILE " is not a corewar executable\n"
# define		NB_AUSED " : this number is already in use.\n"
# define		BAD_ARG " : bad argument.\n"
# define		INVALID_OPCODE "Invalid opcode.\n"
# define		ERASE_WARNING "Warning : You erased another program.\n"
# define		MEM_ERROR "Error : Not enough memory to store all programs.\n"
# define		GRPH_ERROR "Error : Graphical virtual machine is limited to 12 champions.\n"

# define		VERBOSE "v"
# define		DUMP "dump"
# define		NOX "noX"
# define		CTMO "ctmo"
# define		STEP "by_step"
# define		COMMENT "comment"
# define		POURCENT "pourcent"
# define		X "x"
# define		ADDR "a"
# define		ID "n"
# define		FULLSCREEN "fullscreen"
# define		REFRESH_TIME 33

#include <SDL/SDL_thread.h>
#include <SDL/SDL_mutex.h>

typedef struct	s_graphic
{
  SDL_Surface	*screen;
  SDL_Surface	*disp;
  SDL_Surface	*clip;
  SDL_Surface	*proc;
  SDL_Surface	*door;
  SDL_Rect	close_door;
  SDL_Rect	to_close;
  int		closing;
  int		nb_grid;
  double       	size_block;
  double	halfsize_blk;
  TTF_Font	*font;
}		t_graphic;

typedef struct		s_initprog
{
  int			nb;
  int			pos;
  int			decal;
  int			automode;
}			t_initprog;

typedef struct		s_player
{
  char			*prog_name;
  int			prog_size;
  char			*comment;
  int			id;
  int			color;
  int			start;
  int			nbprocess;
  struct s_player	*next;
}			t_player;

typedef struct		s_prog
{
  int			carry;
  int			pc;
  t_player		*header;
  unsigned char		regs[REG_NUMBER][REG_SIZE];
  int			alive;
  int			cycle;
  struct s_prog		*next;
}			t_prog;

typedef struct		s_func
{
  void			(*func)();
}      			t_func;

typedef struct		s_param
{
  char			sdl;
  char			bystep;
  char			aff;
  char			comment;
  char			verbose;
  char			quit;
  char			fullscreen;
  int			dump;
  int			ctmo;
  int			nox;
  int			max;
  int			pourcent;
  int			cycles;
  t_graphic		*graphic;
  int			todie;
  t_player		*lastlive;
  SDL_mutex		*lock;
}			t_param;

typedef struct		s_gltruct
{
  t_prog		*progs;
  t_player		*players;
  t_param		params;
}			t_glstruct;

/* vmfuncs.c  */
int	get_value_param(t_prog *prog, unsigned char *ram,
			int param, int indirect);

void	live(t_prog *prog, unsigned char *ram, t_prog *all, t_param *para);
void	aff(t_prog *prog, unsigned char *ram, t_param *params);
void	ld(t_prog *prog, unsigned char *ram, t_param *params);
void	st(t_prog *prog, unsigned char *ram, t_param *params);
void    add(t_prog *prog, unsigned char *ram, t_param *params);
void	sub(t_prog *prog, unsigned char *ram, t_param *params);
void	and(t_prog *prog, unsigned char *ram, t_param *params);
void	zjmp(t_prog *prog, unsigned char *ram, t_param *params);
void	or(t_prog *prog, unsigned char *ram, t_param *params);
void	xor(t_prog *prog, unsigned char *ram, t_param *params);
void	ldi(t_prog *prog, unsigned char *ram, t_param *params);
void	sti(t_prog *prog, unsigned char *ram, t_param *params);
void	vmfork(t_prog *prog, unsigned char *ram, t_param *params);
void	lld(t_prog *prog, unsigned char *ram, t_param *params);
void	lldi(t_prog *prog, unsigned char *ram, t_param *params);
void	lfork(t_prog *prog, unsigned char *ram, t_param *params);
void	gtmd(t_prog *prog, unsigned char *ram, t_param *params);

int     my_getnbr(char *str);

/* main.c */
void	do_cmd(t_prog *progs, unsigned char *ram, t_param *params);
void	calc(unsigned char *ram, t_prog *progs);
void	calc2(unsigned char *ram, t_prog *progs);
int	find_next_cycle(int value);
void	print_info(t_prog *progs, char *cmd);

/* init_sdl.c */
Uint32	close_timer(Uint32 interv, void *param);
void	my_graph(t_glstruct *gl, unsigned char *ram);

/* usage.c */
int	usage();

/* get_header.c */
int    	fill_header(t_prog *prog, unsigned char *ram, int fd, char *);

/* create.c */
t_player *create_playerlist(int ac, char **av);
t_prog	*create_proglist(int ac, char **av,
			 unsigned char *ram, t_player *players);
int	get_decal(int ac, char **av);
int	attribute_id(int *nb, int id, t_player *player);

/* cycle.c */
void   	cycle(t_prog *progs, t_player *players,
	      unsigned char *ram, t_param *params);

/* dump.c */
void   	dump(unsigned char *ram);

/* get_header.c */
void	fill_player(t_player *player, int fd);
void	clean_regs(t_prog *prog);

/* init.c */
int	handle_params(int ac, char **av, t_param *params);
void	init_params(t_param *params);
void	init_ram(unsigned char *ram);

/* bystep.c */
void	no_echo();
void	by_step(t_param *params);
void	handle_keys(t_param *params, int wait);
void	key_start();

/* ramutils.c */
void	set_pci(t_prog *prog, int jump);
void	write_in_ram(unsigned char *ram, int pos, int nb);
void	write_in_reg(t_prog *prog, int id, int nb);
int     get_regvalue(t_prog *prog, int id);
int	get_ramvalue(unsigned char *ram, int pos, int size);
int	check_mem_space(t_player *players);

/* verbose.c */
void	print_win(t_param *params);
void	print_live(t_prog *wholive);
void	bad_arg(char *, int, int);
void	invalid_cmd(int, int);

/* is_putable.c */
int	is_putable(unsigned char *ram, int pos, int size);

/* lib_1.c */
t_player *rev_list(t_player *list, t_player *next);
t_prog	 *rev_listp(t_prog *list, t_prog *next);

/* quit.c */
void	quit(t_prog *progs, t_player *players, t_param *params);
int	grph_mode(t_glstruct *);

/* dead.c */
void	reset_live(t_prog **progs, t_player *players, int *e);

/* create2.c */
void	init_create(t_initprog *id, int ac, char **av);
void	init_prog(t_prog *prog, unsigned char *ram, t_initprog *id);
int	is_corexec(int fd);
void	addr_id_option(t_initprog *id, char **av, t_player *player);
int	dotcor(char *name);

/* free.c */
void	free_list(t_player *list);
void	free_progs(t_prog *list);

#endif			/* _VM_H_ */
