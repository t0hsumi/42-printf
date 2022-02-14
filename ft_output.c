#include "ft_printf.h"

void ft_percent(t_flag *convert)
{
	convert->putlen = 1;
	convert->field = (convert->field <= 1 ? 0 : convert->field - 1);
	convert->acc = 0;
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
	long long tmp;

	num = va_arg(*ap, int);
	output = num;
	tmp = output;
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
	if (convert->acc == 0 && output == 0)
	{
		convert->putlen -= 1;
		convert->field = (convert->field <= convert->putlen ? 0 : convert->field - convert->putlen);
		if (!convert->flag[MINUS])
			my_putchar(' ', convert->field);
		if (convert->flag[PLUS])
			write(1, "+", 1);
		else if (convert->flag[SPACE])
			write(1, " ", 1);
		if (convert->flag[MINUS])
			my_putchar(' ', convert->field);
		return;
	}
	convert->acc = (convert->acc <= digit_len ? 0 : convert->acc - digit_len);
	convert->field = (convert->field <= digit_len + convert->acc ? 0 : convert->field - convert->acc - digit_len);
	if (output < 0 && convert->field > 0)
		convert->field -= 1;
	if (!convert->flag[ZERO] && !convert->flag[MINUS])
		my_putchar(' ', convert->field);
	else if (convert->flag[ZERO] && !convert->flag[MINUS])
		my_putchar('0', convert->field);
	if (output < 0){
		write(1, "-", 1);
		output *= -1;
	}
	if (convert->flag[PLUS] && tmp >= 0)
		write(1, "+", 1);
	else if (convert->flag[SPACE] && tmp >= 0)
		write(1, " ", 1);
	my_putchar('0', convert->acc);
	ft_putnbr_fd(output, 1);
	if (convert->flag[MINUS])
		my_putchar(' ', convert->field);
}

void ft_hex(va_list *ap, t_flag *convert)
{
	unsigned long long num;
	unsigned long long output;

	num = (unsigned int)va_arg(*ap, int);
	output = num;
	if (num == 0) convert->putlen = 1;
	else{
		while (num){
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
		return;
	}
	convert->acc = (convert->acc <=  convert->putlen ? 0 : convert->acc - convert->putlen);
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

void ft_unsigned(va_list *ap, t_flag *convert)
{
	unsigned long long num;
	unsigned long long output;

	num = (unsigned int)va_arg(*ap, int);
	output = num;
	if (num == 0) convert->putlen = 1;
	else{
		while (num){
			num /= 10;
			convert->putlen++; 
		}
	}
	if (convert->acc == 0 && output == 0)
	{
		convert->putlen -= 1;
		convert->field = (convert->field <= convert->putlen ? 0 : convert->field - convert->putlen);
		my_putchar(' ', convert->field);
		return;
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

void ft_char(va_list *ap, t_flag *convert)
{
	unsigned char c;

	c = (unsigned char)va_arg(*ap, int);
	convert->putlen = 1;
	convert->acc = 0;
	convert->field = (convert->field > convert->putlen ? convert->field - convert->putlen : 0);
	if (!convert->flag[ZERO] && !convert->flag[MINUS])
		my_putchar(' ', convert->field);
	else if (convert->flag[ZERO] && !convert->flag[MINUS])
		my_putchar('0', convert->field);
	my_putchar(c, 1);
	if (convert->flag[MINUS])
		my_putchar(' ', convert->field);
}

void ft_str(va_list *ap, t_flag *convert)
{
	char *str;

	str = (char *)va_arg(*ap, char *);
	if (!str)
		str = "(null)";
	convert->putlen = ft_strlen(str);
	if (convert->acc == -1 || convert->acc >= convert->putlen)
	{
		convert->field = (convert->field > convert->putlen ? convert->field - convert->putlen : 0);
		convert->acc = 0;
		if (!convert->flag[MINUS] && !convert->flag[ZERO])
			my_putchar(' ', convert->field);
		else if (!convert->flag[MINUS] && convert->flag[ZERO])
			my_putchar('0', convert->field);
		my_putstr(str, convert->putlen);
		if (convert->flag[MINUS])
			my_putchar(' ', convert->field);
	}
	else
	{
		convert->putlen = convert->acc;
		convert->field = (convert->field > convert->putlen ? convert->field - convert->putlen : 0);
		convert->acc = 0;
		if (!convert->flag[MINUS] && !convert->flag[ZERO])
			my_putchar(' ', convert->field);
		else if (!convert->flag[MINUS] && convert->flag[ZERO])
			my_putchar('0', convert->field);
		my_putstr(str, convert->putlen);
		if (convert->flag[MINUS])
			my_putchar(' ', convert->field);
	}
}

void ft_pointer(va_list *ap, t_flag *convert)
{
	unsigned long long num;
	int digit_len = 0;
	unsigned long long output;

	num = (unsigned long long)va_arg(*ap, unsigned long long);
	output = num;
	if (num == 0) digit_len = 1;
	else{
		while (num){
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
		return;
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
	return (convert->field + convert->putlen + convert->acc);
}
