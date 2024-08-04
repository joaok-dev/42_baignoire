#ifndef ARGS_H
# define ARGS_H

# include <stdlib.h>

# define MAX_ARGS		100
# define MAX_OPTS		50

typedef	struct	s_args
{
	char	*program_name;
	char	**args;
	char	**opt_flags;
	char	**opt_values;
	int		arg_count;
	int		opt_count;
}	t_args;

int				ft_strcmp(char *s1, char *s2);
int				ft_atoi(const char *str);
static int		ft_is_option(char *arg);
static void		ft_store_option(t_args *args, char *flag, char *value);
static void		ft_store_arg(t_args *args, char *arg);
int				ft_init_args(t_args *args);
void			ft_free_args(t_args *args);
int				ft_parse_args(int argc, char **argv, t_args *args);

#endif // !ARGS_H
