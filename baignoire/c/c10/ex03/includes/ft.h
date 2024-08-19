#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>
# include <libgen.h>

# define BUFFER_SIZE 16
# define HEX_CHARS "0123456789abcdef"
# define ERROR_MALLOC "Error: Memory allocation failed\n"
# define ERROR_OPEN "Error: Cannot open file\n"
# define ERROR_READ "Error: Cannot read file\n"
# define ERROR_CLOSE "Error: Cannot close file\n"
# define ERROR_ARGS "Usage: ./ft_hexdump [-C] [file ...]\n"

typedef	struct	s_hexdump
{
	int		fd;
	int		use_c_option;
	char	*program_name;
	size_t	total_bytes;
}	t_hexdump;

/* hexdump */
int			main(int argc, char **argv);

/* file handling */
int			ft_open_file(const char *filename);
void		ft_close_file(int fd);
ssize_t		ft_read_file(int fd, void *buf, size_t count);

/* arg parsing */
int			ft_parse_arguments(int argc, char **argv, t_hexdump *hexdump);

/* utils */
void		ft_putchar(char c);
void		ft_putstr( const char *str);
size_t		ft_strlen(const char *s);
int			ft_strcmp(const char *s1, const char *s2);
void		*ft_memcpy(void *dst, const void *src, size_t n);

/* error handling */
void		ft_print_error(const char *error_message);
void		ft_print_system_error(void);

/* hexdump core */
void		ft_process_file(t_hexdump *hexdump);
void		ft_format_and_print_chunk(const unsigned char *buf, size_t len, size_t offset, int use_c_option);
void		ft_format_offset(char *dest, size_t offset);
void		ft_format_hex_bytes(char *dest, const unsigned char *buf, size_t len, int use_c_option);
void		ft_format_ascii_representation(char *dest, const unsigned char *buf, size_t len);
void		ft_print_line(const char *offset_str, const char *hex_str, const char *ascii_str, int use_c_option);

#endif
