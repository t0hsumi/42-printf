#include "ft_printf.h"

void	ft_char(va_list *ap, t_flag *convert)
{
	unsigned char	c;

	c = (unsigned char)va_arg(*ap, int);
	convert->putlen = 1;
	convert->acc = 0;
	if (convert->field > convert->putlen)
		convert->field -= convert->putlen;
	else
		convert->field = 0;
	if (!convert->flag[ZERO] && !convert->flag[MINUS])
		my_putchar(' ', convert->field);
	else if (convert->flag[ZERO] && !convert->flag[MINUS])
		my_putchar('0', convert->field);
	my_putchar(c, 1);
	if (convert->flag[MINUS])
		my_putchar(' ', convert->field);
}

void	ft_no_acc_str(char *str, t_flag *convert)
{
	if (convert->field > convert->putlen)
		convert->field -= convert->putlen;
	else
		convert->field = 0;
	convert->acc = 0;
	if (!convert->flag[MINUS] && !convert->flag[ZERO])
		my_putchar(' ', convert->field);
	else if (!convert->flag[MINUS] && convert->flag[ZERO])
		my_putchar('0', convert->field);
	my_putstr(str, convert->putlen);
	if (convert->flag[MINUS])
		my_putchar(' ', convert->field);
}

void	ft_str(va_list *ap, t_flag *convert)
{
	char	*str;

	str = (char *)va_arg(*ap, char *);
	if (!str)
		str = "(null)";
	convert->putlen = ft_strlen(str);
	if (convert->acc == -1 || convert->acc >= convert->putlen)
		ft_no_acc_str(str, convert);
	else
	{
		convert->putlen = convert->acc;
		if (convert->field > convert->putlen)
			convert->field -= convert->putlen;
		else
			convert->field = 0;
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
