NAME = all

CC = gcc
RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft/libft.a

SERVER = server
CLIENT = client

S_SRCS = server.c utils.c
C_SRCS = client.c utils.c

S_OBJS = $(S_SRCS:.c=.o)
C_OBJS = $(C_SRCS:.c=.o)

all: $(SERVER) $(CLIENT)

$(LIBFT):
	$(MAKE) -C libft

$(SERVER): $(S_OBJS) $(LIBFT) 
	$(CC) $(CFLAGS) $(S_OBJS) $(LIBFT) -o server
$(CLIENT): $(C_OBJS) $(LIBFT) 
	$(CC) $(CFLAGS) $(C_OBJS) $(LIBFT) -o client

clean:
	$(MAKE) clean -C libft
	$(RM) $(S_OBJS) $(C_OBJS)
fclean: clean
	$(MAKE) fclean -C libft
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

mandatory: $(CLIENT) $(SERVER)
bonus: mandatory