SRCS		=	main.cpp \
				Point.cpp \
				bsp.cpp \
				Fixed.cpp

OBJS		=	${SRCS:%.cpp=%.o}

NAME		=	bsp

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
