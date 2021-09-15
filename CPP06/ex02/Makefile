SRCS	=	main.cpp

OBJS	=	$(SRCS:%.cpp=%.o)

HEAD	=	*.hpp

NAME	=	ex02

all:		${NAME}

${NAME}:	${OBJS} ${HEAD}
			clang++ --std=c++98 -Wall -Werror -Wextra ${OBJS} -o $@

%.o:		%.cpp
			clang++ --std=c++98 -Wall -Werror -Wextra -c $<

clean:
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME}

re:		fclean all

.PHONY: all claen fclean re