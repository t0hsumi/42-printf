#include "ft_printf.h"

void	ft_percent(t_flag *convert)
{
	convert->putlen = 1;
	if (convert->field <= 1)
		convert->field = 0;
	else
		convert->field -= 1;
	convert->acc = 0;
	if (!convert->flag[ZERO] && !convert->flag[MINUS])
		my_putchar(' ', convert->field);
	else if (convert->flag[ZERO] && !convert->flag[MINUS])
		my_putchar('0', convert->field);
	write(1, "%", 1);
	if (convert->flag[MINUS])
		my_putchar(' ', convert->field);
}

int	ft_non_specifier(const char *fmt, int *tail, int *head, t_flag *convert)
{
	write(1, &fmt[(*tail)], (*head) - (*tail));
	convert->putlen = (*head) - (*tail);
	return (convert->putlen);
}
