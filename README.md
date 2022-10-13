# ft_printf

## The Project

Recode printf in C.

- It doesn't do the buffer management like the real printf.
- It manages the following conversion: **cspdiuxX%**
- It manage any combination of the following flags: **-0.\*** and minimum field width with all conversions.

### misc
- I can use `malloc`, `free`, `write`, `va_start`, `va_arg`, `va_copy` and `va_end`
  and other normal libc functions are forbidden.
- In no way can it quit abruptly.
  (segmentation fault, bus error, double free, etc).
- All heap allocated memory space must be properly freed when necessary.
  No leaks will be tolerated.
- Global variables are forbidden.
- All code must conform to the [42 Norm](https://github.com/42School/norminette).

## Usage

Clone this repository and run `make`, and make `libftprintf.a`.

This file itself isn't executable. If you want to use `ft_printf()`,
code the file something like the below,
```c
#include "ft_printf.h"

int main(void) {
	ft_printf("%d\n", 100);
}
```
and compile it like
```bash
gcc main.c -I./ libftprintf.a
```

> **Warning**
> 
> I didn't manage the case when compiling with the `-Wall` flag output error.
> I also didn't manage if the input string length is bigger than INT_MAX.
>
> My ft_printf's behavior is weird in these cases.

## Author

[Twitter](https://twitter.com/t76_1205)

## Licence

[MIT](./LICENSE)
