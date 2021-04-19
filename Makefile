NAME = ft_containers

CC = clang++

FLAGS = -Werror -Wextra -Wall -Wconversion -g3 -fsanitize=address

CCF = $(CC) $(FLAGS)

RM = rm -f

LIST_SRC = includes/


all: $(NAME)

$(NAME): $(LIST_OBJS) $(LIST_SRC) srcs/main.cpp
	$(CCF) $(LIST_OBJS) srcs/main.cpp -o $@ -I$(LIST_SRC)


clean:
	$(RM) $(LIST_OBJS) $(NAME)

fclean: clean
	$(RM) $(NAME)

re: fclean all