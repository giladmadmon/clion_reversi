# Gilad Madmon
# Dafna Magid

a.out: compile
	g++ *.o 
	rm -f *.o

compile:
	g++ -Iinclude/ -c src/*.cpp

run:
	./a.out
