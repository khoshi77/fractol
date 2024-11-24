NAME	=	fractol
SRCS	=	main.c color.c fractol.c hook.c \
	julia.c mandelbrot.c
OBJS	=	$(SRCS:.c=.o)
CC	=	cc
CFLAG	=	-Wall -Wextra -Werror
MLXDIR	=	./minilibx-linux
LIB_MLX	=	$(MLXDIR)/libmlx.a
LIBX_FLAGS	=	$(LIB_MLX) -lXext -lX11 -lm -L/usr/lib -L$(MLXDIR)/obj 

all:	$(NAME)

git:
	git clone https://github.com/42Paris/minilibx-linux.git minilibx-linux

$(NAME):	$(OBJS)
	$(MAKE) -C minilibx-linux
	$(CC) $(CFLAG) $(OBJS) $(LIBX_FLAGS) -o $(NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re