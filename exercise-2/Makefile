CC = g++
CFLAGS = -Wall -MMD

INC := $(addprefix -I./, $(wildcard lib/*))
# find all cpp files
SRCS = $(notdir $(shell find . -name *.cpp))
# convert them to build/%.o 
OBJS := $(SRCS:%.cpp=build/%.o)
# test isn't depending on main
TEST_OBJS := $(filter-out build/main.o, $(OBJS))
# main isn't depending on test & unity
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
	$(CC) $(CFLAGS)  -c -o $@ $< $(INC)

build/test.o: test/test.cpp 
	$(CC) $(CFLAGS)  -c -o $@ $< $(INC)

build/%.o: lib/*/%.cpp
	$(CC) $(CFLAGS)  -c -o $@ $< $(INC)

-include $(OBJS:.o=.d)

.mkdirs:
	mkdir -p bin build

clean:
	rm -rf bin build
