/*
** compiler.h for  in /u/epitech_2014/cerisi_m/public/group/corewar/forcarole
** 
** Made by carole cailleux
** Login   <caille_c@epitech.net>
** 
** Started on  Thu Jan 28 10:53:59 2010 carole cailleux
** Last update Wed Feb 17 15:41:48 2010 mickael cerisier
*/

#ifndef			_COMPILER_H_
# define		_COMPILER_H_

# define		DONTEXITINS "Instrucion doesn't exist"
# define		TOOMARG "Too many arguments"
# define		TOOFARG "Too few arguments"
# define		SYNTAXERROR "Syntax error"
# define		NOSUCHREG ": No such register"
# define		BADARG "Bad argument"

/* Warning */
# define		WARIND "Warning: Indirect too far"
# define		WARDIR "Warning: Direct too big"
# define		WARNOTNUM "Warning: Invalid number"
# define		WARNOTNUM2 ", value \""
# define		WARNOTNUM3 "\" will be interpreted as "

/* .extend */
# define		NUMNOEXT "Numeric operation without .extend"
# define		HEXNOEXT "Hexadecimal without .extend"
# define		CODENOEXT ".code without .extend"

typedef struct		s_option
{
  int			extend;
  int			old;
}			t_option;

typedef struct		s_file
{
  int			fd;
  char			*name;
}			t_file;

typedef struct		s_label
{
  struct s_label	*next;
  char			*data;
  int			nbr_arg;
}			t_label;

typedef struct		s_list
{
  char			*free;
  char			*command;
  int			octetparam;
  char			**tab;
  int			line;
  int			nbarg;
  struct s_list		*next;
}			t_list;

/* check_errors.c */
int	check_indirect(char *str, int line);
int	check_direct(char *str, int line);
int	check_register(char *str, int line);
int	check_error(char *str, int i, int pos, int line);

/* check_label.c */
char	*my_alt_strdup(char *str);
void	label_error(char *name_lab, int line);
t_label	*get_label(char *str, t_label *label, int line);
int	label_on_line(char *str);
int	syntax_label(char *name);

/* create_list.c */
int	label_already_exist(t_label *label, char *name, int line);
t_label	*create_label(char *line, int nbr_arg, t_label *label, int i);
int	code_in_list(char *str, t_list **list, int nbr_arg, int line);
t_label	*get_info(char *str, int *size, t_label *label, t_list **list);
t_label	*create_list(t_list **list, int *size, int fd);

/* dot_code.c */
int	dot_code(char **tab, int fd);

/* exit.c */
void	exit_fail(t_label *label, t_list *list, char *name);

/* fill_arg_info.c */
int	calc_postab(char *command, int size, int line);
int	step2_arg(char **tab, int line, int pos);
int	step1_arg(t_list *list);
int	fill_arg_info(char *str, t_list **list, int line, int nbarg);

/* free.c */
void	free_label(t_label *list);
void	free_list(t_list *list);
void	free_when_error(t_label *label, t_list *list, char *str);

/* func.c */
int	get_positiontab(char *command);
void	separe_comment(char *str);

/* get_calc.c */
int	get_calc_2(char *str, t_list *list, t_label *label, int *nb);
int	calc_signe(char *str, int *signe);
int	get_calc(char *str, t_list *list, t_label *label, int *nb);

/* get_next_line.c */
int	numberbase(char *str, char *base, int len, int lennbr);
char	*get_next_line(const int fd);

/* get_arg.c */
void	write_nbr(int fd, unsigned int nb, int size);
void	get_arg2(char *str, t_list *list, t_label *label, t_file *file);
void	get_arg(t_list *list, t_label *label, t_file *file);
int	get_octet(char **tab);

/* get_params.c */
char	get_tab_nbr(char *str);
void	put_in_file(char *str, int fd);
char	*get_params(char *str, char **str2);
void	fill_file(t_list *list, t_label *label, t_file *file);

/* is_notnumeric.c */
int	is_notnumeric(char *str);

/* main.c */
char	*find_name(char *init);
void	fill_header(int fd, int fdcor, int size);
void	put_msg_completed(char *src, char *dest);
void	begin_compil(char *name);

/* my_rev_list.c */
t_list	*my_rev_list(t_list *list, t_list *next);

/* my_str_to_wordtab.c */
int	my_isalphanumeric(char c, char s);
char	**my_write_tab(char *str, int taille, int lenmalloc, char c);
char	**my_str_to_wordtab(char *str, char c);

/* my_strncmp_cw.c */
int	my_strncmp_cw(char *s1, char *s2);

/* put_msg_error.c */
void	put_msg_error(char *str, int line);
void	put_notnum_error(char *str, int nb, int line);

/* search.c */
void	fill_str_in_header(char *str, int size, int fd);
int	search_dotstr(char *dotstr, int size, int fd, int fdcor);

#endif			/* _COMPILER_H_ */
