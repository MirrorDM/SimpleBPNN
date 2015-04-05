CC=g++
LD=g++
OBJ=main.o Layer.o Trainset.o misc.o

main:$(OBJ)
	$(LD) -o main $(OBJ)

main.o: Layer.h Trainset.h
Layer.o: Layer.h misc.h
Trainset.o: Trainset.h
misc.o: misc.h

clean:
	rm *.o main