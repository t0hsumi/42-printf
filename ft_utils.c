#include "ft_printf.h"

int ft_isdigit(char c)
{
	if ('0' <= c && c <= '9')
		return 1;
	else
		return 0;
}
void   ft_putnbr_fd(int n, int fd)
{
	long   ln;

	ln = n;
	if (ln < 0)
	{
		write(fd, "-", 1);
		ln *= -1;
	}
	if (ln >= 10)
	{
		ft_putnbr_fd(ln / 10, fd);
		ft_putnbr_fd(ln % 10, fd);
	}
	else
		write(fd, &"0123456789"[(int)ln], 1);
}
