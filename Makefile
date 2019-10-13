##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

CC			=	g++

RM			=	rm -f

SRCDIR		=	src/

SRC			=	main.cpp 										\
				Component/Component.cpp							\
                Component/C4008/C4008.cpp                       \
                Component/C4013/C4013.cpp                       \
				Component/C4017/C4017.cpp						\
                Component/C4040/C4040.cpp                       \
                Component/C4069/C4069.cpp                       \
				Component/C4094/C4094.cpp						\
                Component/C4514/C4514.cpp                       \
				Component/Input/Input.cpp 						\
                Component/Input/Clock/Clock.cpp              	\
                Component/Input/False/False.cpp                 \
                Component/Input/Output/Output.cpp               \
                Component/Input/True/True.cpp                	\
				Component/SimpleGate/SimpleGate.cpp 			\
                Component/SimpleGate/C4001/C4001.cpp            \
                Component/SimpleGate/C4011/C4011.cpp            \
                Component/SimpleGate/C4030/C4030.cpp      		\
                Component/SimpleGate/C4071/C4071.cpp      		\
                Component/SimpleGate/C4081/C4081.cpp       		\
				MyException/MyException.cpp						\
				Parser/Chipsets/Chipsets.cpp					\
				Parser/Links/Links.cpp							\
				Parser/Parser.cpp								\

OBJ			=	$(addprefix $(SRCDIR), $(SRC:.cpp=.o))

CXXFLAGS	=	-I src/

CXXFLAGS	+=	-Wall -Wextra

NAME		=	nanotekspice

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ)

all:		$(NAME)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
