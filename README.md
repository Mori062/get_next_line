<h1 align="center">
  get_next_line
</h1>

<p align="center">
	<b><i>Reading a line on a fd is way too tedious</i></b><br>
</p>

---

## About the project

> _The aim of this project is to make you code a function that returns a line, read from a file descriptor._


## Usage

### Requirements

The function is written in C language and thus needs the **`cc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Using it in your code**

To use the function in your code, simply include its header:

```C
#include "get_next_line.h"
```

and, when compiling your code, add the source files and the required flag:

```shell
get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=<size>
```

## Testing

You only have to edit the get_next_line.c file and uncomment the main function and headers inside it.
You can edit test.txt files to put another text if you wish to test other cases.
Then simply run this command (change "xx" with desired buffer size) :

```shell
cc -Wall -Werror -Wextra -D BUFFER_SIZE=xx get_next_line.c get_next_line_utils.c -o gnl
./gnl
```

## Remaked

I reworked this project to make it more robust.
See [gnl_remake](https://github.com/Mori062/gnl_remake) for details.
