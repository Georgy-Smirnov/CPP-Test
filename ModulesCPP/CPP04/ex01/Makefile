SRCS	=	main.cpp \
			Animal.cpp \
			Cat.cpp \
			Dog.cpp \
			Brain.cpp

OBJS	=	$(SRCS:%.cpp=%.o)

HEAD	=	Animal.hpp \
			Cat.hpp \
			Dog.hpp \
			Brain.hpp

NAME	=	Brain

all:		${NAME}

${NAME}:	${OBJS} ${HEAD}
			clang++ -Wall -Werror -Wextra ${OBJS} -o $@

%.o:		%.cpp
			clang++ -Wall -Werror -Wextra -c $<

clean:
		rm -f ${OBJS}

fclean:	clean
		rm -f ${NAME}

re:		fclean all

.PHONY: all claen fclean re