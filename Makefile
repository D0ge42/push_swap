NAME = push_swap
LIBFT = libft/libft.a

SRC = push_swap.c error_checking.c utils.c utils2.c push.c rotate.c rrotate.c swap.c

OBJS = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra -g -gdwarf-4
RM = rm -rf
AR = ar crs

# Regola per creare l'eseguibile
$(NAME): $(OBJS) $(LIBFT)
	@$(CC) -o push_swap $(CFLAGS) $(OBJS) -Llibft -lft
	@echo "\033[32m$(NAME) compiled :D\033[0m"

# Regola per creare i file .o
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Regola all
all: $(NAME) libft

bonus: all

$(LIBFT): 
	@$(MAKE) --no-print-directory -C libft

# Pulizia degli oggetti
clean:
	@$(RM) $(OBJS)
	@$(MAKE) --no-print-directory -C libft clean

# Pulizia completa
fclean: clean
	@$(RM) $(NAME) $(LIBFT)

# Ricostruzione completa
re: fclean all

.PHONY: all clean fclean re bonus