SRC = ft_putstr.c  ft_putchar.c  ft_printf.c ft_putnbr.c ft_puthexa.c ft_putunsigned.c ft_putp.c\

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

RM = rm -rf

AR = ar rcs

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o :  %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re