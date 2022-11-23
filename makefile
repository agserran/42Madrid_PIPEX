FILES = checkers.c \
       patht.c \
	pipex.c \
 	utils.c \
	utils2.c \

OBJS = $(FILES:.c=.o)

NAME = pipex.a

CFLAGS = -Wall -Werror -Wextra

CC = gcc

LIB = pipex.h

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	ar rc $(NAME) $(OBJS)

$(OBJS): $(FILES) $(LIB)
	gcc $(FLAGS) -c $(FILES)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
