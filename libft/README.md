*This project has been created as part of the 42 curriculum by aalemami@student.42amman.com*

# Libft
*My very first own library*

## Description
This project is created as part of the 42 curriculum. The aim is to create a C library called **libft**, which will be useful for future 42 projects.

This library consists of 3 parts:
1.  **Part 1 - Libc functions**: Reimplementation of standard C library functions. They have the same prototypes and behaviors as the originals (e.g., `strlen` becomes `ft_strlen`).
2.  **Part 2 - Additional functions**: A set of useful functions that are either not included in libc or exist in a different form (e.g., `ft_strjoin`, `ft_split`).
3.  **Part 3 - Linked Lists**: Functions to manipulate and manage linked lists.
4.  **part 4 - ft_printf**: ft_printf was added to this project

## Instructions

### Installation
To download the library to your machine, follow these steps:

1.  Open your terminal in your preferred directory.
2.  Clone the repository:
    ```bash
	git clone <paste_your_ssh_link_here>
	```

### How to Use
To use this library in your own code, include the header file and link the library during compilation:

```C
#include "libft.h"

int main(void)
{
    ft_putstr_fd("Hello 42!", 1);
    return (0);
}
```

### Compilation
The project includes a Makefile. You can compile the library using:
```bash
make
```

This will generate the libft.a static library file.

Compile your program with:

```Bash

gcc main.c -L. -lft -o my_program
```

## Resources
Man pages: Use man function_name (e.g., man strlen) to understand the original behavior.

Makefiles: [[C Programming: Makefiles by Barry Brown - A great tutorial on how automation works](https://www.youtube.com/live/GExnnTaBELk?si=aYJHOSgV4ig30CG7)].

## License

No license.