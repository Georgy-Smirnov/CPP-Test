SRCS	=	main.cpp

OBJS	=	$(SRCS:%.cpp=%.o)

NAME	=	ex01

all:		${NAME}

${NAME}:	${OBJS}
			clang++ --std=c++98 -Wall -Werror -Wextra ${OBJS} -o $@

%.o:		%.cpp
			clang++ --std=c++98 -Wall -Werror -Wextra -c $<

clean:
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME}

re:		fclean all

.PHONY: all claen fclean re