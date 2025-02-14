OBJ=main.o func.o

all:$(OBJ)
	objdump -D main.o > main.asm
	objdump -D func.o > func.asm
	gcc $(OBJ)
	objdump -D a.out > a.asm

clean:
	rm *.o *.asm a.out
