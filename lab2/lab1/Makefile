# Compiler settings
CXX = g++
CXXFLAGS = -g

# Default target
all: build/debug.out

# Object files
build/rect.o: src/rect.cpp src/rect.hpp
	$(CXX) $(CXXFLAGS) -c -o build/rect.o src/rect.cpp

build/my_string.o: src/my_string.cpp src/my_string.hpp
	$(CXX) $(CXXFLAGS) -c -o build/my_string.o src/my_string.cpp

build/barrel.o: src/barrel.cpp src/barrel.hpp
	$(CXX) $(CXXFLAGS) -c -o build/barrel.o src/barrel.cpp

build/matrix.o: src/matrix.cpp src/matrix.hpp
	$(CXX) $(CXXFLAGS) -c -o build/matrix.o src/matrix.cpp

build/text_wrapper.o: src/text_wrapper.cpp src/text_wrapper.hpp
	$(CXX) $(CXXFLAGS) -c -o build/text_wrapper.o src/text_wrapper.cpp

build/debug.out: build/rect.o build/my_string.o build/barrel.o build/matrix.o build/text_wrapper.o
	$(CXX) $(CXXFLAGS) -o build/debug.out src/main.cpp build/rect.o build/my_string.o build/barrel.o build/matrix.o build/text_wrapper.o

debug: build/debug.out
	gdb build/debug.out

clean:
	rm -rf build

.PHONY: all debug clean
