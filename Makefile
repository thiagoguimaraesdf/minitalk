CLIENT = client

SERVER = server

SRC = client.c server.c

OBJ = ${SRC:.c=.o}

all: $(CLIENT) $(SERVER) 

$(CLIENT): client.c
	$(MAKE) -C ./libft
	@gcc -Wall -Wextra -Werror $< -L./libft -lft -o $@

$(SERVER): server.c
	@gcc -Wall -Wextra -Werror $< -L./libft -lft -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(CLIENT) $(SERVER)

re: fclean all
