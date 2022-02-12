#include "ft_printf.h"

void my_putchar(int c, int len)
{
	char str[len + 1];
	int i;

	i = 0;
	while (i < len)
		str[i++] = c;
	str[i] = '\0';
	write(1, str, len);
}

void ft_percent(t_flag *convert)
{
	convert->putlen = 1;
	convert->field = (convert->field <= 1 ? 0 : convert->field - 1);
	if (!convert->flag[ZERO] && !convert->flag[MINUS])
		my_putchar(' ', convert->field);
	else if (convert->flag[ZERO] && !convert->flag[MINUS])
		my_putchar('0', convert->field);
	write(1, "%", 1);
	if (convert->flag[MINUS])
		my_putchar(' ', convert->field);
}

int ft_non_specifier(const char *fmt, int *tail, int *head, t_flag *convert)
{
	write(1, &fmt[(*tail)], (*head) - (*tail));
	convert->putlen = (*head) - (*tail);
	return (convert->putlen);
}

void ft_int(va_list *ap, t_flag *convert)
{
	long long num;
	int digit_len = 0;
	long long output;

	num = va_arg(*ap, int);
	output = num;
	convert->putlen = (num >= 0 ? 0 : 1);
	if (num >= 0 && (convert->flag[SPACE] || convert->flag[PLUS]))
		convert->putlen += 1;
	if (num == 0) digit_len = 1;
	else{
		while (num){
			num /= 10;
			digit_len++;
		}
	}
	convert->putlen += digit_len;
	convert->acc = (convert->acc <= digit_len ? 0 : convert->acc - digit_len);
	convert->field = (convert->field <= digit_len + convert->acc ? 0 : convert->field - convert->acc - digit_len);
	if (!convert->flag[ZERO] && !convert->flag[MINUS])
		my_putchar(' ', convert->field);
	else if (convert->flag[ZERO] && !convert->flag[MINUS])
		my_putchar('0', convert->field);
	if (output < 0){
		write(1, "-", 1);
		output *= -1;
	}
	my_putchar('0', convert->acc);
	ft_putnbr_fd(output, 1);
	if (convert->flag[MINUS])
		my_putchar(' ', convert->field);
}

void ft_hex(va_list *ap, t_flag *convert)
{
	(void)ap;
	(void)convert;
}

void ft_unsigned(va_list *ap, t_flag *convert)
{
	(void)ap;
	(void)convert;
}

void ft_char(va_list *ap, t_flag *convert)
{
	(void)ap;
	(void)convert;
}

void ft_str(va_list *ap, t_flag *convert)
{
	(void)ap;
	(void)convert;
}

void ft_pointer(va_list *ap, t_flag *convert)
{
	(void)ap;
	(void)convert;
}

int ft_conv_print(const char *fmt, int *tail, int *head, va_list *ap, t_flag *convert)
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
	else ft_percent(convert);
	return (convert->field + convert->putlen);
}
