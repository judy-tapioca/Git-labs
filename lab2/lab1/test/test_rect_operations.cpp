
#include <iostream>
#include <cassert> // Required for assert()
#include "../src/rect.hpp"

using namespace std;

int main()
{
    
    Rect r1;

    // inflate(3): all sides expand by 3
    r1.inflate(3);
    assert(r1.get_left()   == -3);
    assert(r1.get_right()  ==  3);
    assert(r1.get_top()    == -3);
    assert(r1.get_bottom() ==  3);

    // inflate(2, 3): expand width by 2, height by 3
    r1.inflate(2, 3);
    assert(r1.get_left()   == -5);
    assert(r1.get_right()  ==  5);
    assert(r1.get_top()    == -6);
    assert(r1.get_bottom() ==  6);

    // inflate(2, 3, 4, 5): expand each side independently
    r1.inflate(2, 3, 4, 5);
    assert(r1.get_left()   == -7);
    assert(r1.get_right()  ==  8);
    assert(r1.get_top()    == -10);
    assert(r1.get_bottom() ==  11);

    // move(2, 1): shift right by 2, down by 1
    r1.move(2, 1);
    assert(r1.get_left()   == -5);
    assert(r1.get_right()  ==  10);
    assert(r1.get_top()    == -9);
    assert(r1.get_bottom() ==  12);

    cout << "PASSED: all operations methods are working" << endl;
    return 0;
}