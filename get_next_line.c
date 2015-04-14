/*
** get_next_line2.c for getnexline in /home/geiger_a/rendu/CPE_2014_get_next_line
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Sat Nov 22 15:13:35 2014 anthony geiger
** Last update Sat Dec  6 13:06:08 2014 anthony geiger
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

void		where_my_buff_end(char *statbuffer, char *stockstat, int j)
{
  int		i;

  i = 0;
  while (statbuffer[j + 1])
    {
      stockstat[i] = statbuffer[j + 1];
      i++;
      j++;
    }
  stockstat[i] = '\0';
}

void		my_strcpy(char *buffer, char *stockstat, t_getline *s, char *dest)
{
  int		i;

  i = 0;
  while (stockstat[s->s])
    {
      buffer[s->s] = stockstat[i];
      s->s++;
      i++;
    }
  i = 0;
  while (i != SIZE_OF_READ)
    {
      stockstat[i] = '\0';
      i++;
    }
  i = 0;
  while (i != (s->i - 1) * SIZE_OF_READ)
    {
      buffer[s->s] = dest[i];
      i++;
      s->s++;
    }
}

char		*stat_in_buff(char *statbuffer, char *buffer,
			      t_getline *s, char *dest)
{
  int		j;
  static char	stockstat[SIZE_OF_READ];

  j = 0;
  s->s = 0;
  my_strcpy(buffer, stockstat, s, dest);
  while (j != SIZE_OF_READ && s->stop !=  1)
    {
      buffer[s->s] = statbuffer[j];
      if (buffer[s->s] == '\n')
  	{
  	  s->stop = 1;
  	  where_my_buff_end(statbuffer, stockstat, j);
  	  buffer[s->s] = '\0';
  	}
      else
	buffer[s->s + 1] = '\0';
      s->s++;
      j++;
    }
  return (buffer);
}

char		*get_next_line(const int fd)
{
  t_getline	s;
  static char	statbuffer[SIZE_OF_READ + 1];

  s.stop = 0;
  s.i = 1;
  while (s.stop == 0)
    {
      if ((s.buffer = malloc(SIZE_OF_READ * s.i + SIZE_OF_READ)) == NULL)
	return (NULL);
      if ((s.ret = read(fd, statbuffer, SIZE_OF_READ)) == - 1)
	return (NULL);
      statbuffer[s.ret] = '\0';
      s.buffer = stat_in_buff(statbuffer, s.buffer, &s, s.dest);
      if (s.i != 1)
	free(s.dest);
      if (s.ret == 0)
	{
	  close(fd);
	  return (s.buffer);
	}
      s.dest = s.buffer;
      s.i++;
    }
  return (s.buffer);
}
