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

EXE = pipex

all: $(FILES) $(EXE)

$(NAME): $(OBJS) $(LIB)
	ar rc $(NAME) $(OBJS)

$(OBJS): $(FILES) $(LIB)
	gcc $(FLAGS) -c $(FILES)

$(EXE): $(OBJS)
	$(CC) $(OBJS) -o $@
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(EXE)

re: fclean all

.PHONY: all clean fclean re

