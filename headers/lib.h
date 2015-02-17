/*
** lib.h for corewar in /u/all/botton_v/cu/test/corewar/lib
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:18:14 2010 vivien botton
** Last update Fri Mar 26 11:30:54 2010 vivien botton
*/

#ifndef		_HEADERS_H_
# define	_HEADERS_H_

int		my_numberbase(char *str, char *base, int len, int lennbr);
int		my_getnbr_base(char *str, char *base);

int		my_getnbr(char *str);
int		my_strlen(char *str);
void		my_perror(char *str);
void		my_putchar(char c);
void		my_putnbr(int nb);
void		my_putstr(char *str);
int		my_printf(char *, ...);
void		my_putchar_fd(char c, int fd);
void		my_putnbr_fd(int nb, int fd);
void		my_putstr_fd(char *str, int fd);
int		my_size_tab(char **tab);
int		my_strcmp(char *s1, char *s2);
char		*my_strcat(char *str1, char *str2);
char		*my_strdup(char *str);
int		my_power_rec(int nb, int power);

void		xfree(void *data);
int		xlseek(int fd, int offset, int whence);
void		*xmalloc(int size);
int		xopen(char *path, int droit, int mode);
int		xread(int fd, void *buf, int count);
void		xremove(const char *str);

#endif		/* _HEADERS_H_ */
