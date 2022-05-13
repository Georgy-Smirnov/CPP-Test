SRCS	=	main.cpp \
			Animal.cpp \
			Cat.cpp \
			Dog.cpp \
			WrongAnimal.cpp \
			WrongCat.cpp

OBJS	=	$(SRCS:%.cpp=%.o)

HEAD	=	Animal.hpp \
			Cat.hpp \
			Dog.hpp \
			WrongAnimal.hpp \
			WrongCat.hpp

NAME	=	Polimorphism

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