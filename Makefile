NAME_SERVER = server
NAME_CLIENT = client
NAME		= $(NAME_CLIENT) $(NAME_SERVER)

SRC_SERVER = server.c mini_utils.c
SRC_CLIENT = client.c mini_utils.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus
NAME_BONUS = $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

SRC_SERVER_BONUS = server_bonus.c mini_utils_bonus.c
SRC_CLIENT_BONUS = client_bonus.c mini_utils_bonus.c

OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra

INCLUDES = -I. -Ilibft -Ilibftprintf

LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft

FT_PRINTF = ./ft_printf/libftprintf.a
FT_PRINTF_PATH = ./ft_printf

all: $(NAME)

$(NAME_SERVER): $(OBJ_SERVER) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ_SERVER) $(LIBFT) $(FT_PRINTF) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ_CLIENT) $(LIBFT) $(FT_PRINTF) -o $(NAME_CLIENT)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_PATH)

clean:
	rm -f *.o
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(FT_PRINTF_PATH) clean

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(FT_PRINTF_PATH) fclean

re: fclean all

bonus: $(NAME_BONUS)

$(NAME_SERVER_BONUS): $(OBJ_SERVER_BONUS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ_SERVER_BONUS) $(LIBFT) $(FT_PRINTF) -o $(NAME_SERVER_BONUS)

$(NAME_CLIENT_BONUS): $(OBJ_CLIENT_BONUS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ_CLIENT_BONUS) $(LIBFT) $(FT_PRINTF) -o $(NAME_CLIENT_BONUS)

.PHONY: all clean fclean re bonus
