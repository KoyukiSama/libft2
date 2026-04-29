NAME		:= libft.a
CC			:= cc
CFLAGS		:= -Wall -Werror -Wextra

SRC_LBFT	:= ft_atoi.c ft_memcpy.c ft_striteri.c ft_substr.c \
				ft_bzero.c ft_memmove.c ft_strjoin.c ft_tolower.c \
				ft_memset.c ft_strlcat.c ft_toupper.c ft_isalnum.c \
				ft_calloc.c ft_putchar_fd.c ft_strlcpy.c ft_isalpha.c \
				ft_putnbr_fd.c ft_strmapi.c ft_isdigit.c ft_putstr_fd.c \
				ft_putendl_fd.c ft_strlen.c ft_isascii.c ft_strncmp.c \
				ft_isprint.c ft_split.c ft_strnstr.c ft_itoa.c \
				ft_memchr.c ft_strchr.c ft_strrchr.c ft_memcmp.c \
				ft_strdup.c ft_strtrim.c

SRC_LKDLST	:= ft_lstnew.c ft_lstlast.c ft_lstiter.c ft_lstdelone.c \
				ft_lstadd_front.c ft_lstclear.c ft_lstmap.c ft_lstsize.c \
				ft_lstadd_back.c


OBJ_LBFT	:= $(SRC_LBFT:.c=.o)
OBJ_LKDLST	:= $(SRC_LKDLST:.c=.o)

OBJ := $(OBJ_LBFT) $(OBJ_LKDLST)

all: $(MAKE)

$(MAKE): $(OBJ)
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
