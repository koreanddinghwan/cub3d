NAME = cub3D
SRCS = ./main.c
OBJS = $(SRCS:%.c=%.o)

CC = cc
# CFLAG = -Wall -Wextra -Werror
CFLAG = -fsanitize=address -g3

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAG) $(SRCS) minilibx_opengl_20191021/libmlx.a -framework OpenGL -framework AppKit -o $(NAME)
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) *.dSYM
	

re: fclean all

.PHONY: all clean fclean re