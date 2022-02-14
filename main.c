#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

#ifdef FT_PRINTF
#define F(...) \
res = ft_printf(__VA_ARGS__); \
ft_putnbr_fd(res, 1); \
write(1, "\n", 1);
#else
#define F(...) \
res = printf(__VA_ARGS__); \
printf("%d\n", res);
#endif

int main()
{
	int res;
	F("[%7d]\n", -11);
}
