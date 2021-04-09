FLAGS = -pedantic-errors -std=c++11

output: main.o menu.o user.o
	g++ $(FLAGS) $^ -o $@
	
user.o: user.cpp user.h
	g++ $(FLAGS) -c $<

menu.o: menu.cpp user.h menu.h
	g++ $(FLAGS) -c $<

main.o: main.cpp user.h menu.h
	g++ $(FLAGS) -c $<
	
clean:
	rm *.o output

.PHONY: clean
