#include "../src/rect.hpp"

#include <iostream>
#include <cassert>
#include "../src/rect.hpp"

using namespace std;

int main() {
    Rect r(1, 5, 2, 6);

    // Test get_width and get_height
    assert(r.get_width()  == 4);
    assert(r.get_height() == 4);

    // Test get_square
    assert(r.get_square() == 16);

    // Test set_width (moves right, keeps left fixed)
    r.set_width(10);
    assert(r.get_width()  == 10);
    assert(r.get_left()   == 1);  // left unchanged
    assert(r.get_right()  == 11);

    // Test set_height (moves bottom, keeps top fixed)
    r.set_height(8);
    assert(r.get_height() == 8);
    assert(r.get_top()    == 2);  // top unchanged
    assert(r.get_bottom() == 10);

    cout << "PASSED: all property methods are working" << endl;
    return 0;
}