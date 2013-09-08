NAME := cpp-programming-language-1

clean:
	rm -rf bin ; mkdir -p bin

build: clean
	g++ -I include src/** -o bin/$(NAME)

debug:
	g++ -I include -g src/** -o bin/$(NAME)-test
	gdb bin/$(NAME)-test

all: build

