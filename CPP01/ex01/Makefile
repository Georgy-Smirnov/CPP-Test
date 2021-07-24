SRCS		=	Zombie.cpp \
				main.cpp \
				ZombieHorde.cpp \

OBJS		=	${SRCS:%.cpp=%.o}

NAME		=	zombie

all:		${NAME}

${NAME}:	${OBJS}
			clang++ -Wall -Werror -Wextra $^ -o $@

%.o:		%.cpp
			clang++ -Wall -Werror -Wextra -c $<

clean:		
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
