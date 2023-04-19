FLAGS = -pedantic-errors -std=c++11

d2boh.o: d2boh.cpp d2boh.h
	g++ $(FLAGS) -c $<
main3.o: main3.cpp d2boh.h 
	g++ $(FLAGS) -c $<
main3: d2boh.o main3.o
	g++ $(FLAGS) $^ -o $@
clean:
	rm -f main3 main3.o d2boh.o
.PHONY: clean
