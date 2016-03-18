##
## Makefile for Makefile in /home/duhieu_b/System_unix/PSU_2015_tetris
## 
## Made by benjamin duhieu
## Login   <duhieu_b@epitech.net>
## 
## Started on  Thu Mar  3 10:29:38 2016 benjamin duhieu
## Last update Fri Mar 18 17:13:42 2016 benjamin duhieu
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
			$(SRCD)game_over.c \
			$(SRCD)disp_over.c \
			$(SRCD)display.c \
			$(SRCD)key_function.c \
			$(SRCD)key_function_next.c \
			$(SRCD)rotate.c \
			$(SRCD)chk_board.c \
			$(SRCD)verif.c \
			$(SRCD)rand_next.c \
			$(SRCD)piece.c \
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
			$(SRCP)get_high_scores.c \
			$(SRCP)replace_high_scores.c \
			$(SRCP)get_max_key_len.c \

OBJS    	=	$(SRC:.c=.o)

NAME    	=	tetris

CFLAGS  	=	-W -Wall -Werror

CFLAGS 		+=	-Iinclude/

LDFLAGS		=	-lncurses -L./lib -lmy

CC      	=	gcc -g

RM      	=	rm -f

# LIBRARY

LIBPATH		=	./lib/

SRCLIB		=	$(LIBPATH)my/my_getnbr.c \
			$(LIBPATH)my/my_power_rec.c \
			$(LIBPATH)my/my_putchar.c \
			$(LIBPATH)my/my_put_nbr.c \
			$(LIBPATH)my/my_putstr.c \
			$(LIBPATH)my/my_revstr.c \
			$(LIBPATH)my/my_strcmp.c \
			$(LIBPATH)my/my_strncmp.c \
			$(LIBPATH)my/my_strlen.c \
			$(LIBPATH)my/my_printf.c \
			$(LIBPATH)my/my_printfcsspb.c \
			$(LIBPATH)my/my_printfdiouxx.c \
			$(LIBPATH)my/my_strdup.c \
			$(LIBPATH)my/my_printfmetc.c \
			$(LIBPATH)my/get_next_line.c

OBJSLIB		=	$(SRCLIB:.c=.o)

# CONSTRUCTING PROJECT

$(NAME):		$(OBJSLIB) $(OBJS)
			ar rc $(LIBPATH)libmy.a $(OBJSLIB)
			ranlib $(LIBPATH)libmy.a
			$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

all:			$(NAME)

clean:
			$(RM) $(OBJS)
			$(RM) $(OBJSLIB)

fclean:			clean
			$(RM) $(NAME)
			$(RM) $(LIBPATH)/libmy.a

re:			fclean all
