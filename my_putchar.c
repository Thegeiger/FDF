/*
** my_putchar.c for my_putchar in /home/geiger_a/rendu/PSU_2014_my_ls
** 
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
** 
** Started on  Sun Nov 30 14:21:31 2014 anthony geiger
** Last update Mon Dec  1 10:44:00 2014 anthony geiger
*/

#include "my.h"
#include <unistd.h>

void    my_putchar(char c)
{
  write(1, &c, 1);
}
