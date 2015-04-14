/*
** my_arg_gest.c for gest_arg in /home/geiger_a/rendu/MUL_2014_fdf/chose_case
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Tue Dec  2 11:44:32 2014 anthony geiger
** Last update Sat Dec  6 13:03:05 2014 anthony geiger
*/

#include "my.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int	how_many_line(char *argv)
{
  char	*s;
  int	i;
  int	fd;

  i = 0;
  fd = open(argv, O_RDONLY);
  if (fd == -1)
    exit(1);
  while ((s = (get_next_line(fd))))
    {
      i++;
      if (i > 100)
	{
	  my_putsterr("Sorry but this file is to big for this programe please ");
	  my_putsterr("try with an other\n");
	  exit(1);
	}
      free(s);
    }
  return (i + 1);
}

void		error_gest(int basey)
{
  if (basey > 100)
    {
      my_putsterr("Sorry but this file is to big for this programe please ");
      my_putsterr("try with an other\n");
      exit(1);
    }
}

int		basenb(char *argv)
{
  int		fd;
  int		i;
  int		basey;
  char		*s;

  basey = 0;
  fd = open(argv, O_RDONLY);
  if (fd == -1)
    exit(1);
  s = get_next_line(fd);
  close(fd);
  while (s[i] != '\0')
    {
      if (s[i] == ' ')
	{
	  basey++;
	  error_gest(basey);
	}
      i++;
    }
  free(s);
  return (basey + 1);
}

int		space_nb(char *s, int i, int y)
{
  while (s[i] != '\0')
    {
      if (s[i] == ' ')
	{
	  if (s[i + 1] == ' ' || (s[i + 1] < '0' || s[i + 1] > '9'))
	    {
	      my_putsterr("This file is contain wrong letter or ");
	      my_putsterr("more than one space befor a number ");
	      my_putsterr("so please check the file");
	      my_putsterr("and change it\n");
	      exit(1);
	    }
	  y++;
	}
      i++;
    }
  return (y + 1);
}

int		how_many_nb(char *argv)
{
  char		*s;
  int		i;
  int		fd;
  int		y;
  int		basey;

  y = 0;
  basey = basenb(argv);
  fd = open(argv, O_RDONLY);
  if (fd == -1)
    exit(1);
  while ((s = (get_next_line(fd))))
    {
      i = 0;
      y = 0;
      y = space_nb(s, i, y);
      if (basey != y)
	{
	  my_putsterr("This file is not a square or an rectangle");
	  my_putsterr("please change it\n");
	  exit(1);
	}
      free(s);
    }
  return (y);
}
