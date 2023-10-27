NAME		= cub3d

SRCS		= src/main.c src/hooks.c src/loop.c src/terminate.c src/init.c src/utils.c\
				src/utils_graphics.c src/utils_colors_init.c src/utils_init.c\
				src/utils_map_init.c src/utils_player_init.c src/utils_textures_init.c\
				src/display/display.c src/display/rays.c

OBJS		= ${SRCS:.c=.o}

CC			= gcc

INCLUDES	= -I include -I MLX42/include/MLX42 -I libft

LIBS		= MLX42/libmlx42.a -lglfw -lm -L /Users/${USER}/.brew/opt/glfw/lib/ -L libft -l ft

CFLAGS		= -Wall -Wextra -Werror -g

RM			= rm -f

all:	${NAME}

%.o: %.c
	${CC} ${CFLAGS} -o $@ -c $< ${INCLUDES}

${NAME}: ${OBJS}
	make -C MLX42
	make -C libft
	${CC} ${OBJS} ${LIBS} ${INCLUDES} -o ${NAME}

clean:
	make clean -C MLX42
	make clean -C libft
	${RM} ${OBJS}

fclean:	clean
	make fclean -C MLX42
	make fclean -C libft
	${RM} ${NAME}

re: fclean all

normi:
	norminette ${SRCS} include

.PHONY: all, clean, fclean, re