target = b03901023 ./src/HashNode ./src/Entry
CPPFLAGS = -O2 -g -std=c++11 -Wall

all: $(target)

b03901023: b03901023.cpp ./src/HashNode.cpp ./src/HashNode.h
	g++ $(CPPFLAGS) b03901023.cpp  ./src/HashNode.cpp -o $@

clean:
	rm -rf $(target)

run:
	./b03901023