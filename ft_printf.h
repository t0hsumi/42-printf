#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# include <stdio.h>

typedef struct	s_flag
{
	int flag[5]; //# 0 - ' ' +
	long long field;
	long long acc;
	int specifier;
	int putlen;
}				t_flag;

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

enum
{
	SHARP,
	ZERO,
	MINUS,
	SPACE,
	PLUS,
};

void   ft_putnbr_fd(int n, int fd);
void   ft_putnbr_u_fd(unsigned long long n, int fd);
void   ft_putnbr_hex_fd(unsigned long long n, int fd, t_flag *convert);
int ft_printf(const char *fmt, ...);
int ft_print_str(const char *fmt, int *tail, int *head);
int ft_proc_per(const char *fmt, int *tail, int *head,va_list *ap);
long long ft_substr_n(const char *fmt, int *head);
int my_strchr(const char *s, int c);
void ft_init_conv(t_flag *convert);
int ft_conv_print(const char *fmt, int *tail, int *head, va_list *ap, t_flag *convert);
int ft_non_specifier(const char *fmt, int *tail, int *head, t_flag *convert);
void ft_int(va_list *ap, t_flag *convert);
void ft_hex(va_list *ap, t_flag *convert);
void ft_unsigned(va_list *ap, t_flag *convert);
void ft_char(va_list *ap, t_flag *convert);
void ft_str(va_list *ap, t_flag *convert);
void ft_pointer(va_list *ap, t_flag *convert);
void ft_percent(t_flag *convert);
int ft_isdigit(char c);
size_t ft_strlen(const char *str);
void my_putstr(char *str, int len);
void my_putchar(int c, int len);


#endif
