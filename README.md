*This project has been created as part of the 42 curriculum by mamatter.*

# ft_printf

## Description

**ft_printf** is a re-implementation of the C standard library function `printf()`.
The goal of the project is to learn how **variadic functions** work in C
(`<stdarg.h>`).

The project produces a library, `libftprintf.a`, which exposes one function:

```c
int ft_printf(const char *format, ...);
```

Like the original, it writes to the standard output and returns the **number of
characters printed**. The buffer management of the original `printf()` is not
reimplemented, as required by the subject.

### Supported conversions

| Conversion | Description                                  |
|:----------:|----------------------------------------------|
| `%c`       | Prints a single character                    |
| `%s`       | Prints a string                              |
| `%p`       | Prints a `void *` pointer in hexadecimal     |
| `%d`       | Prints a signed decimal (base 10) number     |
| `%i`       | Prints a signed integer (base 10)            |
| `%u`       | Prints an unsigned decimal (base 10) number  |
| `%x`       | Prints a number in hexadecimal (lowercase)   |
| `%X`       | Prints a number in hexadecimal (uppercase)   |
| `%%`       | Prints a percent sign                        |

## Instructions

### Compilation

The project is compiled with `cc -Wall -Wextra -Werror`.

```bash
make          # builds libftprintf.a at the root of the repository
make clean    # removes the object files
make fclean   # removes the object files and libftprintf.a
make re       # fclean + all
```

The library is created with `ar`.

### Usage

```c
#include "ft_printf.h"

int main(void)
{
	int	len;

	len = ft_printf("Hello %s! %d + %d = %i (0x%x)\n", "42", 1, 2, 3, 255);
	ft_printf("Printed %d characters\n", len);
	return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o test
./test
```

## Algorithm and data structure

### Algorithm

`ft_printf` reads the format string in a **single pass**, from left to right:

1. A `va_list` is initialised with `va_start`.
2. Each character of the format string is inspected:
   - if it is not a `%`, it is written as is with `write`;
   - if it is a `%`, the next character is the conversion specifier and the
     matching handler is called (`c`, `s`, `p`, `d`/`i`, `u`, `x`, `X`, `%`).
3. Each handler gets its argument with `va_arg`, writes it directly with `write`
   and returns the number of bytes written.
4. The counts are added up and the total is returned after `va_end`.

Numbers are printed with a **recursive base conversion**: the number is divided
by the base until a single digit remains, then digits are written on the way back.
The same function serves base 10 (`d`, `i`, `u`) and base 16 (`x`, `X`, `p`);
only the base string changes.

Special cases follow the behaviour of the original `printf()` on Linux:

- `%s` with a `NULL` pointer prints `(null)`;
- `%p` with a `NULL` pointer prints `(nil)`, otherwise `0x` followed by the address;
- `INT_MIN` is handled by converting to a wider type before negating, to avoid overflow.

### Why this approach?

- **No buffer**: direct `write` calls keep the code simple, and the subject
  forbids reimplementing the original buffer management.
- **One handler per conversion**: each function does one thing, which makes the
  code readable and easy to test.
- **Each function returns the number of bytes written**: the final return value is
  computed without a second pass over the data.
- **No dynamic allocation**: everything is written on the fly, so no memory leaks.

## Resources

### References

- `man 3 printf`
- `man 3 stdarg`
- `man 2 write`
- [The 42 Norm](https://github.com/42School/norminette)

### Use of AI

AI was used for: README.
