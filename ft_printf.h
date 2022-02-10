#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>


int ft_printf(const char *fmt, ...);
int ft_print_str(const char *fmt, int *tail, int *head);


#endif
