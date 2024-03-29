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
	F("%15s\n", "asdfghjkl");
	F("%-15s\n", "asdfghjkl");
	F("%s.\n", "asdfghjkl");
	F("%3.s\n", "asdfghjkl");
	F("%-3.s\n", "asdfghjkl");
	F("%15.s\n", "asdfghjkl");
	F("%-15.s\n", "asdfghjkl");
	F("%3.2s\n", "asdfghjkl");
	F("%-3.2s\n", "asdfghjkl");
	F("%15.2s\n", "asdfghjkl");
	F("%-15.2s\n", "asdfghjkl");
	F("%s.5\n", "asdfghjkl");
	F("%3.5s\n", "asdfghjkl");
	F("%-3.5s\n", "asdfghjkl");
	F("%15.5s\n", "asdfghjkl");
	F("%-15.5s\n", "asdfghjkl");
	F("%.20s\n", "asdfghjkl");
	F("%3.20s\n", "asdfghjkl");
	F("%-3.20s\n", "asdfghjkl");
	F("%15.20s\n", "asdfghjkl");
	F("%-15.20s\n", "asdfghjkl");
	char *str = NULL;
	F("%s\n",str);
	F("%3s\n",str);
	F("%-3s\n",str);
	F("%15s\n",str);
	F("%-15s\n",str);
	F("%s.\n",str);
	F("%3.s\n",str);
	F("%-3.s\n",str);
	F("%15.s\n",str);
	F("%-15.s\n",str);
	F("%s.2\n",str);
	F("%3.2s\n",str);
	F("%-3.2s\n",str);
	F("%15.2s\n",str);
	F("%-15.2s\n",str);
	F("%s.5\n",str);
	F("%3.5s\n",str);
	F("%-3.5s\n",str);
	F("%15.5s\n",str);
	F("%-15.5s\n",str);
	F("%.20s\n",str);
	F("%3.20s\n",str);
	F("%-3.20s\n",str);
	F("%15.20s\n",str);
	F("%-15.20s\n",str);
	F("%.s\n", str);
	F("%.s\n", "asdfghjkl");
}

