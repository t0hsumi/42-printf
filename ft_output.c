#include "ft_printf.h"

void	ft_unsigned(va_list *ap, t_flag *convert)
{
	unsigned long long	num;
	unsigned long long	output;

	num = (unsigned int)va_arg(*ap, int);
	output = num;
	if (num == 0)
		convert->putlen = 1;
	else
	{
		while (num)
		{
			num /= 10;
			convert->putlen++;
		}
	}
	if (convert->acc == 0 && output == 0)
	{
		convert->putlen -= 1;
		convert->field = (convert->field <= convert->putlen ? 0 : convert->field - convert->putlen);
		my_putchar(' ', convert->field);
		return ;
	}
	convert->acc = (convert->acc <= convert->putlen ? 0 : convert->acc - convert->putlen);
	convert->field = (convert->field <= convert->putlen + convert->acc ? 0 : convert->field - convert->acc - convert->putlen);
	if (!convert->flag[ZERO] && !convert->flag[MINUS])
		my_putchar(' ', convert->field);
	else if (convert->flag[ZERO] && !convert->flag[MINUS])
		my_putchar('0', convert->field);
	my_putchar('0', convert->acc);
	ft_putnbr_u_fd(output, 1);
	if (convert->flag[MINUS])
		my_putchar(' ', convert->field);
}

int	ft_conv_print(const char *fmt, int *tail, int *head, va_list *ap, t_flag *convert)
{
	if (convert->specifier == -1)
		return (ft_non_specifier(fmt, tail, head, convert));
	(*head)++;
	if (convert->specifier == d || convert->specifier == i)
		ft_int(ap, convert);
	else if (convert->specifier == x || convert->specifier == X)
		ft_hex(ap, convert);
	else if (convert->specifier == u)
		ft_unsigned(ap, convert);
	else if (convert->specifier == c)
		ft_char(ap, convert);
	else if (convert->specifier == s)
		ft_str(ap, convert);
	else if (convert->specifier == p)
		ft_pointer(ap, convert);
	else
		ft_percent(convert);
	return (convert->field + convert->putlen + convert->acc);
}
