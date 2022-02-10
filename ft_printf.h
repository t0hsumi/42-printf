#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>


typedef struct	s_flag
{
	int flag[5]; //# 0 - ' ' +
	int field;
	int acc;
	int specifier;
	int putnum;
	int putlen;
}				t_flag;


int ft_printf(const char *fmt, ...);
int ft_print_str(const char *fmt, int *tail, int *head);
int ft_proc_per(const char *fmt, int *tail, int *head,va_list *ap);
int ft_substr_n(const char *fmt, int *head);
int my_strchr(const char *s, int c);
void ft_init_conv(t_flag *convert);
int ft_conv_print(const char *fmt, int *tail, int *head, va_list *ap, t_flag *convert);

enum
{
	c,
	s,
	p,
	d,
	i,
	u,
	x,
	X,
	precent,
};


#endif
