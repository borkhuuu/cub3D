SRCS := ft_print_arr.c ft_realloc.c get_next_line.c get_next_line_utils.c ft_isprint.c ft_strcmp.c ft_putchar_fd.c ft_strjoin.c ft_strtrim.c ft_atoi.c ft_itoa.c ft_putendl_fd.c ft_strlcat.c ft_substr.c ft_bzero.c ft_putnbr_fd.c ft_strlcpy.c ft_tolower.c ft_calloc.c ft_memchr.c ft_putstr_fd.c ft_strlen.c ft_toupper.c ft_isalnum.c ft_memcmp.c ft_split.c ft_strmapi.c ft_isalpha.c ft_memcpy.c ft_strchr.c ft_strncmp.c ft_isascii.c ft_memmove.c ft_strdup.c ft_strnstr.c ft_isdigit.c ft_memset.c ft_striteri.c ft_strrchr.c
B_SRCS := ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJS := $(SRCS:.c=.o)
B_OBJS := $(B_SRCS:.c=.o)
HEADER := libft.h
CFLAGS = -Wall -Wextra -Werror
CC = cc
NAME = libft.a
FLAG = .flag

.PHONY: all clean fclean re bonus

make: all

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS) $(B_OBJS)

fclean: clean
	@rm -rf $(NAME) $(FLAG)

re:	fclean all

bonus: $(FLAG)

$(FLAG): $(B_OBJS)
	@ar rcs $(NAME) $(B_OBJS)
	@touch .flag

$(B_OBJS): $(B_SRCS) $(HEADER)
	@$(CC) $(CFLAGS) -c $(B_SRCS)
