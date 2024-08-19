# Name of the executable
NAME := ft_hexdump

# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -Werror

# Directories
SRCDIR := srcs
INCDIR := includes

# Source files
SRCS := $(SRCDIR)/ft_hexdump.c \
        $(SRCDIR)/ft_utils.c \
        $(SRCDIR)/ft_args_parse.c \
        $(SRCDIR)/ft_file_handle.c \
        $(SRCDIR)/ft_error_handle.c \
        $(SRCDIR)/ft_hexdump_core.c \

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
