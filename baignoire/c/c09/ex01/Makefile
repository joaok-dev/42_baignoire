# Name of the library
NAME := libft.a

# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -Werror

# Directories
SRCDIR = srcs
INCDIR = includes

# Source and object files
SRCS = $(SRCDIR)/ft_putchar.c $(SRCDIR)/ft_swap.c $(SRCDIR)/ft_putstr.c $(SRCDIR)/ft_strlen.c $(SRCDIR)/ft_strcmp.c
OBJS = $(SRCS:.c=.o)

# Default target
all: $(NAME)

# Rule to create the library
$(NAME): $(OBJS)
	@echo "Creating library $(NAME)"
	@ar rcs $(NAME) $(OBJS)

# Rule to compile .c files into .o files
%.o: %.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# Rule to clean object files
clean:
	@echo "Cleaning object files"
	@rm -f $(OBJS)

# Rule to clean library file
fclean: clean
	@echo "Cleaning library $(NAME)"
	@rm -f $(NAME)

# Rebuild the projetc
re: fclean all

# Phony targets
.PHONY: all clean fclean re
