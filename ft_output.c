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
	(void)fmt;
	(void)tail;
	(void)head;
	(void)convert;
	return 0;
}

void ft_int(va_list *ap, t_flag *convert)
{
	(void)ap;
	(void)convert;
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
