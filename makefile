all: control worker
	gcc -o control control.o
	gcc -o worker worker.o

control: control.c
	gcc -c control.c

worker: worker.c
	gcc -c worker.c

clean:
	rm *.o

