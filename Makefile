SERVER = server
CLIENT = client
CC = cc
CFLAGS = -Wall -Wextra -Werror

SERVER_SRC = server.c
CLIENT_SRC = client.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

LIBS_DIR = ./libft
LIBFT = $(LIBS_DIR)/libft.a

HEADERS = -I$(LIBS_DIR)/inc

LDFLAGS = -L$(LIBS_DIR)
LDLIBS = -lft

all: $(LIBFT) $(SERVER) $(CLIENT)

%.o: %.c
		$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(SERVER): $(LIBFT) $(SERVER_OBJ)
		$(CC) $(SERVER_OBJ) $(LDFLAGS) $(LDLIBS) -o $(SERVER)

$(CLIENT): $(LIBFT) $(CLIENT_OBJ)
		$(CC) $(CLIENT_OBJ) $(LDFLAGS) $(LDLIBS) -o $(CLIENT)

$(LIBFT):
		$(MAKE) -C $(LIBS_DIR)

clean:
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ)
	$(MAKE) -C $(LIBS_DIR) clean

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	$(MAKE) -C $(LIBS_DIR) fclean

re: fclean all

.PHONY: all clean fclean re