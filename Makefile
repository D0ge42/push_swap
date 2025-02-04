NAME = push_swap
BONUS = checker
LIBFT = libft/libft.a

SRC = srcs/push_swap.c \
srcs/error_checking.c \
srcs/general_utils.c srcs/memory_handler.c \
srcs/push.c srcs/rotate.c \
srcs/rrotate.c\
 srcs/swap.c\
  srcs/algorithm.c\
 srcs/do_operations.c\
 srcs/algorithm_utils.c\
 srcs/sort_utils.c

BONUS_SRC = bonus/checker_bonus.c \
			bonus/error_checking_bonus.c\
			bonus/push_bonus.c\
			bonus/reader_bonus.c\
			bonus/rotate_bonus.c\
			bonus/rrotate_bonus.c\
			bonus/swap_bonus.c\
			bonus/memory_handler_bonus.c\
			bonus/sort_utils_bonus.c\
			bonus/general_utils_bonus.c\
			bonus/algorithm_utils_bonus.c\


OBJS = $(SRC:.c=.o)
BONUS_OBJS = $(BONUS_SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra -g -gdwarf-4
RM = rm -rf
AR = ar crs

# Regola per creare l'eseguibile
$(NAME): $(OBJS) $(LIBFT)
	@$(CC) -o $@ $(CFLAGS) $^ -Llibft -lft
	@echo "\033[32m$(NAME) compiled :D\033[0m"

$(BONUS): $(BONUS_OBJS) $(LIBFT)
	@$(CC) -o $@ $(CFLAGS) $^ -Llibft -lft
	@echo "\033[32m$(BONUS) compiled :D\033[0m"

# Regola per creare i file .o
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Regola all
all: $(NAME) $(BONUS)

bonus: $(BONUS)

$(LIBFT): 
	@$(MAKE) --no-print-directory -C libft

# Pulizia degli oggetti
clean:
	@$(RM) $(OBJS) 
	@$(RM) $(BONUS_OBJS) 
	@$(MAKE) --no-print-directory -C libft clean

# Pulizia completa
fclean: clean
	@$(RM) $(NAME) $(LIBFT) $(BONUS)

# Ricostruzione completa
re: fclean all

.PHONY: all clean fclean re bonus