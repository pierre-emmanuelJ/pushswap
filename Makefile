##
## Makefile for Makefile in /home/jacqui_p/rendu/Piscine_C_J10
##
## Made by Pierre-Emmanuel Jacquier
## Login   <jacqui_p@epitech.net>
##
## Started on  Mon Oct 12 16:01:02 2015 Pierre-Emmanuel Jacquier
## Last update Sun Nov 22 22:44:40 2015 Pierre-Emmanuel Jacquier
##

CC	= cc

RM	= rm -f

CFLAGS	+= -I. -W -Wall -Wextra -ansi -pedantic

NAME	= push_swap

SRCS	= push_swap.c \
	  		my_getnbr.c \
	  		lower_number_found.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
