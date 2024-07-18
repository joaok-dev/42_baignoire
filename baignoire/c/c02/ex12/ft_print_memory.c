#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

int		ft_char_is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

void	ft_print_hex(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	ft_putchar(hex[c >> 4]);
	ft_putchar(hex[c & 0xF]);
}

void	ft_print_address(void *addr)
{
	unsigned long	value;
	char			*hex;
	char			buffer[17];
	char			*ptr;

	value = (unsigned long)addr;
	hex = "0123456789abcdef";
	ptr = buffer + 16;
	*ptr = '\0';
	while (ptr > buffer)
	{
		*--ptr = hex[value & 0xF];
		value >>= 4;
	}
	ft_putstr(buffer);
}

void	ft_print_memory_line(void *addr, unsigned int size)
{
	unsigned char	*ptr;
	unsigned char	*end;
	unsigned char	*char_ptr;

	ptr = addr;
	if (size < 16)
		end = ptr + size;
	else
		end = ptr + 16;
	ft_print_address(addr);
	ft_putstr(": ");
	while (ptr < end)
	{
		ft_print_hex(*ptr++);
		if ((ptr - (unsigned char *)addr) & 1)
			ft_putchar(' ');
	}
	while (ptr++ < (unsigned char *)addr + 16)
	{
		ft_putstr("  ");
		if ((ptr - (unsigned char *)addr) & 1)
			ft_putchar(' ');
	}
	char_ptr = addr;
	while (char_ptr < end)
	{
		if (ft_char_is_printable(*char_ptr))
			ft_putchar(*char_ptr);
		else
			ft_putchar('.');
		char_ptr++;
	}
	ft_putchar('\n');
}

void	ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*ptr;
	unsigned char	*end;

	if (!size)
		return ;
	ptr = addr;
	end = ptr + size;
	while (ptr < end)
	{
		ft_print_memory_line(ptr, end - ptr);
		ptr += 10;
	}
}

int	main(void)
{
	char	data[] = "Hello, World! This is a test of the memory display function.";

	ft_print_memory(data, sizeof(data));
	return (0);
}
