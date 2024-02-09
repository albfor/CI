CC = g++

CFLAGS = -Wall -Wpedantic

INC := $(addprefix -I./, $(wildcard lib/*))

OBJS = $(notdir $(shell find . -name *.cpp))
OBJS := $(addprefix build/, $(OBJS:%.cpp=%.o))

TEST_OBJS := $(filter-out build/main.o, $(OBJS))
MAIN_OBJS := $(filter-out build/test.o build/unity.o, $(OBJS))


run: .mkdirs bin/main
	bin/main $(NUM)

test: .mkdirs bin/test
	bin/test

bin/main: $(MAIN_OBJS)
	$(CC) -o bin/main $^

bin/test: $(TEST_OBJS)
	$(CC) -o bin/test $^

build/main.o: src/main.cpp 
	$(CC) -c -o $@ $^ $(INC) 

build/test.o: test/test.cpp 
	$(CC) -c -o $@ $^ $(INC) 

build/%.o: lib/*/%.cpp
	$(CC) -c -o $@ $^ $(INC)

.mkdirs:
	mkdir -p bin build

clean:
	rm -rf bin build
