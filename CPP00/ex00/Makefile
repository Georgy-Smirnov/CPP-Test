SRC		=	megaphone.cpp

OBJ		=	${SRC:%.cpp=%.o}

NAME	=	megaphone

all:		${NAME}

${NAME}:	${OBJ}
			clang++ $< -o $@

%.o:		%.cpp
			clang++ -c $<

clean:		
			rm -f ${OBJ}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re