void d_test(){
	int res;
	F("%d\n", -1);
	F("%d\n", 0);
	F("%d\n", 1);
	F("%d\n", 13);
	F("%d\n", -16);
	F("%d\n", INT_MAX - 1);
	F("%d\n", INT_MAX);
	F("%d\n", INT_MAX + 1);
	F("%d\n", INT_MIN - 1);
	F("%d\n", INT_MIN);
	F("%d\n", INT_MIN + 1);

	F("% 10d\n", -1);
	F("%10d\n", 0);
	F("%10d\n", 1);
	F("%10d\n", 13);
	F("%10d\n", -16);
	F("%10d\n", INT_MAX - 1);
	F("%10d\n", INT_MAX);
	F("%10d\n", INT_MAX + 1);
	F("%10d\n", INT_MIN - 1);
	F("%10d\n", INT_MIN);
	F("%10d\n", INT_MIN + 1);

	F("%.10d\n", -1);
	F("%.10d\n", 0);
	F("%.10d\n", 1);
	F("%.10d\n", 13);
	F("%.10d\n", -16);
	F("%.10d\n", INT_MAX - 1);
	F("%.10d\n", INT_MAX);
	F("%.10d\n", INT_MAX + 1);
	F("%.10d\n", INT_MIN - 1);
	F("%.10d\n", INT_MIN);
	F("%.10d\n", INT_MIN + 1);

	F("%0.0d\n", -1);
	F("%0.0d\n", 0);
	F("%0.0d\n", 1);
	F("%0.0d\n", 13);
	F("%0.0d\n", -16);
	F("%0.0d\n", INT_MAX - 1);
	F("%0.0d\n", INT_MAX);
	F("%0.0d\n", INT_MAX + 1);
	F("%0.0d\n", INT_MIN - 1);
	F("%0.0d\n", INT_MIN);
	F("%0.0d\n", INT_MIN + 1);

	F("%.d\n", -1);
	F("%.d\n", 0);
	F("%.d\n", 1);
	F("%.d\n", 13);
	F("%.d\n", -16);
	F("%.d\n", INT_MAX - 1);
	F("%.d\n", INT_MAX);
	F("%.d\n", INT_MAX + 1);
	F("%.d\n", INT_MIN - 1);
	F("%.d\n", INT_MIN);
	F("%.d\n", INT_MIN + 1);

	F("% d\n", -1);
	F("% d\n", 0);
	F("% d\n", 1);
	F("% d\n", 13);
	F("% d\n", -16);
	F("% d\n", INT_MAX - 1);
	F("% d\n", INT_MAX);
	F("% d\n", INT_MAX + 1);
	F("% d\n", INT_MIN - 1);
	F("% d\n", INT_MIN);
	F("% d\n", INT_MIN + 1);

	F("%+d\n", -1);
	F("%+d\n", 0);
	F("%+d\n", 1);
	F("%+d\n", 13);
	F("%+d\n", -16);
	F("%+d\n", INT_MAX - 1);
	F("%+d\n", INT_MAX);
	F("%+d\n", INT_MAX + 1);
	F("%+d\n", INT_MIN - 1);
	F("%+d\n", INT_MIN);
	F("%+d\n", INT_MIN + 1);

	F("%0d\n", -1);
	F("%0d\n", 0);
	F("%0d\n", 1);
	F("%0d\n", 13);
	F("%0d\n", -16);
	F("%0d\n", INT_MAX - 1);
	F("%0d\n", INT_MAX);
	F("%0d\n", INT_MAX + 1);
	F("%0d\n", INT_MIN - 1);
	F("%0d\n", INT_MIN);
	F("%0d\n", INT_MIN + 1);

	F("%0 10d\n", -1);
	F("%010d\n", 0);
	F("%010d\n", 1);
	F("%010d\n", 13);
	F("%010d\n", -16);
	F("%010d\n", INT_MAX - 1);
	F("%010d\n", INT_MAX);
	F("%010d\n", INT_MAX + 1);
	F("%010d\n", INT_MIN - 1);
	F("%010d\n", INT_MIN);
	F("%010d\n", INT_MIN + 1);

	F("%0.10d\n", -1);
	F("%0.10d\n", 0);
	F("%0.10d\n", 1);
	F("%0.10d\n", 13);
	F("%0.10d\n", -16);
	F("%0.10d\n", INT_MAX - 1);
	F("%0.10d\n", INT_MAX);
	F("%0.10d\n", INT_MAX + 1);
	F("%0.10d\n", INT_MIN - 1);
	F("%0.10d\n", INT_MIN);
	F("%0.10d\n", INT_MIN + 1);

	F("%00.0d\n", -1);
	F("%00.0d\n", 0);
	F("%00.0d\n", 1);
	F("%00.0d\n", 13);
	F("%00.0d\n", -16);
	F("%00.0d\n", INT_MAX - 1);
	F("%00.0d\n", INT_MAX);
	F("%00.0d\n", INT_MAX + 1);
	F("%00.0d\n", INT_MIN - 1);
	F("%00.0d\n", INT_MIN);
	F("%00.0d\n", INT_MIN + 1);

	F("%0.d\n", -1);
	F("%0.d\n", 0);
	F("%0.d\n", 1);
	F("%0.d\n", 13);
	F("%0.d\n", -16);
	F("%0.d\n", INT_MAX - 1);
	F("%0.d\n", INT_MAX);
	F("%0.d\n", INT_MAX + 1);
	F("%0.d\n", INT_MIN - 1);
	F("%0.d\n", INT_MIN);
	F("%0.d\n", INT_MIN + 1);

	F("%0 d\n", -1);
	F("%0 d\n", 0);
	F("%0 d\n", 1);
	F("%0 d\n", 13);
	F("%0 d\n", -16);
	F("%0 d\n", INT_MAX - 1);
	F("%0 d\n", INT_MAX);
	F("%0 d\n", INT_MAX + 1);
	F("%0 d\n", INT_MIN - 1);
	F("%0 d\n", INT_MIN);
	F("%0 d\n", INT_MIN + 1);

	F("%0+d\n", -1);
	F("%0+d\n", 0);
	F("%0+d\n", 1);
	F("%0+d\n", 13);
	F("%0+d\n", -16);
	F("%0+d\n", INT_MAX - 1);
	F("%0+d\n", INT_MAX);
	F("%0+d\n", INT_MAX + 1);
	F("%0+d\n", INT_MIN - 1);
	F("%0+d\n", INT_MIN);
	F("%0+d\n", INT_MIN + 1);

	F("%-d\n", -1);
	F("%-d\n", 0);
	F("%-d\n", 1);
	F("%-d\n", 13);
	F("%-d\n", -16);
	F("%-d\n", INT_MAX - 1);
	F("%-d\n", INT_MAX);
	F("%-d\n", INT_MAX + 1);
	F("%-d\n", INT_MIN - 1);
	F("%-d\n", INT_MIN);
	F("%-d\n", INT_MIN + 1);

	F("%- 10d\n", -1);
	F("%-10d\n", 0);
	F("%-10d\n", 1);
	F("%-10d\n", 13);
	F("%-10d\n", -16);
	F("%-10d\n", INT_MAX - 1);
	F("%-10d\n", INT_MAX);
	F("%-10d\n", INT_MAX + 1);
	F("%-10d\n", INT_MIN - 1);
	F("%-10d\n", INT_MIN);
	F("%-10d\n", INT_MIN + 1);

	F("%-.10d\n", -1);
	F("%-.10d\n", 0);
	F("%-.10d\n", 1);
	F("%-.10d\n", 13);
	F("%-.10d\n", -16);
	F("%-.10d\n", INT_MAX - 1);
	F("%-.10d\n", INT_MAX);
	F("%-.10d\n", INT_MAX + 1);
	F("%-.10d\n", INT_MIN - 1);
	F("%-.10d\n", INT_MIN);
	F("%-.10d\n", INT_MIN + 1);
}

