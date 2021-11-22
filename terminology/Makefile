file.o: file.cpp
	g++ -c -std=c++17 -fPIC file.cpp
shared.o: file.o
	g++ -shared -o libshared.so file.o
all: shared.o
clean:
	rm -f *.o *.so
