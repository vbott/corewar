/*
** graph.h for corewar in /u/all/botton_v/cu/test/corewar/headers
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:18:58 2010 vivien botton
** Last update Mon Mar 29 07:40:37 2010 vivien botton
*/

#ifndef		_GRAPH_H_
# define	_GRAPH_H_

# ifndef	_SDL_TTF_H_
#  include <SDL/SDL_ttf.h>
# endif		/* _SDL/SDL_TTF_H_ */

# define	TITLE		"Corewar"
# define	WINX		1200
# define	WINY		960
# define	BCOLOR		32
# define	FADING		0x33000000

# define	x_ADD		1
# define	X_SUB		2
# define	X_AND		3
# define	X_OR		4
# define	X_XOR		5
# define	X_AFF		6
# define	X_STI		7
# define	X_ZJMP		8
# define	X_ST		9
# define	X_LOAD		10
# define	X_LD		11
# define	X_LLD		12
# define	X_LLDI		13
# define	X_LDI		14
# define	X_LIVE		15
# define	X_FORK		16
# define	X_GTMD		17

# if SDL_BYTEORDER == SDL_BIG_ENDIAN

#  define RM 0xff000000
#  define GM 0x00ff0000
#  define BM 0x0000ff00
#  define AM 0x000000ff

# else

#  define RM 0x000000ff
#  define GM 0x0000ff00
#  define BM 0x00ff0000
#  define AM 0xff000000

# endif

typedef struct  s_calc
{
  int           d;
  int           dx;
  int           dy;
  int           aincr;
  int           bincr;
  int           xincr;
  int           yincr;
  int           x;
  int           y;
}               t_calc;

/* graph.c */
void		load_right_blk(t_param *param);
void		calc_block_pos(int pc, t_param *para, SDL_Rect *pos);
void		calc_grid(t_param *param);
void		aff_zjump(t_prog *prog, t_param *para, int *co);

/* aff_actions.c */

void		aff_actions(t_prog *prog, int mode, t_param *para, int pc);

/* aff_text.c */
int		calc_len_int(int nb);
void		int_to_str(int nb, char *str);
void		aff_text(t_param *param, char *str, int x, int y);
void		if_no_player(int *y, SDL_Surface *screen, int *i);
void		aff_names(t_prog *prog, t_param *param);

/* base_funcs.c */

void            vline(int *coord, int height, SDL_Surface *surface, int color);
void            hline(int *coord, int width, SDL_Surface *surface, int color);
void            pixel_set(int x, int y, SDL_Surface *surface, int color);

/* geometric_basics.c */

void            any_line(int *coord, SDL_Surface *surface, int color);
void            circle(int *center, int rad, SDL_Surface *surface, int color);
void            disk(int *center, int rad, SDL_Surface *surface, int color);

/* xSDL_1.c */

void            my_swap(int *x, int *y);
SDL_Surface     *ximg_load(const char *file);
int             xsdl_flip(SDL_Surface *screen);
int             xsdl_blitsurface(SDL_Surface *src, SDL_Rect *srcrect,
                                 SDL_Surface *dst, SDL_Rect *dstrect);
int             xsdl_fillrect(SDL_Surface *dst, SDL_Rect *dstrect,
                              Uint32 color);

/* xSDL_2.c */

SDL_Surface     *xttf_rendertext_blended(TTF_Font *font, const char *text,
                                         SDL_Color fg);
TTF_Font        *xttf_openfont(const char *file, int ptsize);
int             xttf_init();
SDL_Surface     *xsdl_setvideomode(int width, int height, int bpp,
                                   Uint32 flags);
int             xsdl_init(Uint32 flags);

/* xSDL_3.c */

SDL_TimerID	xsdl_addtimer(Uint32 inter, SDL_NewTimerCallback cbk,
			      void *param);

#endif		/* _GRAPH_H_ */
