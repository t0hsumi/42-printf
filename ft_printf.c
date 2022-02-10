#include "ft_printf.h"

int ft_print_str(const char *fmt, int *tail, int *head)
{
	while (fmt[(*head)] != '%' && fmt[(*head)])
		(*head)++;
	write(1, &fmt[(*tail)], (*head) - (*tail));
	return ((*head) - (*tail));
}

int ft_printf(const char *fmt, ...)
{
	va_list ap;
	int res;
	int head;
	int tail;

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
			return 0;
			/* res += ft_proc_per(fmt, &tail, &head, &ap); */
	}
	va_end(ap);
	return (res);
}

