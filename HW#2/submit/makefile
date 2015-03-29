target = b03901023 HashNode
CPPFLAGS = -O2 -g -std=c++11 -Wall

all: $(target)

b03901023: b03901023.cpp HashNode.cpp HashNode.h
	g++ $(CPPFLAGS) b03901023.cpp  HashNode.cpp -o $@

clean:
	rm -rf $(target)

run:
	./b03901023