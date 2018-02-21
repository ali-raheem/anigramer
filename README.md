# anigramer v2.0.2 [![Build Status](https://travis-ci.org/wolfmankurd/anigramer.svg?branch=master)](https://travis-ci.org/wolfmankurd/anigramer)

Simple program to try and find single word anagrams. Making use of binary heap trees and linked lists.

GPLv2

## Project files

Listing of files in this project with description.

```
.
├── anigramer.c			Main anigramer code
├── anigramer.h			Header for anigramer
├── LICENSE			GPLv2 copy
├── main.c			Main interface
├── Makefile			Simple makefile
├── pre-built			Some prebuilt binaries
│   ├── linux-x86_64		64 Linux shared binaries
│   │   ├── anigramer		64bit linux
│   │   └── anigramer-upx	64bit linux packed
│   └── raspberrypi
│       └── anigramer		Binary for arm
└── README.md			This Readme

3 directories, 9 files
```

## Running

```
$ ./anigramer /usr/share/dict/american-english
```

On GNU/Linux systems often you will find a wordlist in /usr/share/dict.

You may pass options to alter it's operation, currently all that is supported is -b which will make the program ignore how many copies of each letter you pass it "broken keyboard mode". Thus elope and people will also match.

```
ali@ali-K53E:~/Code/C/anigramer$ ./anigramer 
Usage:
	./anigramer word-file [OPTIONS]

Options:
	-b	Broken keyboard mode.
```

### Sample output

```
ali@ali-K53E:~/Code/C/anigramer$ ./anigramer /usr/share/dict/american-english 
Ctrl+D to quit.
Enter search word: anigramer
margarine
```

## Compiling

```
$ make
```

Or explicitly

```
$ gcc -o anigramer main.c anigramer.c -O3
```

### Dependencies

Uses GNU getline to reduce malloc calls.
UPX is an optional dependencies should you want smaller binaries (typically 5-6kB v 11kB), upx may be installed from the repos on most distros.


### Installing

Copy binary files anigramer and anigramer-upx (if present) into a directory which is part of your $PATH. I used ~/.local/bin for system wide installation you may require root priviledges.

### ToDo

* Reduce cache misses, rather than multiple mallocs try to minimise non-continuous memory.
* Chase any memory leaks.
