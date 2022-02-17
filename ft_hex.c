#include "ft_printf.h"

void	ft_hex_print(unsigned long long num, t_flag *convert)
{
	if (!convert->flag[ZERO] && !convert->flag[MINUS])
		my_putchar(' ', convert->field);
	if (convert->flag[SHARP] && num && convert->specifier == x)
		write(1, "0x", 2);
	else if (convert->flag[SHARP] && num && convert->specifier == X)
		write(1, "0X", 2);
	else if (convert->specifier == p)
		write(1, "0x", 2);
	if (convert->flag[ZERO] && !convert->flag[MINUS])
		my_putchar('0', convert->field);
	my_putchar('0', convert->acc);
	ft_putnbr_hex_fd(num, 1, convert);
	if (convert->flag[MINUS])
		my_putchar(' ', convert->field);
}

void	ft_hex_err_print(t_flag *convert)
{
	convert->putlen -= 1;
	if (convert->field <= convert->putlen)
		convert->field = 0;
	else
		convert->field -= convert->putlen;
	my_putchar(' ', convert->field);
}

int	ft_hex_len(unsigned long long num)
{
	int	res;

	res = 0;
	if (num == 0)
		res = 1;
	else
	{
		while (num)
		{
			num /= 16;
			res++;
		}
	}
	return (res);
}

void	ft_hex(va_list *ap, t_flag *convert)
{
	unsigned long long	num;

	num = (unsigned int)va_arg(*ap, int);
	convert->putlen = ft_hex_len(num);
	if (convert->flag[SHARP] && num != 0)
		convert->putlen += 2;
	if (convert->acc == 0 && num == 0)
	{
		ft_hex_err_print(convert);
		return ;
	}
	if (convert->acc <= convert->putlen)
		convert->acc = 0;
	else
		convert->acc -= convert->putlen;
	if (convert->field <= (convert->putlen + convert->acc))
		convert->field = 0;
	else
		convert->field -= convert->acc + convert->putlen;
	ft_hex_print(num, convert);
}

void	ft_pointer(va_list *ap, t_flag *convert)
{
	unsigned long long	num;
	int					digit_len;

	digit_len = 0;
	num = (unsigned long long)va_arg(*ap, unsigned long long);
	digit_len = ft_hex_len(num);
	convert->putlen += digit_len + 2;
	if (convert->acc == 0 && num == 0)
	{
		ft_hex_err_print(convert);
		return ;
	}
	if (convert->acc <= digit_len)
		convert->acc = 0;
	else
		convert->acc -= digit_len;
	if (convert->field <= (convert->putlen + convert->acc))
		convert->field = 0;
	else
		convert->field -= convert->acc + convert->putlen;
	ft_hex_print(num, convert);
}
