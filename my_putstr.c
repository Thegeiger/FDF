/*
** my_putstr.c for my_putstr in /home/geiger_a/rendu/PSU_2014_my_ls
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Sun Nov 30 14:33:53 2014 anthony geiger
** Last update Sat Dec  6 12:00:25 2014 anthony geiger
*/

#include "my.h"
#include <unistd.h>

void     my_putstr(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}

void	my_puterr(char c)
{
  write(2, &c, 1);
}

void	my_putsterr(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      my_puterr(str[i]);
      i++;
    }
}
