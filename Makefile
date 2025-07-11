CC = cc
CFLAGS = -Wall -Wextra -Werror

SERVER_NAME = server
SERVER_SRC = server.c
SERVER_OBJ = $(SERVER_SRC:.c=.o)

CLIENT_NAME = client
CLIENT_SRC = client.c
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

UTILS_SRC = utils.c
UTILS_OBJ = $(UTILS_SRC:.c=.o)

all: $(SERVER_NAME) $(CLIENT_NAME)

$(CLIENT_NAME): $(CLIENT_OBJ) $(UTILS_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_SRC) $(UTILS_SRC) -o $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJ) $(UTILS_OBJ)
	$(CC) $(CFLAGS) $(SERVER_SRC) $(UTILS_SRC) -o $(SERVER_NAME)

clean: 
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ) $(UTILS_OBJ)

fclean: clean
	rm -f $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all