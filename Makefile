##
## Makefile for FDF in /home/geiger_a/MUL_2014_fdf
## 
## Made by anthony geiger
## Login   <geiger_a@epitech.net>
## 
## Started on  Mon Nov 10 10:43:10 2014 anthony geiger
## Last update Tue Dec  9 16:40:08 2014 anthony geiger
##

CC	= gcc -g

CFLAGS  += -Wextra -Wall -Werror -g
CFLAGS  += -pedantic
CFLAGS  += -I.

SRCS	= fdf.c \
	my_putchar.c \
	my_putstr.c \
	my_putnbr.c \
	my_conv_and_put.c \
	my_link.c \
	my_arg_gest.c \
	my_event.c \
	get_next_line.c

OBJS	= $(SRCS:.c=.o)

NAME	= fdf

RM	= rm -f

LIB	= -L/usr/lib64 -lmlx -L/usr/lib64/X11 -lXext -lX11


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(SRCS) $(LIB) -o $(NAME)

op:
	clang $(SRCS) $(LIB) -o $(NAME) -Weverything

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
