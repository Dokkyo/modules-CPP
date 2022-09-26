SRCS =	main.cpp \
		Winner.cpp

OBJS = ${SRCS:.cpp=.o}

CC = c++

FLAGS = -Wall -Wextra -Werror -g -std=c++98 

RM = rm -rf

NAME = winner

all :		$(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

clean :
			@${RM} ${OBJS}

fclean :	clean
			@${RM} $(NAME)
			@${RM} *.replace

re :		fclean all

.PHONY:		all bonus clean fclean re
