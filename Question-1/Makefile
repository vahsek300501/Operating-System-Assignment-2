all:
	gcc prog_process.c -o output.out
	./output.out
preprocessing:
	gcc -E prog_process.c -o process.i
compilation:
	gcc -S prog_process.c -o process.s
assembly:
	gcc -c prog_process.c -o process.o
