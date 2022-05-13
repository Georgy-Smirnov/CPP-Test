SRCS	=	AMateria.cpp \
			Character.cpp \
			Cure.cpp \
			Ice.cpp \
			MateriaSource.cpp \
			main.cpp


OBJS	=	$(SRCS:%.cpp=%.o)

HEAD	=	*.hpp

NAME	=	Interface

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