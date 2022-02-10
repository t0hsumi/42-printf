#include <stdio.h>
#include "ft_printf.h"

int main()
{
	printf("%d\n\n", ft_printf("asdfasd%fasdf\n", 0.05));

	printf("%d\n", printf("asdfasd%fasdf\n", 0.05));
}
