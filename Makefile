NAME = cub3D
INC = ./inc/

FTDIR = ./libft/
FT = libft.a
FTINC = ./libft/

PARSER_SRCS = $(addprefix ./src/parser/, check_open.c extension_checker.c delete_splited.c error_exit.c get_image_ptr.c get_rgb.c \
map_fill.c map_open.c map_reader.c map_validation.c map_make.c parser.c tools.c)

MAIN_SRCS = main.c
KEY_SRCS = ./src/key/key.c ./src/key/move.c
RAYCASTING_SRCS = ./src/raycasting/ray.c
UTILS_SRCS = ./src/utils/utils.c ./src/utils/utils_2.c

SRCS = $(MAIN_SRCS) $(KEY_SRCS) $(RAYCASTING_SRCS) $(UTILS_SRCS) $(PARSER_SRCS)
OBJS = $(SRCS:%.c=%.o)

CC = cc
CFLAG = -Wall -Wextra -Werror
\CFLAG = -fsanitize=address -g3

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	make all -j 4 -C $(FTDIR) #recursively create libft
	mv $(FTDIR)$(FT) ./$(FT) #move in root dir
	$(CC) $(CFLAG) -I$(INC) -I$(FTINC) $(SRCS) $(FT) minilibx_opengl_20191021/libmlx.a -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c
	$(info    VAR is $(OBJS))
	$(CC) $(CFLAG) -I$(INC) -I$(FTINC) -c $^ -o $@ 

clean:
	make clean -C $(FTDIR)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) *.dSYM
	$(RM) *.a
	

re: fclean all

.PHONY: all clean fclean re
