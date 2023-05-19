.PHONY: build clean

INC = /home/dellarrivalisa/gurobi1000/linux64/include/
CPPLIB = -lncurses -lpthread
CPP = gcc
#CARGS = -m64 -Wall 
SOURCES = *generic.c
LAB = exe
OBJ = obj
OBJECTS = $(patsubst %.c, %.o, $(wildcard *generic.c))

build: $(SOURCES) $(OBJ) $(OBJECTS)
	$(CPP) $(OBJ) -o $(LAB) $(CPPLIB) -lm

$(OBJ): *generic.c
	$(CPP) $(CARGS) -g -c $< -o $@ $(CPPLIB) -lm

clean:
	rm -rf $(OBJ) $(LAB) *.o
