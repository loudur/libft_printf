#include "ft_printf_internal.h"

int	ft_printf_putchar(int fd, t_printf_conversion conv, char val)
{
	int	size;
	int	i;

	size = 1;
	if (conv.width > 0)
		size = conv.width;
	i = 0;
	while (++i < size && !(conv.flags & F_Left_Adjusted))
		write(fd, " ", 1);
	write(fd, &val, 1);
	while (++i - 1 < size && conv.flags & F_Left_Adjusted)
		write(fd, " ", 1);
	return (size);
}
