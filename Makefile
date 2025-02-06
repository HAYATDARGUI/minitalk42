
src = ./Mandatory/client.c ./Mandatory/server.c

srcb = ./bonus/client_bonus.c ./bonus/server_bonus.c

obj = $(src:.c=.o)

objb = $(srcb:.c=.o)


CC = gcc

CFLAGS = -Wall -Wextra -Werror


all:  client server

bonus : server_bonus client_bonus

client: ./Mandatory/client.o 
	$(CC)  $(CFLAGS) $< -o $@

client_bonus: ./bonus/client_bonus.o 
	$(CC)  $(CFLAGS) $< -o $@

server_bonus: ./bonus/server_bonus.o
	$(CC)  $(CFLAGS) $< -o $@

server: ./Mandatory/server.o
	$(CC)  $(CFLAGS) $< -o $@

%.o :  %.c  ./Mandatory/minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(obj)
	rm -f $(objb)


fclean: clean
	rm -f client server client_bonus server_bonus

re: fclean all

.PHONY: all server client all clean re bonus client_bonus server_bonus
