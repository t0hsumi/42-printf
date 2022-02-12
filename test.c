#include <stdio.h>

int main()
{
	int a = 100;
	int res = 0;
	if (!a) res = 1;
	else
	{
		while (a){
			a /= 10;
			res++;
		}
	}
	printf("%d\n", res);
}
