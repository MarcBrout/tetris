##
## Makefile for tetris in /home/brout_m/RENDU/PSU/PSU_2015_tetris
## 
## Made by marc brout
## Login   <brout_m@epitech.net>
## 
## Started on  Thu Feb 25 16:34:58 2016 marc brout
## Last update Thu Feb 25 16:35:05 2016 marc brout
##

SRCP		= program/

SRC     	= $(SRCP)client.c \
		$(SRCP)my_putnbr_to_str.c \
		$(SRCP)my_getnbr.c

OBJS    	= $(SRC:.c=.o)

NAME    	= tetris

CC      	= gcc -g

CFLAGS  	=  -W -Wall -Werror

HDFLAGS 	= -I./include/

LDFLAGS 	= 

RM      	= rm -f

.phony: 

.c.o:
	$(CC) -c $< -o $@ $(HDFLAGS) $(CFLAGS)

$(CLIENT): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
