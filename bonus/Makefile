CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = client_bonus.c server_bonus.c

OBJS = server_bonus.o

OBJC = client_bonus.o

SRV_NAME = ../server_bonus

CLT_NAME = ../client_bonus

all : $(CLT_NAME) $(SRV_NAME)

$(CLT_NAME) : $(OBJC)
	$(CC) $(CFLAGS) $< -o $@

$(SRV_NAME) : $(OBJS)
	$(CC) $(CFLAGS) $< -o $@

%.o : %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -fr $(OBJS) $(OBJC)
 
fclean : clean
	rm -rf $(SRV_NAME) $(CLT_NAME)

re : fclean all

.PHONY : all clean fclean re
