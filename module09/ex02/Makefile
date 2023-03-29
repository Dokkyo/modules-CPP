NAME1 = PmergeMe

SRCS1 = main.cpp PmergeMe.cpp

INCLUDE= .

OBJS1 = $(SRCS1:.cpp=.o)
DEPS1 = $(SRCS1:.cpp=.d)

CC= c++
FLAGS1= -Wall -Wextra -Werror -std=c++98 -g3

%.o:				%.cpp
	@$(CC) $(FLAGS) -MMD -c $< -o $@ -I $(INCLUDE)

all: $(NAME1)

$(NAME1): $(OBJS1)
	@echo "Compilation du programme $(NAME1)"
	$(CC) $(FLAGS1) $(OBJS1) -o $(NAME1)

clean:
	rm -Rf $(OBJS1) $(DEPS1)

fclean: clean
	rm -Rf $(NAME1) $(NAME2)

re: fclean all

-include $(DEPS1)
.PHONY: all clean fclean re