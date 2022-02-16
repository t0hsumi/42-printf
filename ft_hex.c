#include "ft_printf.h"

void	ft_hex(va_list *ap, t_flag *convert)
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
			num /= 16;
			convert->putlen++;
		}
	}
	if (convert->flag[SHARP] && output != 0)
		convert->putlen += 2;
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
	if (convert->flag[SHARP] && output != 0)
		write(1, (convert->specifier == x ? "0x" : "0X"), 2);
	if (convert->flag[ZERO] && !convert->flag[MINUS])
		my_putchar('0', convert->field);
	my_putchar('0', convert->acc);
	ft_putnbr_hex_fd(output, 1, convert);
	if (convert->flag[MINUS])
		my_putchar(' ', convert->field);
}

void	ft_pointer(va_list *ap, t_flag *convert)
{
	unsigned long long	num;
	int					digit_len;
	unsigned long long	output;

	digit_len = 0;
	num = (unsigned long long)va_arg(*ap, unsigned long long);
	output = num;
	if (num == 0)
		digit_len = 1;
	else
	{
		while (num)
		{
			num /= 16;
			digit_len++;
		}
	}
	convert->putlen += digit_len + 2;
	if (convert->acc == 0 && output == 0)
	{
		convert->putlen -= 1;
		convert->field = (convert->field <= convert->putlen ? 0 : convert->field - convert->putlen);
		my_putchar(' ', convert->field);
		return ;
	}
	convert->acc = (convert->acc <= digit_len ? 0 : convert->acc - digit_len);
	convert->field = (convert->field <= (convert->putlen + convert->acc) ? 0 : convert->field - convert->acc - convert->putlen);
	if (!convert->flag[ZERO] && !convert->flag[MINUS])
		my_putchar(' ', convert->field);
	write(1, "0x", 2);
	if (convert->flag[ZERO] && !convert->flag[MINUS])
		my_putchar('0', convert->field);
	my_putchar('0', convert->acc);
	ft_putnbr_hex_fd(output, 1, convert);
	if (convert->flag[MINUS])
		my_putchar(' ', convert->field);
}
