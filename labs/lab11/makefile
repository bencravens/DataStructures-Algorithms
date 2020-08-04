all:
	gcc -ansi -pedantic -W -Wall -O2 -g -o output htable_test.c mylib.c htable.c
	time ./output 18143 < war-and-peace-20.txt | sort -n
