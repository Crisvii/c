CC = g++
LIBS = -lallegro -lallegro_image

3enRaya: funciones.o 3enRaya.o
	$(CC) funciones.o 3enRaya.o -o 3enRaya $(LIBS)
funciones.o: funciones.cpp funciones.h
	$(CC) -c funciones.cpp
3enRaya.o: 3enRaya.cpp funciones.h
	$(CC) -c 3enRaya.cpp
.PHONY: clean

clean:
	rm *.o 3enRaya
