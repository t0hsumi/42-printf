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
	/* F("[%c]\n", 'c'); */
	/* F("[%c]\n", '\0'); */
	/* F("[%5c]\n", 'c'); */
	/* F("[%5c]\n", '\0'); */
	/* F("[%-5c]\n", 'c'); */
	/* F("[%-5c]\n", '\0'); */
	/* F("[%2147483645c]\n", 'p'); */
	F("[%2147483646c]\n", 'p');
	F("[%2147483647c]\n", 'p');
	F("[%2147483648c]\n", 'p');
}
