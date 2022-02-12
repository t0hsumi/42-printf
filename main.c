#include <stdio.h>
#include "ft_printf.h"

#ifdef FT_PRINTF
#define F(...) \
res = ft_printf(__VA_ARGS__); \
printf("%d\n", res);
#else
#define F(...) \
res = printf(__VA_ARGS__); \
printf("%d\n", res);
#endif

int main()
{
	int res;
	F("asdf%d\n", 62);
}
