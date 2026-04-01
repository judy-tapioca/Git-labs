CXX = g++
CXXFLAGS = -g -Wall

OBJ = build/rect.o build/my_string.o build/barrel.o build/text_wrapper.o build/matrix.o
TARGET = build/debug.out

all: $(TARGET)

$(TARGET): $(OBJ) src/main.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) src/main.cpp $(OBJ)

build/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f build/*.o build/*.out

build/test_rect_basic_properties.out: src/rect.cpp test/test_rect_basic_properties.cpp
	$(CXX) $(CXXFLAGS) -o build/test_rect_basic_properties.out test/test_rect_basic_properties.cpp src/rect.cpp

build/test_rect_operations.out: src/rect.cpp test/test_rect_operations.cpp
	$(CXX) $(CXXFLAGS) -o build/test_rect_operations.out test/test_rect_operations.cpp src/rect.cpp

build/test_bounding_rect.out: src/rect.cpp test/test_bounding_rect.cpp
	$(CXX) $(CXXFLAGS) -o build/test_bounding_rect.out test/test_bounding_rect.cpp src/rect.cpp

test: build/test_rect_basic_properties.out build/test_rect_operations.out build/test_bounding_rect.out
	./build/test_rect_basic_properties.out
	./build/test_rect_operations.out
	./build/test_bounding_rect.out
