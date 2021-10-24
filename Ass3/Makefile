ALL: ass3j main

ass3j: ass3j.o
	g++ ass3j.cpp -o ass3j

ass3j.o: ass3j.cpp read.h hashClass.h dataStruct.h heap.h
	g++ -c ass3j.cpp

main: main.o
	g++ main.o -o main

main.o: main.cpp read.h hashClass.h dataStruct.h heap.h
	g++ -c main.cpp

clean:
	rm *.o ass3j main