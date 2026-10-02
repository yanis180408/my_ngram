# My Ngram

**Submit directory:** `.`
**Submit files:** `Makefile` — `*.c` — `*.h`

## Specifications

Write a program `my_ngram`; it will count the number of occurrences per character.

### NAME
`my_ngram`

### SYNOPSIS
```
my_ngram text [text2, text3]
```

### DESCRIPTION

In computational linguistics and probability, an **n-gram** is a contiguous sequence of n items from a given sample of text or speech. The items can be phonemes, syllables, letters, words or base pairs according to the application. The n-grams typically are collected from a text or speech corpus. When the items are words, n-grams may also be called shingles.

Google Inc. has used this technique to improve the completion of its Search Engine. The program was developed by Jon Orwant and Will Brockman, and released in mid-December 2010.

`my_ngram` will take 1 or multiple strings as arguments.

It will display, one per line, each character and the number of times it appears.

Order will be alphanumerical.

## Examples

**Example 00**
```bash
$>./my_ngram "abcdef"
a:1
b:1
c:1
d:1
e:1
f:1
$>
```

**Example 01**
```bash
$>./my_ngram "        "
 :8
$>
```
*(8 spaces :-))*

**Example 02**
```bash
$>./my_ngram "aaabb" "abc"
a:4
b:3
c:1
$>
```

## Technical information

- (If you are doing this as a project) you must create a `Makefile`, and the output is the command itself.
- You **can** use:
  - `printf(3)`
  - `write(2)`
- You **cannot** use:
  - Any functions/syscalls which do not appear in the previous list
  - Yes, it includes `exit`
  - Multiline macros are forbidden
  - Including another `.c` is forbidden
  - Macros with logic (while/if/variables/...) are forbidden

## Requirements

- Your code must be compiled with the flags `-Wall -Wextra -Werror`.
- Your Makefile must have `clean` & `fclean` rules.

**Example of some rules for Makefiles:**
```makefile
all : $(TARGET)

$(TARGET) : $(OBJ)
	gcc $(CFLAGS) -o $(TARGET) $(OBJ)

$(OBJ) : $(SRC)
	gcc $(CFLAGS) -c $(SRC)

clean:
	rm -f *.o

fclean: clean
	rm -f $(TARGET)

re: fclean all
```

## Warnings

It's a bad practice to submit "object/binary files". Gandalf will reject your project if you submit your binary (with the message: `"pushed file wrong format"`).

## Gandalf issue

Gandalf is sending an extra `"`. Please add a check `if != '"'` in order to pass the project.
```c
#include <stdio.h>

int main(int argc, char *argv[]){
  int arr[256] = {0};
  for (int i = 1; i < argc ; i++) {
    for (int j = 0; argv[i][j] != '\0' ; j++) {
      if (argv[i][j] != '"'){
        arr[argv[i][j]]++;
      }

      else{

      }

    }

  }
  for (int x = 0;  x < 256 ; x++){
    if (arr[x] > 0){
      printf ("%c:%d\n", x, arr[x]);
    }
  }
  return 0;
}

```
Makefile!!!!!:
```o

NAME = my_ngram
SRC = my_ngram.c
OBJ = my_ngram.o
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

$(OBJ) : $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)


```