##
## Makefile for tetris in /home/brout_m/RENDU/PSU/PSU_2015_tetris
## 
## Made by marc brout
## Login   <brout_m@epitech.net>
## 
## Started on  Thu Feb 25 16:34:58 2016 marc brout
## Last update Mon Feb 29 20:28:42 2016 marc brout
##

SRCP		= ./

SRC     	= $(SRCP)error.c \
		$(SRCP)main.c \
		$(SRCP)misc.c \
		$(SRCP)get_next_line.c \
		$(SRCP)tabs.c \
		$(SRCP)debug.c \
		$(SRCP)tetris_load_tetriminos.c \
		$(SRCP)my_getnbr.c \
		$(SRCP)free.c 

OBJS    	= $(SRC:.c=.o)

NAME    	= tetris

CC      	= gcc -g

CFLAGS  	=  -W -Wall -Werror

HDFLAGS 	= -I../include/

LDFLAGS 	= -L../lib/ -lmy

RM      	= rm -f

.phony: 

.c.o:
	$(CC) -c $< -o $@ $(HDFLAGS) $(CFLAGS)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
