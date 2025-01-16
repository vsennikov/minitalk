CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_C = $(LIBFT_PATH)/*.c
INCLUDES = -I./$(LIBFT_PATH)
SERVER_SRC = server.c utils.c server_utils.c
SERVER_O = $(SERVER_SRC:.c=.o)
CLIENT_SRC = client.c utils.c
CLIENT_O = $(CLIENT_SRC:.c=.o)

SERVER_NAME = server
CLIENT_NAME = client

all: $(LIBFT) $(SERVER_NAME) $(CLIENT_NAME)

$(LIBFT): $(LIBFT_C)
	$(MAKE) -C ./libft

$(SERVER_NAME): $(SERVER_O) $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_O) -L./$(LIBFT_PATH) -lft -o $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_O) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_O) -L./$(LIBFT_PATH) -lft -o $(CLIENT_NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(MAKE)  -C ./libft clean
	@rm -f $(SERVER_O) $(CLIENT_O)

fclean: clean
	@$(MAKE) -C ./libft fclean
	@rm -f $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all

.PHONY: all clean fclean re