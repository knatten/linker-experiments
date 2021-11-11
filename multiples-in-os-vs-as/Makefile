main.o: main.cpp
	g++ -c main.cpp
f1.o: f1.cpp
	g++ -c f1.cpp
f2.o: f1.cpp
	g++ -c f2.cpp
usingo: main.o f1.o f2.o
	g++ -o usingo main.o f1.o f2.o
f1.a: f1.o
	ar rcs libf1.a f1.o
f2.a: f2.o
	ar rcs libf2.a f2.o
usinga: main.o f1.a f2.a
	# g++ -o usinga main.o -lf1 -lf2 -L.
	g++ -o usinga main.o -Wl,--whole-archive -lf1 -lf2 -L.
all: a1.a a2.a usingo
clean:
	rm -f *.o *.a unsingo
