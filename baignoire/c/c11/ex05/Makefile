# Name of the executable
NAME := do-op

# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -Werror

# Directories
SRCDIR := srcs
INCDIR := includes

# Source files
SRCS := $(SRCDIR)/core_operation.c \
        $(SRCDIR)/error_handling.c \
        $(SRCDIR)/main.c \
        $(SRCDIR)/operators.c \
        $(SRCDIR)/parse_arg.c \
        $(SRCDIR)/pointer_array.c

# Object files
OBJS := $(SRCS:.c=.o)

# Default target
all: $(NAME)

# Rule to create the executable
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -I$(INCDIR) -o $(NAME) $(OBJS)

# Rule to compile .c files into .o files
%.o: %.c
	@$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# Rule to clean object files
clean:
	@rm -f $(OBJS)

# Rule to clean executable file
fclean: clean
	@rm -f $(NAME)

# Rebuild the project
re: fclean all

# Phony targets
.PHONY: all clean fclean re

