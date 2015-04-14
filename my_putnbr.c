/*
** my_putnbr.c for putnbr in /home/geiger_a/rendu/PSU_2014_my_ls
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Sun Nov 30 14:36:37 2014 anthony geiger
** Last update Mon Dec  1 11:44:00 2014 anthony geiger
*/

#include "my.h"

void     my_putnbr(int nb)
{
  int   div;

  div = 1;
  if (nb < 0)
    {
      my_putchar('-');
      nb = - nb;
    }
  while (nb / (div * 10) > 0)
    div = div * 10;
  while (div != 0)
    {
      if (div == 1)
        my_putchar(nb % 10 + 48);
      else
        my_putchar(nb / div + 48);
      nb = nb % div;
      div = div / 10;
    }
}
