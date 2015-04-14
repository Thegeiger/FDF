/*
** get_next_line.h for struct in /home/geiger_a/rendu/CPE_2014_get_next_line
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Fri Nov 14 16:56:05 2014 anthony geiger
** Last update Sat Dec  6 13:04:46 2014 anthony geiger
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# define SIZE_OF_READ 1

typedef	struct	s_getline
{
  int		stop;
  int		i;
  int		ret;
  int		s;
  char		*dest;
  char		*buffer;
}		t_getline;

void			my_putchar(char c);
void			my_putstr(char *str);
void			my_putnbr(int nb);
char			*getbuffer(char *buffer, char *retbuffer);
char			*stat_in_buff(char *strtbuffer, char *buffer,
				      t_getline *s, char *dest);
void			where_my_buff_end(char *statbuffer,
					  char *stockstat, int j);
void			my_strcpy(char *buffer, char *stockstat,
				  t_getline *s, char *dest);

#endif /* !GET_NEXT_LINE_H_ */
