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

void c_test(){
	int res;
	F("%c\n", 'a');
	F("%10c\n", 'a');
	F("%-10c\n", 'a');
	F("%010c\n", 'a');
}

void percent_test(){
	int res;
	F("%%\n");
	F("%10%\n");
	F("%010%\n");
	F("%-10%\n");
	F("%010.5%\n");
	F("%-10.5%\n");
	F("%10.5%\n");
	F("%010.15%\n");
	F("%-10.15%\n");
	F("%10.15%\n");
}

void s_test(){
	int res;
	F("%s\n", "asdfghjkl");
	F("%3s\n", "asdfghjkl");
	F("%-3s\n", "asdfghjkl");
	F("%03s\n", "asdfghjkl");
	F("%15s\n", "asdfghjkl");
	F("%-15s\n", "asdfghjkl");
	F("%015s\n", "asdfghjkl");
	F("%s.\n", "asdfghjkl");
	F("%3.s\n", "asdfghjkl");
	F("%-3.s\n", "asdfghjkl");
	F("%03.s\n", "asdfghjkl");
	F("%15.s\n", "asdfghjkl");
	F("%-15.s\n", "asdfghjkl");
	F("%015.s\n", "asdfghjkl");
	F("%.2s\n", "asdfghjkl");
	F("%3.2s\n", "asdfghjkl");
	F("%-3.2s\n", "asdfghjkl");
	F("%03.2s\n", "asdfghjkl");
	F("%15.2s\n", "asdfghjkl");
	F("%-15.2s\n", "asdfghjkl");
	F("%015.2s\n", "asdfghjkl");
	F("%s.5\n", "asdfghjkl");
	F("%3.5s\n", "asdfghjkl");
	F("%-3.5s\n", "asdfghjkl");
	F("%03.5s\n", "asdfghjkl");
	F("%15.5s\n", "asdfghjkl");
	F("%-15.5s\n", "asdfghjkl");
	F("%015.5s\n", "asdfghjkl");
	F("%.20s\n", "asdfghjkl");
	F("%3.20s\n", "asdfghjkl");
	F("%-3.20s\n", "asdfghjkl");
	F("%03.20s\n", "asdfghjkl");
	F("%15.20s\n", "asdfghjkl");
	F("%-15.20s\n", "asdfghjkl");
	F("%015.20s\n", "asdfghjkl");
	char *str = NULL;
	F("%s\n",str);
	F("%3s\n",str);
	F("%-3s\n",str);
	F("%03s\n",str);
	F("%15s\n",str);
	F("%-15s\n",str);
	F("%015s\n",str);
	F("%s.\n",str);
	F("%3.s\n",str);
	F("%-3.s\n",str);
	F("%03.s\n",str);
	F("%15.s\n",str);
	F("%-15.s\n",str);
	F("%015.s\n",str);
	F("%s.2\n",str);
	F("%3.2s\n",str);
	F("%-3.2s\n",str);
	F("%03.2s\n",str);
	F("%15.2s\n",str);
	F("%-15.2s\n",str);
	F("%015.2s\n",str);
	F("%s.5\n",str);
	F("%3.5s\n",str);
	F("%-3.5s\n",str);
	F("%03.5s\n",str);
	F("%15.5s\n",str);
	F("%-15.5s\n",str);
	F("%015.5s\n",str);
	F("%.20s\n",str);
	F("%3.20s\n",str);
	F("%-3.20s\n",str);
	F("%03.20s\n",str);
	F("%15.20s\n",str);
	F("%-15.20s\n",str);
	F("%015.20s\n",str);
	F("%0.0s\n", "asdfghjkl");
	F("%0.0s\n", str);
	F("%.s\n", str);
	F("%.s\n", "asdfghjkl");
	F("%0.s\n", str);
	F("%00.s\n", "asdfghjkl");
}

int main()
{
	int res;
	/* c_test(); */
	/* percent_test(); */
	/* s_test(); */
	F("%.d\n", 0);
}
