#include "./ft_printf.h"

void	ft_init_conv(t_flag *convert)
{
	convert->flag[0] = 0;
	convert->flag[1] = 0;
	convert->flag[2] = 0;
	convert->flag[3] = 0;
	convert->flag[4] = 0;
	convert->field = -1;
	convert->acc = -1;
	convert->specifier = -1;
	convert->putnum = 0;
	convert->putlen = 0;
}

int	ft_proc_per(const char *fmt, int *tail, int *head, va_list *ap)
{
	t_flag	convert;
	int		num;

	ft_init_conv(&convert);
	num = my_strchr("#0- +", fmt[(*head)]);
	while (num >= 0)
	{
		(*head)++;
		convert.flag[num] = 1;
		num = my_strchr("#0- +", fmt[(*head)]);
	}
	convert.field = ft_substr_n(fmt, head);
	if (convert.field == INT_MAX)
		return (INT_MIN);
	if (fmt[(*head)] == '.')
	{
		(*head)++;
		convert.acc = ft_substr_n(fmt, head);
		if (convert.acc == -1)
			convert.acc = 0;
	}
	convert.specifier = my_strchr("cspdiuxX%", fmt[(*head)]);
	if (convert.specifier == -1)
		return (ft_non_specifier(fmt, tail, head, &convert));
	return (ft_conv_print(head, ap, &convert));
}

int	ft_print_str(const char *fmt, int *tail, int *head)
{
	while (fmt[(*head)] != '%' && fmt[(*head)])
		(*head)++;
	write(1, &fmt[(*tail)], (*head) - (*tail));
	return ((*head) - (*tail));
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		res;
	int		head;
	int		tail;

	res = 0;
	head = 0;
	va_start(ap, fmt);
	if (fmt == NULL)
		res = -1;
	while (res >= 0 && fmt[head])
	{
		tail = head;
		if (fmt[head] != '%')
			res += ft_print_str(fmt, &tail, &head);
		else
		{
			head++;
			res += ft_proc_per(fmt, &tail, &head, &ap);
		}
	}
	va_end(ap);
	if (res < -1)
		res = -1;
	return (res);
}
