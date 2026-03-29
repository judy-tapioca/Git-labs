# Compiler and flags
CXX = g++
CXXFLAGS = -g -Wall

# Source files
SRC = src/main.cpp src/rect.cpp src/my_string.cpp src/barrel.cpp src/text_wrapper.cpp src/matrix.cpp

# Object files
OBJ = build/rect.o build/my_string.o build/barrel.o build/text_wrapper.o build/matrix.o

# Final executable
TARGET = build/debug.out

# Default target
all: $(TARGET)

# Link executable
$(TARGET): $(OBJ) src/main.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) src/main.cpp $(OBJ)

# Pattern rule for .o files
build/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Debug target
debug: $(TARGET)
	gdb $(TARGET)

# Memory leak target
build/leaks.out: $(OBJ) src/main.cpp
	$(CXX) -g -fsanitize=address -o build/leaks.out src/main.cpp $(OBJ)

leaks: build/leaks.out
	./build/leaks.out < input.txt
	# or use valgrind: valgrind ./build/leaks.out < input.txt

# Clean build files
clean:
	rm -f build/*.o build/*.out
# Improvements:
# - Used variables (CXX, CXXFLAGS) to simplify changes
# - Used pattern rules (build/%.o) to avoid repeating code
# - Added 'clean' target to remove build files
# - Reduced duplication and improved readability
build/test_rect_basic_methods.out: src/rect.cpp tests/test_rect_basic_methods.cpp
	$(CXX) $(CXXFLAGS) -o build/test_rect_basic_methods.out tests/test_rect_basic_methods.cpp src/rect.cpp
