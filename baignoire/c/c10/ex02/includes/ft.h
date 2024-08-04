#ifndef FT_H
# define FT_H

# include <errno.h>
# include <fcntl.h>
# include <libgen.h>
# include <string.h>
# include <unistd.h>

/* Macros */
# define ERR_ARGS		"Invalid arguments.\n"
# define ERR_READ		"Error reading file.\n"
# define BUFFER_SIZE	30000

/* Functions prototypes */
void		ft_putchar(char c);
void		ft_putstr(char *str);
int			ft_validate_args(int argc, char **argv);
void		ft_display_error(char *filename);
int			ft_read_and_write(int fd, char *filename);
int			ft_handle_file(char *filename);

#endif // !FT_H
