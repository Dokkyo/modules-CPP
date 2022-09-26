SRCS =	megaphone.cpp

OBJS = ${SRCS:.cpp=.o}

CC = c++

FLAGS = -Wall -Wextra -Werror -g -std=c++98 

RM = rm -rf

NAME = megaphone

all :		$(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

clean :
			@${RM} ${OBJS}

fclean :	clean
			@${RM} $(NAME)

re :		fclean all

.PHONY:		all bonus clean fclean re
