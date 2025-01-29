NAME = push_swap
LIBFT = libft/libft.a

SRC = srcs/push_swap.c \
srcs/error_checking.c \
srcs/utils.c srcs/utils2.c \
srcs/push.c srcs/rotate.c \
srcs/rrotate.c\
 srcs/swap.c\
  srcs/algorithm.c\
 srcs/do_operations.c\
 srcs/utils3.c\
 srcs/utils4.c

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