#include "ft_printf.h"

void my_putchar(int c, int len)
{
	char str[len+1];
	int i = 0;
	while (i < len)
		str[i++] = c;
	write(1, str, len);
	/* char str[1 + (1<<16)]; */
	/* int i; */

	/* i = 0; */
	/* while (i < len && i <= 1<<16) */
	/* 	str[i++] = c; */
	/* str[i] = '\0'; */
	/* if (len < 1<<16) */
	/* 	write(1, str, len); */
	/* else */
	/* { */
	/* 	while (len > 1<<16) */
	/* 	{ */
	/* 		write(1, str, 1<<16); */
	/* 		len -= 1<<16; */
	/* 	} */
	/* 	write(1, str, len); */
	/* } */
}

void my_putstr(char *str, int len)
{
	write(1, str, len);
}

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
	if (ln == INT_MIN)
	{
		write(1, "2147483648", 10);
		return;
	}
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

void   ft_putnbr_u_fd(unsigned long long n, int fd)
{
	if (n >= 10)
	{
		ft_putnbr_u_fd(n / 10, fd);
		ft_putnbr_u_fd(n % 10, fd);
	}
	else
		write(fd, &"0123456789"[(int)n], 1);
}

void   ft_putnbr_hex_fd(unsigned long long n, int fd, t_flag *convert)
{
	if (n >= 16)
	{
		ft_putnbr_hex_fd(n / 16, fd, convert);
		ft_putnbr_hex_fd(n % 16, fd, convert);
	}
	else if (convert->specifier == x || convert->specifier == p)
		write(fd, &"0123456789abcdef"[(int)n], 1);
	else
		write(fd, &"0123456789ABCDEF"[(int)n], 1);
}

size_t ft_strlen(const char *str)
{
	size_t res;

	res = 0;
	while (str[res])
		res++;
	return res;
}

