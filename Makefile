#This file specifies how to build an executable program from source code files by defining two flags passed to the `g++` compiler: `-pedantic-errors` for warning non-standard code and `-std=c++11` for using C++11 standard. 
#The file contains rules for compiling source code files into object files and linking them into an executable program. 

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

Baccarat103: Baccarat.o Card.o detect_invalid_input.o load_game.o new_game.o save_game.o
	g++ $(FLAGS) $^ -o $@

clean: #The `clean` rule deletes the `Baccarat` executable program and all object files.
	rm -f Baccarat *.o

.PHONY: clean
