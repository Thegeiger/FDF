/*
** my_event.c for envent in /home/geiger_a/rendu/MUL_2014_fdf/chose_case
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Wed Dec  3 11:18:44 2014 anthony geiger
** Last update Sat Dec  6 10:45:24 2014 anthony geiger
*/

#include "s_graph.h"
#include <mlx.h>
#include <stdlib.h>
#include "my.h"

int	gere_key(int key)
{
  if (key == ESCAPE)
    exit(1);
  else if (key == Q_FOR_QUIT)
    exit(1);
  return (0);
}

int	gere_mouse(int boutton)
{
  if (boutton == MOUSE_LEFT)
    exit(1);
  return (0);
}

int	gere_expose(t_igraph *s)
{
  my_link_pos(s);
  return (0);
}
