target = demo HashNode
CPPFLAGS = -O2 -g -std=c++11 -Wall

all: $(target)

demo: demo.cpp HashNode.cpp HashNode.h
	g++ $(CPPFLAGS) demo.cpp  HashNode.cpp -o $@

clean:
	rm -rf $(target)
