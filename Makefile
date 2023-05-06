FLAGS = -pedantic-errors -std=c++11

fight_rules.o: fight_rules.cpp header.h
        g++ $(FLAGS) -c $<
map.o: map.cpp header.h
        g++ $(FLAGS) -c $<
events.o: events.cpp fight_rules.cpp header.h
        g++ $(FLAGS) -c $<
gamesave.o: gamesave.cpp header.h
        g++ $(FLAGS) -c $<
main.o: main.cpp header.h
        g++ $(FLAGS) -c $<
game: main.o gamesave.o events.o map.o fight_rules.o
        g++ $(FLAGS) $^ -o $@
clean:
        rm -f game main.o gamesave.o events.o map.o fight_rules.o game.tgz
tar:
        tar -czvf game.tgz *.cpp *.h
.PHONY: clean ta
