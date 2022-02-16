#include "ft_printf.h"

void	ft_int_conv_set(t_flag *convert, long long num, int *digit_len)
{
	*digit_len = 0;
	if (num >= 0)
		convert->putlen = 0;
	else
		convert->putlen = 1;
	if (num >= 0 && (convert->flag[SPACE] || convert->flag[PLUS]))
		convert->putlen += 1;
	if (num == 0)
		*digit_len = 1;
	else
	{
		while (num)
		{
			num /= 10;
			(*digit_len)++;
		}
	}
	convert->putlen += *digit_len;
}

void	ft_int_conv_set2(t_flag *convert, int digit_len, long long output)
{
	if (convert->acc <= digit_len)
		convert->acc = 0;
	else
		convert->acc = convert->acc - digit_len;
	if (convert->field <= digit_len + convert->acc)
		convert->field = 0;
	else
		convert->field = convert->field - convert->acc - digit_len;
	if (output < 0 && convert->field > 0)
		convert->field -= 1;
}

void	ft_int_print(long long output, long long num, t_flag *convert)
{
	if (!convert->flag[ZERO] && !convert->flag[MINUS])
		my_putchar(' ', convert->field);
	if (output < 0)
	{
		write(1, "-", 1);
		output *= -1;
	}
	if (convert->flag[ZERO] && !convert->flag[MINUS])
		my_putchar('0', convert->field);
	if (convert->flag[PLUS] && num >= 0)
		write(1, "+", 1);
	else if (convert->flag[SPACE] && num >= 0)
		write(1, " ", 1);
	ft_digit_print(convert, output);
}

void	ft_int_error_case(t_flag *convert)
{
	convert->putlen -= 1;
	if (convert->field <= convert->putlen)
		convert->field = 0;
	else
		convert->field = convert->field - convert->putlen;
	if (!convert->flag[MINUS])
		my_putchar(' ', convert->field);
	if (convert->flag[PLUS])
		write(1, "+", 1);
	else if (convert->flag[SPACE])
		write(1, " ", 1);
	if (convert->flag[MINUS])
		my_putchar(' ', convert->field);
}

void	ft_int(va_list *ap, t_flag *convert)
{
	long long	num;
	int			digit_len;
	long long	output;

	num = va_arg(*ap, int);
	output = num;
	ft_int_conv_set(convert, num, &digit_len);
	if (convert->acc == 0 && output == 0)
	{
		ft_int_error_case(convert);
		return ;
	}
	ft_int_conv_set2(convert, digit_len, output);
	ft_int_print(output, num, convert);
}
