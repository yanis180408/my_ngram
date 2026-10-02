# Welcome to My Ngram
***

## Task
The goal of this project is to write a program that counts the occurrences of every character found in the strings given as command line arguments.
The result is displayed one character per line, sorted in ascending ASCII order.
The challenge lies in counting efficiently across several arguments, without relying on the standard library for string handling or sorting, while only using the allowed functions of the subject.

## Description
I solved this problem by using a frequency table indexed by character value:
- **Counting** : an array of 256 integers, initialized to zero, stores the number of occurrences of each possible character.
- **Argument Parsing** : `main` walks through every argument and every character of each argument, incrementing the matching counter.
- **Sorted Output** : since the table is indexed by ASCII value, reading it from index 0 to 255 gives the characters in ASCII order with no extra sorting step.
- **Display** : only characters with a count greater than zero are printed, in the format `character:count`.
- **Custom Utilities** : helper functions replace the standard library (output with `write`, number-to-string conversion).
- **Error Handling** : if no argument is given, the program exits without displaying anything.

## Installation
The project includes a Makefile for easy compilation.
1. Compile the project :
```bash
make
```

2. Recompile (clean and build) :
```bash
make re
```

3. Clean object files :
```bash
make clean
```

4. Clean everything (executable and objects) :
```bash
make fclean
```

## Usage
The program takes any number of strings as arguments. Occurrences are counted across all of them together.

**Syntax :**
```bash
./my_ngram [STRING...]
```

**Examples :**

One argument:
```
$>./my_ngram "hello"
e:1
h:1
l:2
o:1
$>
```

Several arguments (counts are combined):
```
$>./my_ngram "abc" "abcd"
a:2
b:2
c:2
d:1
$>
```

Spaces and special characters are counted too:
```
$>./my_ngram "a a"
 :1
a:2
$>
```

### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>