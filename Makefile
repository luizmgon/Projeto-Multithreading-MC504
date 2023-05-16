all: river_crossing_generic
exe: river_crossing_generic.o 
river_crossing_generic.o: river_crossing_generic.c
	gcc -o river_crossing_generic.o -c river_crossing_generic.c
clean:
	rm -rf *.o
mrproper: clean
	rm -rf exe