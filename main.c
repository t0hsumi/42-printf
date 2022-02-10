#include <stdio.h>
#include "ft_printf.h"

#ifdef FT_PRINTF
#define F(...) \
	ft_printf(__VA_ARGS__);
#else
#define F(...) \
	printf(__VA_ARGS__);
#endif

int main()
{
	F("asdf\n");
}
