all: sed
.PHONY: test
sed: main.o func.o
	gcc -o sed main.o func.o

main.o: main.c
	gcc -c main.c

func.o: func.c
	gcc -c func.c

test: sed
	./sed input.txt -i -f LOL
clean:
	rm sed *.o
