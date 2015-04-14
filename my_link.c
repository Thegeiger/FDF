/*
** my_link.c for linker in /home/geiger_a/MUL_2014_fdf
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Sat Dec  6 12:53:26 2014 anthony geiger
** Last update Sat Dec  6 12:57:39 2014 anthony geiger
*/

#include <mlx.h>
#include "s_graph.h"
#include "my.h"

void		link_1(t_igraph *s, int x1, int y1, int x2, int y2)
{
  int   x;

  x = x1;
  while (x <= x2)
    {
      mlx_pixel_put(s->mlx_ptr, s->win_ptr, x,
		    (y1 + (( y2 - y1 ) * ( x - x1 )) / ( x2 - x1 )), 0xFFFFFF);
      x++;
    }
}

void		link_2(t_igraph *s, int x1, int y1, int x2, int y2)
{
  int   x;

  x = x2;
  while (x <= x1)
    {
      mlx_pixel_put(s->mlx_ptr, s->win_ptr, x,
		    (y1 + (( y2 - y1 ) * ( x - x1 )) / ( x2 - x1 )), 0xFFFFFF);
      x++;
    }
}

void		my_putline_one(t_igraph *s, int y)
{
  while (y != s->posi.ymax)
    {
      link_2(s, (s->coord[s->posi.xmax - 1][y].x) + 675,
	     (s->coord[s->posi.xmax - 1][y].y),
	     (s->coord[s->posi.xmax - 1][y + 1].x) + 675,
	     (s->coord[s->posi.xmax - 1][y + 1].y));
      y++;
    }
}

void		my_link_pos(t_igraph *s)
{
  int		x;
  int		y;

  x = 0;
  y = 0;
  my_putline_one(s, y);
  while (x != s->posi.xmax - 1)
    {
      y = 0;
      while (y != s->posi.ymax)
  	{
	  link_1(s, (s->coord[x][y].x) + 675, (s->coord[x][y].y),
		 (s->coord[x + 1][y].x) + 675, (s->coord[x + 1][y].y));
	  link_2(s, (s->coord[x][y].x) + 675, (s->coord[x][y].y),
		 (s->coord[x][y + 1].x) + 675, (s->coord[x][y + 1].y));
    	  y++;
    	}
      x++;
    }
}
