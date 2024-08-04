#ifndef FT_H
# define FT_H

# include <fcntl.h>
# include <unistd.h>

/* Error messages and buffer size constant */
# define ERR_NO_FILE	"File name is missing.\n"
# define ERR_ARGS		"Too many arguments.\n"
# define ERR_READ		"Cannot read file.\n"
# define BUFFER_SIZE	4096

/* Function prototypes */
void	ft_putstr(char *str);
int		ft_validate_args(int argc);
int		ft_reading_file(char *file, char *buffer);

#endif
