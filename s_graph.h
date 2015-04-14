/*
** s_graph.h for graph in /home/geiger_a/rendu/MUL_2014_fdf/chose_case
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Wed Dec  3 10:32:25 2014 anthony geiger
** Last update Fri Dec  5 11:25:10 2014 anthony geiger
*/

#ifndef S_GRAPH_H_
# define S_GRAPH_H_
# define ESCAPE 65307
# define Q_FOR_QUIT 113
# define MOUSE_LEFT 3
# define MAX(x, y) ((x > y) ? 1 : 0)

typedef struct	s_parimg
{
  char		*data;
  unsigned int	color;
  void		*img;
  int		bits_per_pixel;
  int		size_line;
  int		endian;
}		t_parimg;

typedef struct	s_place
{
  int		xmax;
  int		ymax;
  int		xwin;
  int		ywin;
}		t_place;

typedef	struct	s_coord
{
  int		x;
  int		y;
}		t_coord;

typedef struct	s_igraph
{
  void		*mlx_ptr;
  void		*win_ptr;
  int		**tab;
  t_parimg	parimg;
  t_place	posi;
  t_coord	**coord;
}		t_igraph;

typedef struct	s_navig
{
  int		y;
  int		x;
  int		xtab;
  int		ytab;
  float		buffer_x;
  float		buffer_y;
}		t_navig;

#endif /* !S_GRAPH_H_ */
