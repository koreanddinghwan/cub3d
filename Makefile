NAME = cub3D
INC = ./inc/

FTDIR = ./libft/
FT = libft.a
FTINC = ./libft/

PARSER_SRCS = $(addprefix ./srcs/parser/, check_open.c extension_checker.c fill_map.c parser.c)
PARSER_OBJS = $(PARSER_SRCS:.c=.o)

MAIN_SRCS = main.c
MAIN_OBJS = $(MAIN_SRCS:.c=.o)

SRCS = $(MAIN_OBJS) $(PARSER_OBJS)
OBJS = $(SRCS:%.c=%.o)

CC = cc
# CFLAG = -Wall -Wextra -Werror
CFLAG = -fsanitize=address -g3

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAG) -I$(INC) -I$(FTINC) $(SRCS) $(FT) minilibx_opengl_20191021/libmlx.a -framework OpenGL -framework AppKit -o $(NAME)
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) *.dSYM
	

re: fclean all

.PHONY: all clean fclean re
