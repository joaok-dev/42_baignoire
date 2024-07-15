#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int	ft_char_is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

void	ft_print_hex(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	ft_putchar(hex[c / 16]);
	ft_putchar(hex[c % 16]);
}

void	ft_print_address(unsigned long addr)
{
	char	addr_str[17];
	int		i;

	i = 0;
	while (i < 16)
	{
		addr_str[i] = '0';
		i++;
	}
	addr_str[16] = '\0';
	i = 15;
	while (i >= 0)
	{
		addr_str[i] = "0123456789abcdef"[addr % 16];
		addr = addr / 16;
		i--;
	}
	ft_putstr(addr_str);
}

void	ft_print_memory_line(void *addr, unsigned int size)
{
	unsigned char	*ptr;
	unsigned int	i;

	ptr = (unsigned char *)addr;
	ft_print_address((unsigned long)ptr);
	ft_putstr(": ");
	i = 0;
	while (i < 16)
	{
		if (i < size)
			ft_print_hex(ptr[i]);
		else
			ft_putstr("  ");
		if (i % 2)
			ft_putchar(' ');
		i++;
	}
	i = 0;
	while (i < size && i < 16)
	{
		if (ft_char_is_printable(ptr[i]))
			ft_putchar(ptr[i]);
		else
			ft_putchar('.');
		i++;
	}
	ft_putchar('\n');
}

void	ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	block_size;

	if (size == 0)
		return ;
	i = 0;
	while (i < size)
	{
		if (size - i >= 16)
			block_size = 16;
		else
			block_size = size - i;
		ft_print_memory_line(addr + i, block_size);
		i += 16;
	}
}

int	main(void)
{
	char	data[] = "Hello, World! This is a test of the memory display function.";

	ft_print_memory(data, sizeof(data));
	return (0);
}
