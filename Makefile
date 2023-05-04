FLAGS = -pedantic-errors -std=c++11

Card.o: Card.cpp Card.h
	g++ $(FLAGS) -c $<

detect_invalid_input.o: detect_invalid_input.cpp detect_invalid_input.h
	g++ $(FLAGS) -c $<

load_game.o: load_game.cpp load_game.h
	g++ $(FLAGS) -c $<

new_game.o: new_game.cpp new_game.h
	g++ $(FLAGS) -c $<

save_game.o: save_game.cpp save_game.h
	g++ $(FLAGS) -c $<

Baccarat.o: Baccarat.cpp Card.h detect_invalid_input.h load_game.h new_game.h save_game.h
	g++ $(FLAGS) -c $<

Baccarat: Baccarat.o Card.o detect_invalid_input.o load_game.o new_game.o save_game.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm -f Baccarat *.o

.PHONY: clean
