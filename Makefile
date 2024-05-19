all:
	cc src/main.c -c -o main.o
	cc src/files.c -c -o files.o
	cc src/xor.c -c -o xor.o
	cc xor.o files.o main.o -o xor
	rm -rf main.o files.o xor.o