TEXT := $(patsubst %.pdf,%.txt,$(PDF))

all: lab1

# lab1: main.o
# 	g++ main.o -o lab1
# 	./lab1

# main.o: main.cpp
# 	g++ -c main.cpp

# clean:
# 	rm -f *o lab1
# 	rm -f $(TEXT)

lab1:
	g++ -c main.cpp
	g++ main.o -o lab1
	./lab1


clean:
	rm -f *o lab1
