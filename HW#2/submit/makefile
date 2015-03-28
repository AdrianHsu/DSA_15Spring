target = b03901023 ./src/HashNode ./src/HashMap ./src/Entry
CPPFLAGS = -O2 -std=c++11 -Wall

all: $(target)

b03901023: b03901023.cpp ./src/HashNode.cpp ./src/HashNode.h ./src/HashMap.h ./src/HashMap.cpp ./src/Entry.h
	g++ $(CPPFLAGS) b03901023.cpp  ./src/HashNode.cpp ./src/HashMap.cpp ./src/Entry.h -o $@

clean:
	rm -rf $(target)

run:
	./b03901023