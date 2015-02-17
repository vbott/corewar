/*
** visuals.h for corewar in /u/all/bereng_p/cu/rendu/SVN/corewar/vm/visuals
** 
** Made by philippe berenguel
** Login   <bereng_p@epitech.net>
** 
** Started on  Fri Mar 26 00:26:31 2010 philippe berenguel
** Last update Mon Mar 29 07:42:25 2010 vivien botton
*/

#ifndef		_VISUALS_H_
# define	_VISUALS_H_

# ifndef	_SDL_TTF_H_
#  include	<SDL/SDL_ttf.h>
#  endif	/* _SDL/SDL_TTF_H_ */

# define WINX 1024
# define WINY 768
# define WIDTH 200
# define HEIGHT 200
# define FADING 0x35000000

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

typedef struct	s_anime
{
  int		width;
  int		height;
  SDL_Surface	*back;
  SDL_Surface	*shade;
  SDL_Surface	*screen;
  SDL_Surface	*live;
  SDL_Surface	*ld;
  SDL_Surface	*st;
  SDL_Surface	*add;
  SDL_Surface	*sub;
  SDL_Surface	*and;
  SDL_Surface	*or;
  SDL_Surface	*xor;
  SDL_Surface	*zjmp;
  SDL_Surface	*ldi;
  SDL_Surface	*sti;
  SDL_Surface	*fork;
  SDL_Surface	*lld;
  SDL_Surface	*lldi;
  SDL_Surface	*lfork;
  SDL_Surface	*aff;
}		t_anime;

typedef struct	s_calc
{
  int		d;
  int		dx;
  int		dy;
  int		aincr;
  int		bincr;
  int		xincr;
  int		yincr;
  int		x;
  int		y;
}		t_calc;

void		pixel_set(int x, int y, SDL_Surface *surface, int color);
void		vline(int *coord, int height, SDL_Surface *surface, int color);
void		hline(int *coord, int width, SDL_Surface *surface, int color);
void		any_line(int *coord, SDL_Surface *surface, int color);
void		circle(int *center, int rad, SDL_Surface *surface, int color);
void		disk(int *center, int rad, SDL_Surface *surface, int color);

/* xSDL_1.c */

void		my_swap(int *x, int *y);
SDL_Surface	*ximg_load(const char *file);
int		xSDL_flip(SDL_Surface *screen);
int		xSDL_blitsurface(SDL_Surface *src, SDL_Rect *srcrect,
				 SDL_Surface *dst, SDL_Rect *dstrect);
int		xSDL_FillRect(SDL_Surface *dst, SDL_Rect *dstrect,
			      Uint32 color);

/* xSDL_2.c */

SDL_Surface	*xTTF_RenderText_Blended(TTF_Font *font, const char *text,
					 SDL_Color fg);
TTF_Font	*xTTF_OpenFont(const char *file, int ptsize);
int		xTTF_Init();
SDL_Surface	*xSDL_SetVideoMode(int width, int height, int bpp,
				   Uint32 flags);
int		xSDL_Init(Uint32 flags);

#endif		/* _VISUALS_H_ */
