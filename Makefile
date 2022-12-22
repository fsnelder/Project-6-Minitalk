SRC = client.c server.c utils.c 

OBJ = $(SRC:.c=.o)

CLIENT = client
SERVER = server

CFLAGS = -Werror -Wall -Wextra

all: $(SERVER) $(CLIENT)

$(CLIENT): client.o utils.o
	gcc $(CFLAGS) $^ -o $(CLIENT)

$(SERVER): server.o utils.o
	gcc $(CFLAGS) $^ -o $(SERVER)

%.o: %.c minitalk.h
	gcc $(CFLAGS) $< -c -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all
