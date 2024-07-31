#!/bin/sh

# Script to ocmpile C files and create a static library
# Usage: ./create_libft.sh

set -e  # Exit immediately if a command exits with a non-zero status

# Use provided arguments or default files
files=${@:-"ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c"}

# Compile C files
echo "Compiling source files..."
gcc -Wall -Wextra -Werror -c $files

# Create library
echo "Creating library..."
ar rcs libft.a *.o

# Cleanup
echo "Cleaning up..."
rm -f *.o

echo "Library creation completed successfully"
