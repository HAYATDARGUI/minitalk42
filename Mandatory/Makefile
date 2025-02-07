CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = client.c server.c

OBJS = server.o

OBJC = client.o

SRV_NAME = ../server

CLT_NAME = ../client

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