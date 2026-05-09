# Test 1
add_executable(test_bounding_rect test_bounding_rect.cpp)
target_link_libraries(test_bounding_rect PRIVATE DataLogic)
add_test(NAME BoundingRectTest COMMAND test_bounding_rect)

# Test 2
add_executable(test_rect_basic test_rect_basic_properties.cpp)
target_link_libraries(test_rect_basic PRIVATE DataLogic)
add_test(NAME RectBasicTest COMMAND test_rect_basic)

# Test 3
add_executable(test_rect_operations test_rect_operations.cpp)
target_link_libraries(test_rect_operations PRIVATE DataLogic)
add_test(NAME RectOperationsTest COMMAND test_rect_operations)