run: build
	bin/main $(NUM)

build: .mkdirs build/main.o build/fizzbuzz.o
	g++ -o bin/main build/main.o build/fizzbuzz.o

check: .mkdirs build/test.o build/fizzbuzz.o build/unity.o
	g++ -o bin/test build/test.o build/fizzbuzz.o build/unity.o
	bin/test

build/unity.o: lib/unity/unity.cpp
	g++ -c -o build/unity.o lib/unity/unity.cpp

build/test.o: test/test.cpp lib/unity/unity.h
	g++ -c -o build/test.o test/test.cpp -I lib/fizzbuzz -I lib/unity

build/main.o: src/main.cpp lib/fizzbuzz/fizzbuzz.h
	g++ -c -o build/main.o src/main.cpp -I lib/fizzbuzz 

build/fizzbuzz.o: lib/fizzbuzz/fizzbuzz.cpp
	g++ -c -o build/fizzbuzz.o lib/fizzbuzz/fizzbuzz.cpp

.mkdirs:
	mkdir -p build bin

clean:
	rm -rf build bin

