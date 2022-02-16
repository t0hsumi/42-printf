#include "ft_printf.h"

void	ft_digit_print(t_flag *convert, int output)
{
	my_putchar('0', convert->acc);
	if (convert->specifier == d || convert->specifier == i)
		ft_putnbr_fd(output, 1);
	if (convert->flag[MINUS])
		my_putchar(' ', convert->field);
}

int	my_strchr(const char *s, int c)
{
	int	index;

	index = 0;
	while (s[index])
	{
		if (s[index] == c)
			return (index);
		index++;
	}
	return (-1);
}

int	ft_substr_n(const char *fmt, int *head)
{
	int	res;

	res = 0;
	if (!ft_isdigit(fmt[(*head)]))
		return (-1);
	while (ft_isdigit(fmt[(*head)]))
		res = res * 10 + (fmt[(*head)++] - '0');
	return (res);
}

void	my_putchar(int c, int len)
{
	char	str[2];
	int		i;

	i = 0;
	str[0] = c;
	str[1] = '\0';
	while (i++ < len)
		write(1, str, 1);
}

void	my_putstr(char *str, int len)
{
	write(1, str, len);
}
