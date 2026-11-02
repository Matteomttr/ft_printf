NAME= libftprintf.a
CC= cc
CFLAGS= -Wall -Werror -Wextra
AR= ar
ARFLAGS= rsc
SRC_DIR= SRC
OBJ_DIR= OBJ
SRCS=	$(SRC_DIR)/ft_printf.c \
		$(SRC_DIR)/ft_putchar_fd.c \
		$(SRC_DIR)/ft_puthexa_fd.c \
		$(SRC_DIR)/ft_putnbr_fd.c \
		$(SRC_DIR)/ft_putstr_fd.c \
		$(SRC_DIR)/ft_putptr_fd.c \
		$(SRC_DIR)/ft_countargs.c \

OBJS=	$(OBJ_DIR)/ft_printf.o \
		$(OBJ_DIR)/ft_putchar_fd.o \
		$(OBJ_DIR)/ft_puthexa_fd.o \
		$(OBJ_DIR)/ft_putnbr_fd.o \
		$(OBJ_DIR)/ft_putstr_fd.o \
		$(OBJ_DIR)/ft_putptr_fd.o \
		$(OBJ_DIR)/ft_countargs.o \

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
