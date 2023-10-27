NAME		= philo

SRCS		= src/utils/ft_atoi.c src/utils/time.c src/utils/init.c \
				src/utils/message.c src/main.c

OBJS		= ${SRCS:.c=.o}

CC			= cc

INCLUDES	= -I include

CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

all:	${NAME}

%.o: %.c
	${CC} ${CFLAGS} -o $@ -c $< ${INCLUDES}

${NAME}: ${OBJS}
	${CC} ${OBJS} ${INCLUDES} -o ${NAME}

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re: fclean all

normi:
	norminette ${SRCS} include

.PHONY: all, clean, fclean, re