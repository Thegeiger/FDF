/*
** my_conv_and_put.c for my_conv in /home/geiger_a/rendu/MUL_2014_fdf/chose_case
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Wed Dec  3 19:04:16 2014 anthony geiger
** Last update Sat Dec  6 12:20:05 2014 anthony geiger
*/

#include "my.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int	**tab_init(char *argv)
{
  int	x;
  int	**tab;

  x = 0;
  tab = malloc(how_many_line(argv) * sizeof(int *));
  if (tab == NULL)
    exit (1);
  while (x != how_many_line(argv))
    {
      tab[x] = malloc(how_many_nb(argv) * sizeof(int));
      if (tab[x] == NULL)
	exit (1);
      x++;
    }
  return (tab);
}

void	my_freetab(int **tab, int max)
{
  int	i;

  i = 0;
  while (i != max)
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}

void	chek_nb(char s, char *c)
{
  if ((s < '0' || s > '9') && s != ' ')
    {
      my_putstr("The file can bee read please modifie it or try with");
      my_putstr("an other file.\n");
      if (c != NULL)
	free(c);
      exit (1);
    }
}

int	int_now(char *s, int **tab, int x, int y)
{
  int	i;

  i = 0;
  while (s[i])
    {
      if (s[i] == ' ')
	{
	  if (s[i + 1] == ' ')
	    {
	      my_putstr("The file can bee read please modifie it or try with");
	      my_putstr("an other file.\n");
	      if (s != NULL)
		free(s);
	      exit (1);
	    }
	  y++;
	}
      chek_nb(s[i], s);
      if ((s[i] >= '0' && s[i] <= '9') && s[i] != ' ')
	tab[x][y] = ((tab[x][y] * 10) + (s[i] - '0'));
      i++;
    }
  return (y + 1);
}

void	convert_lines(int **tab, char *argv, t_igraph *struc)
{
  int	y;
  int	x;
  char	*s;
  int	fd;

  x = 0;
  fd = open(argv, O_RDONLY);
  if (fd == - 1)
    return ;
  while ((s = (get_next_line(fd))))
    {
      my_putstr(s);
      my_putchar('\n');
      y = 0;
      y = int_now(s, tab, x, y);
      x++;
      free(s);
    }
  struc->posi.xmax = x;
  struc->posi.ymax = y;
}
