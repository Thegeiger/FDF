/*
** my.h for include in /home/geiger_a/rendu/MUL_2014_fdf/chose_case
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Mon Dec  1 10:26:24 2014 anthony geiger
** Last update Sat Dec  6 12:12:18 2014 anthony geiger
*/

#ifndef MY_H_
# define MY_H_
#include "s_graph.h"

char		*get_next_line(const int fd);
void		my_putchar(char c);
void		my_putstr(char *str);
void		my_putnbr(int nb);
int		**tab_init(char *argv);
void		my_freetab(int **tab, int max);
void		chek_nb(char s, char *c);
void		convert_lines(int **tab, char *argv, t_igraph *s);
int		gere_key(int key);
int		gere_mouse(int boutton);
int		gere_expose(t_igraph *s);
void		my_draw_base(t_igraph *s);
int		**tab_init(char *argv);
int		int_now(char *s, int **tab, int x, int y);
void		convert_lines(int **tab, char *argv, t_igraph *struc);
int		how_many_line(char *argv);
int		basenb(char *argv);
int		space_nb(char *s, int i, int y);
int		how_many_nb(char *argv);
void		my_place_pos(t_igraph *s);
void		my_3d_pos(t_igraph *s);
void		my_link_pos(t_igraph *s);
void		display_exp(t_igraph *s);
void		my_putsterr(char *str);

#endif /* !MY_H_ */
