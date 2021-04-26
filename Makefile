NAME = ft_containers

CC = clang++

SAN_FLAGS = -Werror -Wextra -Wall -Wconversion -std=c++98 -g3 -fsanitize=address

FLAGS = -Werror -Wextra -Wall -Wconversion -std=c++98 -g3

CCF = $(CC) $(FLAGS)

RM = rm -f

LIST_SRC = includes/List.hpp


all: $(NAME)

$(NAME): $(LIST_OBJS) $(LIST_SRC) srcs/main.cpp
	@$(CCF) $(LIST_OBJS) srcs/main.cpp -o $@ -I$(LIST_SRC)

fsan: $(LIST_OBJS) $(LIST_SRC) srcs/main.cpp
	@$(CC) $(SAN_FLAGS) $(LIST_OBJS) srcs/main.cpp -o $(NAME) -I$(LIST_SRC)


clean:
	@$(RM) $(LIST_OBJS) $(NAME)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
	@./$(NAME)
ref: fclean fsan
	@printf "\e[93mFSANITIZE ACTIVATED !\n\e[0m"
	@./$(NAME)

rel: fclean all
	@printf "\e[92mLEAKS CHECK !\n\e[0m"
	@leaks -atExit -- ./$(NAME)