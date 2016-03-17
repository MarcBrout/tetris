##
## Makefile for Makefile in /home/duhieu_b/System_unix/PSU_2015_tetris
## 
## Made by benjamin duhieu
## Login   <duhieu_b@epitech.net>
## 
## Started on  Thu Mar  3 10:29:38 2016 benjamin duhieu
## Last update Thu Mar 17 12:55:37 2016 marc brout
##

SRCD		=	disp/

SRCP		=	program/

SRC     	=	$(SRCD)disp.c \
			$(SRCD)create_win_tet.c \
			$(SRCD)aff_tetris.c \
			$(SRCD)aff_score.c \
			$(SRCD)aff_next.c \
			$(SRCD)aff_tot.c \
			$(SRCD)tab_game.c \
			$(SRCP)main.c \
			$(SRCP)debug.c \
			$(SRCP)error.c \
			$(SRCP)misc.c \
			$(SRCP)free.c \
			$(SRCP)tabs.c \
			$(SRCP)my_getnbr.c \
			$(SRCP)tetris_load_tetriminos.c \
			$(SRCP)tri.c \
			$(SRCP)get_next_line.c \
			$(SRCP)options.c \
			$(SRCP)get_keys.c \
			$(SRCP)get_pause.c \
			$(SRCP)help.c \
			$(SRCP)recup_env.c \
			$(SRCP)temp_tetriminos.c \
			$(SRCP)get_high_scores.c

OBJS    	=	$(SRC:.c=.o)

NAME    	=	tetris

CC      	=	gcc -g

CFLAGS  	=	-W -Wall -Werror

HDFLAGS 	=	-Iinclude/

LDFLAGS		=	-lncurses -L./lib -lmy

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
