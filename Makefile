##
## Makefile for Makefile in /home/bourhi_a/rendu/Piscine-C-lib/my
## 
## Made by bourhime amine
## Login   <bourhi_a@epitech.net>
## 
## Started on  Mon Oct 21 11:02:20 2013 bourhime amine
## Last update Sun Mar 16 23:30:02 2014 
##

SRC		= 	src/graphics/put_pixel_in_image.c \
			src/graphics/gere_expose.c \
			src/graphics/clear_image.c \
			src/keys/manage_key.c \
			src/geometry/ab_distance.c \
			src/geometry/vector_rotation.c \
			src/geometry/normalise_vec.c \
			src/geometry/rot_arr_axis.c \
			src/forms/plane.c \
			src/forms/cone.c \
			src/forms/sphere.c \
			src/forms/cylindre.c \
			src/forms/equ_to_inter.c \
			src/graphics/init_rtv1.c \
			src/graphics/rtv1_loop.c \
			src/graphics/img_to_win.c \
			src/misc/xmalloc.c \
			src/rtv1.c \
			src/misc.c \
			src/draw_plans.c \
			main.c \

OBJ		=	$(SRC:.c=.o)

MINILIBX	=	minilibx

NAME		=	rtv1

CC		=	cc

CFLAGS		=	-W -Werror -Wall -ansi -pedantic -Wextra -I./include

HOST		=	$(HOSTTYPE)

RM		=	rm -f

LDFLAGS		=	-lm -L/usr/lib64 -L./minilibx -lmlx -L/usr/lib64/X11 -lXext -lX11

BCP		=	*~

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(MINILIBX)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	make clean -C $(MINILIBX)
	$(RM) $(OBJ) $(BCP) src/$(BCP) lib/$(BCP) include/$(BCP)

fclean:	clean
	make fclean -C $(MINILIBX)
	$(RM) $(NAME)

re:	fclean all
