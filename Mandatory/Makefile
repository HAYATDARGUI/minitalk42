
src = client.c server.c
obj = $(src:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror


PRINTF_DIR = printf
PRINTF = ./printf/libftprintf.a


all: $(PRINTF) client server


$(PRINTF):
	@make -C $(PRINTF_DIR)


client: client.o $(PRINTF)
	$(CC) -o $@ $^ $(PRINTF)

server: server.o $(PRINTF)
	$(CC) -o $@ $^ $(PRINTF)


clean:
	rm -f $(obj)

fclean: clean
	@make -C $(PRINTF_DIR) fclean
	rm -f client server

re: fclean all
