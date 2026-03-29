#include "../src/rect.hpp"

// #define MYASSERT(condition) if (!(condition)) return 1;

int main() {
    Rect r1(1, 2, 3, 4);

    // MYASSERT(r1.get_bottom() == 1);


    if (r1.get_left() != 1) return 1; // ERROR
    if (r1.get_bottom() != 3) return 1;
    
    return 0; // ALL PASSED
}