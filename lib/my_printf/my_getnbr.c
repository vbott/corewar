/*
** my_getnbr.c for my_getnbr in /afs/epitech.net/users/all/botton_v/rendu/piscine/Jour_04
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Thu Oct  8 13:14:06 2009 vivien botton
** Last update Wed Nov 25 10:32:23 2009 vivien botton
*/

int	str_number_pos(char *str)
{
  int	signe;
  int	pos;

  signe = 1;
  pos = 0;
  while (str[pos] == '+' || str[pos] == '-' || str[pos] == ' ')
    pos++;
  return (signe * pos);
}

int	getnbr(char *str)
{
  int	nbr;
  int	signe;
  int	first_number;

  signe = 1;
  first_number = str_number_pos(str);
  if (first_number < 0)
    {
      first_number = first_number * -1;
      signe = - 1;
    }
  str = str + first_number;
  nbr = 0;
  while (*str >= '0' && *str <= '9')
    {
      nbr = nbr * 10;
      nbr = nbr + (*str - '0');
      str = str + 1;
    }
  return (signe * nbr);
}
