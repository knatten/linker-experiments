base.o: base.cpp base.h
	# g++ -c base.cpp -I. -fPIC -std=c++17
	g++ -c -fvisibility=hidden base.cpp -I. -fPIC -std=c++17
base.a: base.o
	ar rcs libbase.a base.o
shared.o: shared.cpp base.h
	g++ -c shared.cpp -I. -fPIC -std=c++17
shared.so: shared.o base.a
	g++ -shared  -o libshared.so shared.o -lbase -L./
main.o: main.cpp libshared.so libbase.a base.h shared.h
	g++ -c main.cpp -I. -std=c++17
main: shared.so base.a main.o
	g++ -o main main.o -lbase -lshared -L.
	# g++ -o main main.o -lshared -lbase -L.
all: main
clean:
	rm -f *.o *.a *.so main
run: all
	LD_LIBRARY_PATH=. ./main; echo $$?
