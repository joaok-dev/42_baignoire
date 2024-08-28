#ifndef DO_OP_H
# define DO_OP_H
# include <unistd.h>

// argument parsing
int		ft_parse_arg(int argc, char **argv, int *num1, int *num2, char *op);

// basic operator functions
int		ft_add(int a, int b);
int		ft_subtract(int a, int b);
int		ft_multiply(int a, int b);
int		ft_divide(int a, int b);
int		ft_modulo(int a, int b);

// core operation functions
void	ft_itoa(int n, char *buffer);
void	ft_print_result(int result);
void	ft_handle_operation(int num1, int num2, char op);

// pointer array
int		(*ft_get_operator_function(char op))(int, int);

// error handling
void	ft_handle_division_by_zero(void);
void	ft_handle_modulo_by_zero(void);
void	ft_handle_invalid_operator(void);

// main
int		main(int argc, char **argv);

#endif // !DO_OP_H
