NAME_SERVER = server
NAME_CLIENT = client
NAME		= $(NAME_CLIENT) $(NAME_SERVER)

SRC_SERVER = server.c mini_utils.c
SRC_CLIENT = client.c mini_utils.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

SRC_SERVER_BONUS = server_bonus.c mini_utils_bonus.c
SRC_CLIENT_BONUS = client_bonus.c mini_utils_bonus.c

OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS.c=.o)
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra

INCLUDES = -I. -Ilibft -Ilibftprintf

LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft

FT_PRINTF = ./ft_printf/libftprintf.a
FT_PRINTF_PATH = ./ft_printf

all: $(NAME)

$(NAME_SERVER): $(OBJ_SERVER) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(NAME_CLIENT)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: fclean all

.PHONY: all clean fclean re
