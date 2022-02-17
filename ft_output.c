#include "ft_printf.h"

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
