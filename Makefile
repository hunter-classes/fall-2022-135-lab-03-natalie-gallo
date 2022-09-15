# Starter Makefile
# add .cpp and .h files as specified in each task.

OBJECTS = main.o reservoir.o reverseorder.o

main: main.o reservoir.o reverseorder.o
	g++ -o main $(OBJECTS)

main.o: main.cpp reservoir.h
	g++ -c main.cpp

reservoir.o: reservoir.cpp reservoir.h
	g++ -c reservoir.cpp

reverseorder.o: reverseorder.cpp reverseorder.h
	g++ -c reverseorder.cpp
clean:
	rm -f main.o reservoir.o reverseorder.o

help:
	@echo main: build executable main
	@echo clean: remove object file
	@echo help: this file

