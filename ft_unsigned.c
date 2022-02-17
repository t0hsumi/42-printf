#include "ft_printf.h"

int	ft_unsigned_len(unsigned long long num)
{
	int	res;

	res = 0;
	if (num == 0)
		res = 1;
	else
	{
		while (num)
		{
			num /= 10;
			res++;
		}
	}
	return (res);
}

void	ft_unsigned_print(unsigned long long num, t_flag *convert)
{
	if (!convert->flag[ZERO] && !convert->flag[MINUS])
		my_putchar(' ', convert->field);
	else if (convert->flag[ZERO] && !convert->flag[MINUS])
		my_putchar('0', convert->field);
	my_putchar('0', convert->acc);
	ft_putnbr_u_fd(num, 1);
	if (convert->flag[MINUS])
		my_putchar(' ', convert->field);
}

void	ft_unsigned(va_list *ap, t_flag *convert)
{
	unsigned long long	num;

	num = (unsigned int)va_arg(*ap, int);
	convert->putlen = ft_unsigned_len(num);
	if (convert->acc == 0 && num == 0)
	{
		convert->putlen -= 1;
		if (convert->field <= convert->putlen)
			convert->field = 0;
		else
			convert->field -= convert->putlen;
		my_putchar(' ', convert->field);
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
	ft_unsigned_print(num, convert);
}
