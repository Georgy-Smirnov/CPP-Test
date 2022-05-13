SRCS	=	main.cpp \
			ClapTrap.cpp \
			ScavTrap.cpp

OBJS	=	$(SRCS:%.cpp=%.o)

NAME	=	Serena

all:		${NAME}

${NAME}:	${OBJS}
			clang++ -Wall -Werror -Wextra $^ -o $@

%.o:		%.cpp
			clang++ -Wall -Werror -Wextra -c $<

clean:
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME}

re:		fclean all

.PHONY: all claen fclean re