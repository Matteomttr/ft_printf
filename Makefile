NAME= libft.a
CC= cc
CFLAGS= -Wall -Werror -Wextra
AR= ar
ARFLAGS= rsc
SRCS=	ft_isalpha.c \

OBJS= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
