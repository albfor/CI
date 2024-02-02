CC := g++

CFLAG := -Wall -Wextra -g

BUILD_DIR := build
BIN_DIR := bin
LIB_DIR := lib
FIZZBUZZ := -I./$(LIB_DIR)/fizzbuzz
UNITY := -I./$(LIB_DIR)/unity

# All library cpp files 
LIB := $(notdir $(wildcard $(LIB_DIR)/*/*.cpp))
LIB_OBJS := $(LIB:%.cpp=$(BUILD_DIR)/%.o)
APP_NAME := main

all: test bin
	$(BIN_DIR)/$(APP_NAME) $(NUM)

bin: .mkdirs $(BUILD_DIR)/main.o $(BUILD_DIR)/fizzbuzz.o
	$(CC) -o $(BIN_DIR)/$(APP_NAME) $(CFLAGS) $(BUILD_DIR)/$(APP_NAME).o $(BUILD_DIR)/fizzbuzz.o

test: .mkdirs $(BUILD_DIR)/test.o $(LIB_OBJS)
	$(CC) -o $(BIN_DIR)/test $(CFLAGS) $(BUILD_DIR)/test.o $(LIB_OBJS)

$(BUILD_DIR)/test.o: test/test.cpp
	$(CC) -o $(BUILD_DIR)/test.o -c $(CFLAGS) $(FIZZBUZZ) $(UNITY) test/test.cpp

$(BUILD_DIR)/$(APP_NAME).o: src/$(APP_NAME).cpp 
	$(CC) -o $(BUILD_DIR)/$(APP_NAME).o -c $(CFLAGS) $(FIZZBUZZ) src/$(APP_NAME).cpp

# Makes .o files for all cpp files in lib/
$(BUILD_DIR)/%.o: $(LIB_DIR)/*/%.cpp
	$(CC) -o $@ -c $(CFLAGS) $^

.mkdirs:
	mkdir -p $(BUILD_DIR) $(BIN_DIR)

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)
