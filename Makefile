NAME		:= libft.a
CC			:= cc
CFLAGS		:= -Wall -Werror -Wextra

SRC_LBFT	:= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
				ft_isprint.c ft_strlen.c

#OBJ_LKDLST	:=

OBJ_LBFT	:= $(SRC_LBFT:.c=.o)
#OBJ_LKDLST	:= $(SRC_LKDLST:.c=.o)

OBJ := $(OBJ_LBFT)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test:
	make && cc -Wall -Werror -Wextra tester.c libft.a && ./a.out && make fclean && rm a.out

.PHONY: all clean fclean re