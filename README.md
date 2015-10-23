# anigramer v0.1.1

Simple program to try and find single word anagrams. Making use of binary heap trees and linked lists, this program uses libreadline and GNU getline.

GPLv2

## Project files
```
ali@ali-K53E:~/Code/C/anigramer$ tree .
.
├── anigramer
├── anigramer.c
├── anigramer.h
├── anigramer-upx
├── LICENSE
├── main.c
├── Makefile
└── README.md

0 directories, 8 files
```

## Running

```
$ ./anigramer /usr/share/dict/american-english
```

On GNU/Linux systems often you will find a wordlist in /usr/share/dict.

### Sample output

```
ali@ali-K53E:~/Code/C/anigramer$ ./anigramer /usr/share/dict/american-english 
Ctrl+C to quit.
Enter search word: pots
pots->Post->opts->post->pot's->pots->spot->stop->top's->tops.
```

## Compiling

```
$ make
```

```
$ gcc -o anigramer main.c anigramer.c -O3 -lreadline
```

### Dependencies

Uses readline and getline.

```
# apt-get install libreadline6
```

Or there abouts should get you required dependencies on GNU/Debian systems.

### ToDo

Chase any memory leaks.
