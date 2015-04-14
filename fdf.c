/*
** tp.c for tp in /home/geiger_a/MUL_2014_fdf/tp
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Mon Nov 17 10:44:40 2014 anthony geiger
** Last update Sat Dec  6 16:54:58 2014 anthony geiger
*/

#include <mlx.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "s_graph.h"
#include "my.h"

void	my_gere_param(t_igraph *s)
{
  s->posi.xwin = 1080;
  s->posi.ywin = 720;
  s->mlx_ptr = mlx_init();
  if (s->mlx_ptr == NULL)
    exit (1);
  s->win_ptr = mlx_new_window(s->mlx_ptr, s->posi.xwin, s->posi.ywin, "FDF");
  if (s->mlx_ptr == NULL)
    exit (1);
  my_place_pos(s);
  my_3d_pos(s);
  my_link_pos(s);
  mlx_key_hook(s->win_ptr, &gere_key, s);
  mlx_mouse_hook(s->win_ptr, &gere_mouse, s);
  mlx_expose_hook(s->win_ptr, &gere_expose, s);
}

t_coord		**coord_tab(int xmax, int ymax)
{
  t_coord	**coord;
  int		i;

  i = 0;
  coord = malloc(sizeof(t_coord *) * (xmax + 1));
  if (coord == NULL)
    exit (1);
  while (i != xmax + 1)
    {
      coord[i] = malloc(sizeof(t_coord) * (ymax + 1));
      if (coord[i] == NULL)
	exit (1);
      i++;
    }
  return (coord);
}

void		my_place_pos(t_igraph *s)
{
  int		y;
  int		x;
  int		xtab;
  int		ytab;

  x = s->posi.xmax;
  xtab = 0;
  s->coord = coord_tab(s->posi.xmax, s->posi.ymax);
  while (x != 0)
    {
      ytab = 0;
      y = s->posi.ymax;
      while (y != 0)
	{
	  (s->coord[xtab][ytab]).x = (s->posi.ywin / (s->posi.ymax + 1) * y);
	  (s->coord[xtab][ytab]).y = (s->posi.xwin / (s->posi.xmax + 1) * x);
	  ytab++;
	  y--;
	}
      xtab++;
      x--;
    }
}

void		my_3d_pos(t_igraph *s)
{
  t_navig       nav;

  nav.x = s->posi.xmax;
  nav.xtab = 0;
  while (nav.x != 0)
    {
      nav.ytab = 0;
      nav.y = s->posi.ymax;
      while (nav.y != 0)
        {
          nav.buffer_x = (0.75 * (s->coord[nav.xtab][nav.ytab]).x -0.75
                          * (s->coord[nav.xtab][nav.ytab]).y);
          nav.buffer_y = (s->tab[nav.xtab][nav.ytab] * -1 + (0.75 / 2) *
                          (s->coord[nav.xtab][nav.ytab]).x + (0.75 / 2) *
                          (s->coord[nav.xtab][nav.ytab]).y);
          (s->coord[nav.xtab][nav.ytab]).x = nav.buffer_x;
          (s->coord[nav.xtab][nav.ytab]).y = nav.buffer_y;
	  mlx_pixel_put(s->mlx_ptr, s->win_ptr, (nav.buffer_x + 675),
                        nav.buffer_y, 0x00FF00);
          nav.ytab++;
          nav.y--;
        }
      nav.xtab++;
      nav.x--;
    }
}

int		main(int argc, char **argv)
{
  t_igraph	s;

  if (argc != 2)
    {
      my_putsterr("Usage : ./fdf [file]\n");
      return (1);
    }
  if ((s.tab = tab_init(argv[1])) == NULL)
    return (1);
  my_putstr("For quit you can :\nPress the 'mouse left boutton'");
  my_putstr(", press 'q', or 'ESCAPE'\n");
  my_putstr("file format :\n");
  convert_lines(s.tab, argv[1], &s);
  my_gere_param(&s);
  mlx_loop(s.mlx_ptr);
  my_freetab(s.tab, s.posi.xmax);
  return (0);
}
