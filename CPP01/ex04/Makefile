SRCS		=	main.cpp

OBJS		=	${SRCS:%.cpp=%.o}

NAME		=	replace

all:		${NAME}

${NAME}:	${OBJS}
			clang++ -Wall -Werror -Wextra $^ -o $@

%.o:		%.cpp
			clang++ -Wall -Werror -Wextra -c $<

clean:		
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}
			rm *.replace

re:			fclean all

.PHONY:		all clean fclean re
