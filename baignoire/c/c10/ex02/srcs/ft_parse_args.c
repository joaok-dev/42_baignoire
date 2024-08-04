#include "../includes/args.h"
#include "../includes/ft.h"

/*
 * ft_strcmp - Compares two strings lexicographically
 *
 * This function compares two strings character by character
 * until a difference is found or the end of a string is reached.
 *
 * @s1: The first string to compare
 * @s2: The second string to compare
 *
 * Return: An integer less than, equal to, or greater than zero if s1 is found,
 *         respectively, to be less than, to match, or be greater than s2.
 *
 * Flow:
 * 1. While characters in both strings are equal and not null:
 *    a. Move to the next character in both strings
 * 2. Return the difference between the first differing characters,
 *    or 0 if strings are identical
 */
int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

/*
 * ft_atoi - Converts a string to an integer
 *
 * This function parses a string representation of an integer,
 * handling whitespace, signs, and numeric characters.
 *
 * @str: The input string to convert
 *
 * Return: The integer value of the parsed string
 *
 * Flow:
 * 1. Skip leading whitespace (space and control characters)
 * 2. Handle optional sign (+ or -)
 * 3. Parse numeric characters, building the integer value
 * 4. Apply the sign and return the result
 *
 * Note: This function uses ASCII values for character comparisons
 *       and does not handle overflow or underflow conditions.
 */
int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}

/*
 * ft_is_option - Checks if a given argument is an option
 *
 * This function determines if the argument is an option by checking
 * if it starts with '-' and is not just '-' alone.
 *
 * @arg: The argument string to check
 *
 * Return: 1 if the argument is an option, 0 otherwise
 *
 * Flow:
 * 1. Check if the first character is '-'
 * 2. Check if the second character is not '\0'
 * 3. Return the result of these conditions
 */
static int	ft_is_option(char *arg)
{
	return (arg[0] == '-' && arg[1] != '\0');
}

/*
 * ft_store_option - Stores an option and its value in the args structure
 *
 * This function adds an option flag and its corresponding value to the
 * args structure, if there's room available.
 *
 * @args: Pointer to the t_args structure
 * @flag: The option flag string
 * @value: The option value string
 *
 * Flow:
 * 1. Check if there's room for another option (opt_count < MAX_OPTS)
 * 2. If room available:
 *    a. Store the flag in opt_flags array
 *    b. Store the value in opt_values array
 *    c. Increment opt_count
 */
static void	ft_store_option(t_args *args, char *flag, char *value)
{
	if (args->arg_count < MAX_ARGS)
	{
		args->args[args->opt_count] = flag;
		args->opt_values[args->opt_count] = value;
		args->opt_count++;
	}
}

/*
 * ft_store_arg - Stores a non-option argument in the args structure
 *
 * This function adds a non-option argument to the args structure,
 * if there's room available.
 *
 * @args: Pointer to the t_args structure
 * @arg: The argument string to store
 *
 * Flow:
 * 1. Check if there's room for another argument (arg_count < MAX_ARGS)
 * 2. If room available:
 *    a. Store the argument in args array
 *    b. Increment arg_count
 */
static void	ft_store_arg(t_args *args, char *arg)
{
	if (args->arg_count < MAX_ARGS)
	{
		args->args[args->arg_count] = arg;
		args->arg_count++;
	}
}

/*
 * ft_init_args - Initializes the t_args structure
 *
 * This function allocates memory for the arrays in the t_args structure
 * and initializes its members.
 *
 * @args: Pointer to the t_args structure to initialize
 *
 * Return: 1 on success, 0 on failure (NULL input or memory allocation failure)
 *
 * Flow:
 * 1. Check if args is not NULL
 * 2. Initialize program_name, arg_count, and opt_count
 * 3. Allocate memory for args, opt_flags, and opt_values arrays
 * 4. If any allocation fails, free all allocated memory and return 0
 * 5. Return 1 on successful initialization
 */
int	ft_init_args(t_args *args)
{
	if (!args)
		return (0);
	args->program_name = NULL;
	args->arg_count = 0;
	args->opt_count = 0;
	args->args = (char **)malloc(MAX_ARGS * sizeof(char *));
	args->opt_flags = (char **)malloc(MAX_OPTS * sizeof(char *));
	args->opt_values = (char **)malloc(MAX_OPTS * sizeof(char *));
	if (!args->args || !args->opt_flags || !args->opt_values)
	{
		ft_free_args(args);
		return (0);
	}
	return (1);
}

/*
 * ft_free_args - Frees memory allocated for the t_args structure
 *
 * This function releases the memory allocated for the arrays in the
 * t_args structure and sets the pointers to NULL.
 *
 * @args: Pointer to the t_args structure to free
 *
 * Flow:
 * 1. Check if args is not NULL
 * 2. Free memory for args, opt_flags, and opt_values arrays
 * 3. Set the freed pointers to NULL
 */
void	ft_free_args(t_args *args)
{
	if (args)
	{
		free(args->args);
		free(args->opt_flags);
		free(args->opt_values);
		args->args = NULL;
		args->opt_flags = NULL;
		args->opt_values = NULL;
	}
}

/*
 * ft_parse_args - Parses command-line arguments into the t_args structure
 *
 * This function initializes the t_args structure, processes the command-line
 * arguments, separating options and their values from non-option arguments,
 * and stores them in the provided t_args structure.
 *
 * @argc: The number of command-line arguments
 * @argv: The array of command-line argument strings
 * @args: Pointer to the t_args structure to store parsed arguments
 *
 * Return: 1 on success, 0 on failure (invalid input or parsing error)
 *
 * Flow:
 * 1. Validate input parameters
 * 2. Initialize the args structure
 * 3. Store the program name (first argument)
 * 4. Iterate through arguments starting from the second one:
 *    a. If argument is an option:
 *       - Ensure there's a value for the option
 *       - Store option and its value
 *       - Move to the next argument after the value
 *    b. If argument is not an option:
 *       - Store as a regular argument
 *       - Move to the next argument
 * 5. Return 1 if parsing completes successfully, 0 otherwise
 */
int ft_parse_args(int argc, char **argv, t_args *args)
{
	char	**arg_ptr;

	if (!args || !argv || argc < 1)
		return (0);
	if (!ft_init_args(args))
		return (0);
	args->program_name = *argv;
	arg_ptr = argv + 1;
	while (arg_ptr < argv + argc)
	{
		if (ft_is_option(*arg_ptr))
		{
			if (arg_ptr + 1 >= argv + argc)
			{
				ft_free_args(args);
				return (0);
			}
			ft_store_option(args, *arg_ptr, *(arg_ptr + 1));
			arg_ptr += 2;
		}
		else
		{
			ft_store_arg(args, *arg_ptr);
			arg_ptr++;
		}
	}
	return (1);
}

