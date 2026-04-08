# ft_printf

[![Language](https://img.shields.io/badge/language-C-informational?style=flat)](https://github.com/topics/c)

## Description

ft_printf is a custom implementation of the standard C printf function in C. This project teaches variadic functions - functions that accept a variable number of arguments. The implementation mimics the original printf() behavior, supporting various format specifiers for characters, strings, pointers, and numeric conversions.

## Technologies & Concepts

- Variadic Functions (va_start, va_arg, va_copy, va_end)
- String Manipulation
- Type Conversion
- Output Formatting
- Dynamic Format Parsing
- Makefile Development

## Installation

```bash
git clone https://github.com/fabbbiodc/printf.git
cd printf
```

## Usage

```bash
make
```

This compiles the library and creates `libftprintf.a`. To use in your programs:

```c
#include "ft_printf.h"
```

Link the library during compilation:

```bash
gcc -L. -lftprintf your_program.c
```

## Compilation

| Command | Description |
|---------|-------------|
| `make` | Compile the library |
| `make clean` | Remove object files |
| `make fclean` | Remove all build artifacts |
| `make re` | Full rebuild |

## Project Structure

```
printf/
├── ft_printf.h       # Header file with function prototype
├── ft_printf.c      # Main printf implementation
├── ft_parse.c       # Format string parser
├── ft_tools.c       # Utility functions
├── libft/           # Linked libft library
├── print/           # Conversion handlers
├── Makefile
└── README.md
```

## Supported Conversions

| Specifier | Description |
|-----------|-------------|
| `%c` | Single character |
| `%s` | String |
| `%p` | Pointer (hexadecimal) |
| `%d` | Decimal integer |
| `%i` | Integer (base 10) |
| `%u` | Unsigned decimal |
| `%x` | Hexadecimal (lowercase) |
| `%X` | Hexadecimal (uppercase) |
| `%%` | Percent sign |

## How It Works

The ft_printf function works by:

1. **Parsing** - Iterates through the format string to identify format specifiers
2. **Processing** - For each specifier, extracts the corresponding argument using variadic macros
3. **Converting** - Converts the argument to its string representation based on the specifier
4. **Output** - Writes the result using the `write()` system call

The project uses a modular approach with separate functions handling each conversion type, making the code extensible and maintainable.

## Key Features

- **Variadic Argument Handling** - Uses `va_start`, `va_arg`, `va_copy`, and `va_end` macros to process variable arguments
- **Modular Conversion Pipeline** - Each format specifier has a dedicated handler function
- **Format String Parsing** - Supports flags, width, precision, and length modifiers
- **Libft Integration** - Reuses Libft functions for string and memory operations
- **Return Value Tracking** - Returns the total number of characters printed, matching standard `printf` behavior

## Tech Stack

- **Language:** C
- **System Calls:** `write()` for output
- **Libraries:** Custom Libft submodule for utility functions
- **Build:** Makefile with static library compilation

## Resources

- [Variadic Functions in C](https://en.cppreference.com/w/c/variadic) - Reference for `stdarg.h` macros
- [printf Format Specifiers](https://en.cppreference.com/w/c/io/fprintf) - Standard format string reference
- [The `write()` System Call](https://man7.org/linux/man-pages/man2/write.2.html) - Core output mechanism
