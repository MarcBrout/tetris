##
## Makefile for tetris in /home/brout_m/RENDU/PSU/PSU_2015_tetris
## 
## Made by marc brout
## Login   <brout_m@epitech.net>
## 
## Started on  Thu Feb 25 16:34:58 2016 marc brout
## Last update Thu Feb 25 20:31:50 2016 benjamin duhieu
##

SRC     	=	main.c \
			error.c \
			misc.c

OBJS    	=	$(SRC:.c=.o)

NAME    	=	game

CC      	=	gcc -g

CFLAGS  	=	-W -Wall -Werror

HDFLAGS 	=	-I../include/

LDFLAGS		=	-lncurses

RM      	=	rm -f

.c.o:
			$(CC) -c $< -o $@ $(HDFLAGS) $(CFLAGS)

$(NAME):		$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

all:			$(NAME)

clean:
			$(RM) $(OBJS)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all
