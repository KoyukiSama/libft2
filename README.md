*This project has been created as part of the 42 curriculum by kaclaes.*

## Description

Libft is a custom C standard library built as part of the 42 curriculum.  
The goal of this project is to reimplement common standard C functions, learn memory management, pointers, and data structures at a low level (like a linked list).

This library provides functions for string manipulation, memory handling, character checks, and linked list operations.

## Instructions

### Compilation
Run the following command to build the library:

```make```

Some extra useful make commands:

Rebuild package        : ```make re```

Remove  objects        : ```make clean```

Remove  objects & lib  : ```make fclean```

### Usage

Copy the header file into your project:

```cp PATH_TO_LIBFT/libft.h PATH_TO_PROJECT/

Include it in your C files:

```#include "libft.h"```

Compile with:

```cc -Wall -Werror -Wextra PATH_TO_PROJECT/*.c libft.a```

## Resources

- https://man7.org/linux/man-pages/
- https://www.gnu.org/software/libc/manual/
- https://en.cppreference.com/
- 42 intra documentation and subject PDFs

### AI Usage

AI was used as a learning assistant to:
- clarify edge cases in C standard library functions
- help debug pointer and memory-related issues
- review and verify edge-case handling in functions such as ft_split, ft_lstmap, ft_strnstr, ...
- understand correct behavior of edge cases defined in man pages
- helping write the README.md

No AI-generated code was blindly copied; all implementations were written and tested manually.

## Library Description

This library implements a subset of the C standard library, including:

### Memory functions
- memset, bzero, memcpy, memmove, memchr, memcmp, calloc

### String functions
- strlen, strdup, strlcpy, strlcat
- strchr, strrchr, strncmp, strnstr, substr, strjoin, strtrim, split, strmapi, striteri

### Character functions
- isalpha, isdigit, isalnum, isascii, isprint, toupper, tolower

### Conversion functions
- atoi, itoa

### File descriptor functions
- putchar_fd, putstr_fd, putendl_fd, putnbr_fd

### Linked list functions
- lstnew, lstadd_front, lstadd_back, lstdelone, lstclear
- lstiter, lstmap, lstsize, lstlast

## Technical Choices

- Manual memory management using malloc/free
- No use of standard library functions except allowed ones
- Careful handling of edge cases such as NULL pointers and integer overflow
- Linked list implemented using singly linked nodes