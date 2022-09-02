CC 		= gcc
FLAGS 	= -Wall -Wextra -Werror
CLIENT 	= client.c utils.c conversions.c 
SERVER 	= server.c utils.c conversions.c 
NAMECL 	= client
NAMESR 	= server

all: $(NAMECL) $(NAMESR)
$(NAMECL):
	$(CC) $(FLAGS) $(CLIENT) -o client
$(NAMESR):
	$(CC) $(FLAGS) $(SERVER) -o server
clean:
	rm -rf client server
fclean: clean
re: fclean all
.PHONY: clean fclean re all
