NAME		:= libft.a
CC			:= cc
CFLAGS		:= -Wall -Werror -Wextra

SRC_LBFT	:= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
				ft_isprint.c ft_toupper.c ft_tolower.c ft_toint.c \
				ft_tochar.c ft_isspace.c \
				ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c \
				ft_memcmp.c ft_bzero.c ft_calloc.c \
				ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c \
				ft_strrchr.c ft_strcmp.c ft_strncmp.c ft_strnstr.c \
				ft_strdup.c ft_str_mallocpy.c ft_substr.c ft_strjoin.c \
				ft_strtrim.c ft_split.c ft_atoi.c ft_isdigit.c ft_itoa.c ft_strmapi.c \
				ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
				ft_putnbr_fd.c ft_strlower.c ft_streq.c ft_atod.c \
				ft_abs.c ft_atoi_err.c ft_next_p2.c ft_issign.c

SRC_LKDLST	:= ft_lst_add.c ft_lst_del.c ft_lst_manage.c \
				ft_lst_get.c ft_lst_getcont.c
			
OBJ_LBFT	:= $(SRC_LBFT:.c=.o)
OBJ_LKDLST	:= $(SRC_LKDLST:.c=.o)

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

.PHONY: all clean fclean re