void x_test(){
	int res;
	F("%x\n", -1);
	F("%x\n", 0);
	F("%x\n", 1);
	F("%x\n", 13);
	F("%x\n", -16);
	F("%x\n", INT_MAX - 1);
	F("%x\n", INT_MAX);
	F("%x\n", INT_MAX + 1);
	F("%x\n", INT_MIN - 1);
	F("%x\n", INT_MIN);
	F("%x\n", INT_MIN + 1);
	F("%10x\n", 0);
	F("%10x\n", 1);
	F("%10x\n", 13);
	F("%10x\n", -16);
	F("%10x\n", INT_MAX - 1);
	F("%10x\n", INT_MAX);
	F("%10x\n", INT_MAX + 1);
	F("%10x\n", INT_MIN - 1);
	F("%10x\n", INT_MIN);
	F("%10x\n", INT_MIN + 1);

	F("%.10x\n", -1);
	F("%.10x\n", 0);
	F("%.10x\n", 1);
	F("%.10x\n", 13);
	F("%.10x\n", -16);
	F("%.10x\n", INT_MAX - 1);
	F("%.10x\n", INT_MAX);
	F("%.10x\n", INT_MAX + 1);
	F("%.10x\n", INT_MIN - 1);
	F("%.10x\n", INT_MIN);
	F("%.10x\n", INT_MIN + 1);

	F("%0.0x\n", -1);
	F("%0.0x\n", 0);
	F("%0.0x\n", 1);
	F("%0.0x\n", 13);
	F("%0.0x\n", -16);
	F("%0.0x\n", INT_MAX - 1);
	F("%0.0x\n", INT_MAX);
	F("%0.0x\n", INT_MAX + 1);
	F("%0.0x\n", INT_MIN - 1);
	F("%0.0x\n", INT_MIN);
	F("%0.0x\n", INT_MIN + 1);

	F("%.x\n", -1);
	F("%.x\n", 0);
	F("%.x\n", 1);
	F("%.x\n", 13);
	F("%.x\n", -16);
	F("%.x\n", INT_MAX - 1);
	F("%.x\n", INT_MAX);
	F("%.x\n", INT_MAX + 1);
	F("%.x\n", INT_MIN - 1);
	F("%.x\n", INT_MIN);
	F("%.x\n", INT_MIN + 1);

	F("%0x\n", -1);
	F("%0x\n", 0);
	F("%0x\n", 1);
	F("%0x\n", 13);
	F("%0x\n", -16);
	F("%0x\n", INT_MAX - 1);
	F("%0x\n", INT_MAX);
	F("%0x\n", INT_MAX + 1);
	F("%0x\n", INT_MIN - 1);
	F("%0x\n", INT_MIN);
	F("%0x\n", INT_MIN + 1);
	F("%010x\n", 0);
	F("%010x\n", 1);
	F("%010x\n", 13);
	F("%010x\n", -16);
	F("%010x\n", INT_MAX - 1);
	F("%010x\n", INT_MAX);
	F("%010x\n", INT_MAX + 1);
	F("%010x\n", INT_MIN - 1);
	F("%010x\n", INT_MIN);
	F("%010x\n", INT_MIN + 1);

	F("%0.10x\n", -1);
	F("%0.10x\n", 0);
	F("%0.10x\n", 1);
	F("%0.10x\n", 13);
	F("%0.10x\n", -16);
	F("%0.10x\n", INT_MAX - 1);
	F("%0.10x\n", INT_MAX);
	F("%0.10x\n", INT_MAX + 1);
	F("%0.10x\n", INT_MIN - 1);
	F("%0.10x\n", INT_MIN);
	F("%0.10x\n", INT_MIN + 1);

	F("%00.0x\n", -1);
	F("%00.0x\n", 0);
	F("%00.0x\n", 1);
	F("%00.0x\n", 13);
	F("%00.0x\n", -16);
	F("%00.0x\n", INT_MAX - 1);
	F("%00.0x\n", INT_MAX);
	F("%00.0x\n", INT_MAX + 1);
	F("%00.0x\n", INT_MIN - 1);
	F("%00.0x\n", INT_MIN);
	F("%00.0x\n", INT_MIN + 1);
	F("%0.x\n", -1);
	F("%0.x\n", 0);
	F("%0.x\n", 1);
	F("%0.x\n", 13);
	F("%0.x\n", -16);
	F("%0.x\n", INT_MAX - 1);
	F("%0.x\n", INT_MAX);
	F("%0.x\n", INT_MAX + 1);
	F("%0.x\n", INT_MIN - 1);
	F("%0.x\n", INT_MIN);
	F("%0.x\n", INT_MIN + 1);


	F("%-x\n", -1);
	F("%-x\n", 0);
	F("%-x\n", 1);
	F("%-x\n", 13);
	F("%-x\n", -16);
	F("%-x\n", INT_MAX - 1);
	F("%-x\n", INT_MAX);
	F("%-x\n", INT_MAX + 1);
	F("%-x\n", INT_MIN - 1);
	F("%-x\n", INT_MIN);
	F("%-x\n", INT_MIN + 1);

	F("%-10x\n", 0);
	F("%-10x\n", 1);
	F("%-10x\n", 13);
	F("%-10x\n", -16);
	F("%-10x\n", INT_MAX - 1);
	F("%-10x\n", INT_MAX);
	F("%-10x\n", INT_MAX + 1);
	F("%-10x\n", INT_MIN - 1);
	F("%-10x\n", INT_MIN);
	F("%-10x\n", INT_MIN + 1);

	F("%-.10x\n", -1);
	F("%-.10x\n", 0);
	F("%-.10x\n", 1);
	F("%-.10x\n", 13);
	F("%-.10x\n", -16);
	F("%-.10x\n", INT_MAX - 1);
	F("%-.10x\n", INT_MAX);
	F("%-.10x\n", INT_MAX + 1);
	F("%-.10x\n", INT_MIN - 1);
	F("%-.10x\n", INT_MIN);
	F("%-.10x\n", INT_MIN + 1);
}

int main()
{
	/* F("%p\n", (unsigned long long)0); */
	/* F("%.0p\n", (unsigned long long)0); */
	x_test();
	c_test();
	percent_test();
	s_test();
	/* F("%2147483645d\n", 1); */
}
