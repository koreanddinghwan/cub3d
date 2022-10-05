CC = cc

NAME = cub3D

FT = libft.a

PARSER_SRCS = check_open.c extension_checker.c delete_splited.c error_exit.c get_image_ptr.c get_rgb.c map_fill.c map_open.c map_reader.c map_validation.c map_make.c parser.c tools.c
PARSER_OBJS = $(PARSER_SRCS:.c=.o)

SRCS = $(PARSER_SRCS)
OBJS = $(SRCS:%.c=%.o)

CC = cc
CFLAG = -Wall -Wextra -Werror #-fsanitize=address -g3

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAG) $(OBJS) $(FT) libmlx.dylib -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c
	$(info    VAR is $(OBJS))
	$(CC) $(CFLAG) -I$(INC) -I$(FTINC) -c $^ -o $@ 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) *.dSYM
	

re: fclean all
