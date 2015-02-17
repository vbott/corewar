/*
** dasm.h for corewar in /u/all/botton_v/cu/test/corewar/headers
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Fri Mar 26 11:19:11 2010 vivien botton
** Last update Fri Mar 26 11:19:15 2010 vivien botton
*/

#ifndef			_DASM_H_
# define		_DASM_H_

# define		LABEL_NAME "lab_"

/* argument */
# define		OUTPOUT "-o"
# define		NO_LABEL "-no_label"

typedef	struct		s_list
{
  int			args[4];
  int			types[4];
  int			posarg;
  int			nb;
  struct s_list		*next;
}			t_list;

typedef struct		s_label
{
  int			pos;
  int			nbr;
  struct s_label	*next;
}			t_label;

/* create_label.c */
int	exist_label(t_label *label, int pos);
t_label	*fill_label(t_list *list, t_label *label, int pos);
int	command_with_label(char *cmd);
t_label	*create_label(t_list *list);

/* create_list.c */
int	verif_dotcode(char c, int nb);
int	fill_arg_next(char c, int fd, int nb, t_list **list);
int	fill_arg(int fd, int nb, int posarg, t_list **list);
t_list	*create_list(t_list *list, int fd, int posarg, char c);

/* fill_file.c */
void	write_with_label(int arg, int pos, int fd, t_label *label);
void	write_list(t_list *list, int fd, t_label *label);
t_list	*handle_dotcode(int fd, t_list *list);
void	fill_file(int fd, t_list *list, t_label *label);

/* fill_file_nolab.c */
void	fill_file_nolab(int fd, int newfd);

/* fill_header.c */
int	fill_header(int fd, int newfd);
void	handle_extend(int fd, t_list *list);

/* free.c */
void	free_label(t_label *label);

/* get_arg.c */
int	get_arg(int fd, int size);

/* get_name.c */
char	*get_name(char *name);

/* main.c */
void	decompil_with_label(int fd, int newfd);
int	begin_decompil(char *name, char *output, int no_label);
char	*get_argument(int ac, char **av, char **name, int *no_label);
int	verif(char *str, char *name, char *mem, int no_label);

/* my_putnbr_base.c */
void	my_putnbr_base(int nb, char *base, int fd);

/* my_sort_label.c */
void	my_sort_label(t_label **begin);

/* num_label.c */
void	num_label(t_label *label);

/* put.c */
void	put_msg_completed(char *src, char *dest);
int	put_usage(char *str);

/* rev_list.c */
t_list	*rev_list(t_list *list, t_list *next);

/* write_arg.c */
int	special_write_arg(char *param, int fd, int *nbarg);
int	write_arg(char param, int nb, int fd, int *type);

#endif			/* _DASM_H_ */
