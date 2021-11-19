shared.o: shared.cpp shared.h
	g++ -c shared.cpp -I. -fPIC -std=c++17
shared.so: shared.o
	g++ -shared  -o libshared.so shared.o
main.o: main.cpp libshared.so shared.h
	g++ -c main.cpp -I. -std=c++17
main: shared.so main.o
	g++ -o main main.o -lshared -L.
all: main
clean:
	rm -f *.o *.a *.so main
run: all
	LD_LIBRARY_PATH=. ./main; echo $$?
