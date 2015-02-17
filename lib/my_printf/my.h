/*
** my.h for my_macroABS in /u/all/botton_v/cu/rendu/piscine/Jour_09
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Oct 16 14:40:23 2009 vivien botton
** Last update Mon Mar 29 07:50:59 2010 vivien botton
*/

#ifndef		_MY_H_
# define	_MY_H_

typedef struct  s_pt
{
  char  type;
  void  (*show)();
  int  (*len)();
  char	*base;
}               t_func;

typedef	struct	s_flags
{
  char	type;
  char	flag;
  char	carac;
  int	len;
  int	precision;
}		t_flags;

/* my_printf.c */
void    put_char(int ch);
void    putfloat(double f);
void    aff_type(t_flags *cmd, void *data);
void    aff_space(t_flags *cmd, char carac, void *data);
int	my_printf(char *, ...);

/* my_put_nbr.c */
void    put_nbr(int nb);
void    put_nbrp(int nb, int precision);

/* my_putstr.c */
void    putstr(char *str);
void    putstrp(char *str, int precision);

/* my_putstrimp.c */
void    putstrimp(char *str);

/* my_putnbr_base.c */
void    putnbr_basep(unsigned nb, char *base, int precision);
void	putnbr_base(unsigned nb, char *base);

/* gere.c */
void    gere_plus(t_flags *cmd, int droite, void *data);
void    gere_diese(t_flags *cmd, int droite, void *data);
void    aff_flag(char *str, t_flags *cmd, void *data);

/* my_getnbr.c */
int     getnbr(char *str);

/* my_strlen.c */
int	strlenp(char *str, int precision);
int     strimplen(char *str);
int     charlen(int ch);

/* my_nbrlen.c */
int	nbrlenp(int nb, int precision);

/* my_nbrlen_base.c */
int     nbrlen_basep(unsigned int nb, char *base, int precision);

/* get.c */
int	get_precision(char *str);
int     get_nb(char *str, t_flags *cmd, void *data);
char    get_flag(char *cmd);
char    get_carac(char *str);
char    get_drap(char *str, char type);

/* justify.c */
int     justify(char *str);
char    is_in(char c, char *str);
void    fill_n(int *nb, int total);

#endif		/* _MY_H_ */
