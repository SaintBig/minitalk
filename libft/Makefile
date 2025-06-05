# Variables
NAME        = libft.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
HPATH       = ./

# Source files
SRCPATH = ./
SRCFILES = ft_isprint.c ft_putstr_fd.c ft_strncmp.c ft_atoi.c ft_itoa.c ft_split.c\
			ft_strnstr.c ft_bzero.c ft_memcpy.c ft_striteri.c ft_substr.c ft_calloc.c\
			ft_memmove.c ft_strjoin.c ft_tolower.c ft_isalnum.c ft_memset.c ft_strlcat.c\
			ft_toupper.c ft_memchr.c ft_strchr.c ft_strrchr.c ft_memcmp.c ft_strdup.c\
			ft_strtrim.c ft_isalpha.c ft_putchar_fd.c ft_strlcpy.c ft_isascii.c\
			ft_putendl_fd.c ft_strlen.c ft_isdigit.c ft_putnbr_fd.c  ft_strmapi.c

BONUSFILES = ft_lstadd_back_bonus.c ft_lstclear_bonus.c ft_lstlast_bonus.c ft_lstnew_bonus.c\
				ft_lstadd_front_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c ft_lstsize_bonus.c\
				ft_lstdelone_bonus.c

SRCS = $(addprefix $(SRCPATH), $(SRCFILES))
BONUS_SRCS = $(addprefix $(SRCPATH), $(BONUSFILES))

# Object files
OBJS        = $(SRCS:.c=.o)
BONUS_OBJS  = $(BONUS_SRCS:.c=.o)

# Header file
HEADER      = libft.h

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I$(HPATH) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	rm -f .bonus 

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: .bonus

.bonus: $(NAME) $(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)
	touch .bonus

.PHONY: all bonus clean fclean re