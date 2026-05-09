#include <iostream>
#include <cassert>
#include "../src/rect.hpp"

using namespace std;

int main()
{
    // r1: left=1, right=4, top=1, bottom=3  → width=3, height=2, area=6
    // r2: left=2, right=7, top=0, bottom=5  → width=5, height=5, area=25
    Rect r1(1, 4, 1, 3), r2(2, 7, 0, 5);
    Rect r3 = bounding_rect(r1, r2);

    // Bounding rect: left=1, right=7, top=0, bottom=5 → width=6, height=5, area=30
    // r3 must be strictly larger than both r1 and r2
    assert(r3.get_square() > r1.get_square());
    assert(r3.get_square() > r2.get_square());

    // Verify exact bounding dimensions
    assert(r3.get_left()   == 1);
    assert(r3.get_right()  == 7);
    assert(r3.get_top()    == 0);
    assert(r3.get_bottom() == 5);
    assert(r3.get_square() == 30);

    cout << "PASSED: all operations methods are working" << endl;
}