SRCS =	Zombie.cpp \
		randomChump.cpp \
		newZombie.cpp \
		main.cpp

OBJS = ${SRCS:.cpp=.o}

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 

RM = rm -rf

NAME = zombie

all :		$(NAME)

$(NAME): $(OBJS)
	$(CC) -o $@ $^ $(FLAGS)

%.o: %.cpp
	$(CC) -o $@ -c $< $(FLAGS)

clean :
			${RM} ${OBJS}

fclean :	clean
			${RM} $(NAME)

re :		fclean all

.PHONY:		all bonus clean fclean re
