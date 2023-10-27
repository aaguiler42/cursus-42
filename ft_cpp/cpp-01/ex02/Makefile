NAME		= brain

CPP			= c++
CPPFLAGS	= -Wall -Werror -Wextra -std=c++98

SRC			= main.cpp
OBJ			= ${SRC:.cpp=.o}

all:	${NAME}

%.o: %.cpp
	${CPP} ${CPPFLAGS} -c $< -o $@

${NAME}:	${OBJ}
	${CPP} ${OBJ} -o ${NAME}

clean:
	rm -f ${OBJ}

fclean:	clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re