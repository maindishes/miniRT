NAME	=	a.out

#
# SRCS and OBJS
#

SRCS	=	\
			minirt.c

OBJS = $(SRCS:%.c=%.o)

#
# Compiler and flags
#

CC		=	clang
CFLAGS	=	-Wall -Werror -Wextra -g
CLIB	=	-L./minilibx -lmlx -framework OpenGL -framework Appkit -I./minilibx/

#
# Rules
#

all		: $(NAME)

%.o	:%.c
	$(CC) $(CFLAGS)  -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(CLIB) $(SRCS) -o $(NAME)
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

clean	:
	rm -rf $(OBJS)

fclean	: clean
	rm -rf	$(NAME)

re		: fclean all
