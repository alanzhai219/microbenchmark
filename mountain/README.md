This directory contains code for generating a memory mountain, as
described in Computer Systems: A Programmer's Perspective 

clock.{c,h}	- routines for using x86 and Alpha cycle timers
fcyc2.{c,h}	- routines that estimate the number of cycles required 
                  by a function f that takes two arguments.
Makefile	- memory mountain makefile
mountain.c	- program that generates the memory mountain.

```bash
python draw.py "$(./mountain)"
```