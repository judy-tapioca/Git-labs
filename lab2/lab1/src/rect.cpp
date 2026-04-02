
#include "rect.hpp"
#include <iostream>

 
/**Rect::Rect() {
    left   = 0;
    right  = 0;
    top    = 0;
    bottom = 0;
    std::cout << "Default constructor called for " << this << std::endl;
}
*/
Rect::Rect() : Rect(0, 0, 0, 0) {
    std::cout << "Default constructor called for " << this << std::endl;
}
/**Rect::Rect(int left, int right, int top, int bottom) {
    this->left   = left;
    this->right  = right;
    this->top    = top;
    this->bottom = bottom;
    std::cout << "Parameterized constructor called for " << this << std::endl;
}
*/

/**Rect::Rect(int left, int right, int top, int bottom)
    : left(left), right(right), top(top), bottom(bottom) {
    std::cout << "Parameterized constructor called for " << this << std::endl;
}
*/
Rect::Rect(int left, int right, int top, int bottom)
    : left(left), top(top), width(right - left), height(bottom - top) {
    std::cout << "Parameterized constructor called for " << this << std::endl;
}

/*Rect::Rect(const Rect &other) 
    : left(other.left), right(other.right), top(other.top), bottom(other.bottom) {
    std::cout << "Copy constructor called for " << this 
              << " from " << &other << std::endl;
}
*/
Rect::Rect(const Rect &other)
    : left(other.left), top(other.top), width(other.width), height(other.height) {
    std::cout << "Copy constructor called for " << this
              << " from " << &other << std::endl;
}

Rect::~Rect() {
    std::cout << "Destructor called for " << this << std::endl;
}


/*int Rect::get_left()   const { return left; }
int Rect::get_right()  const { return right; }
int Rect::get_top()    const { return top; }
int Rect::get_bottom() const { return bottom; }
*/
int Rect::get_left()   const { return left; }
int Rect::get_right()  const { return left + width; }
int Rect::get_top()    const { return top; }
int Rect::get_bottom() const { return top + height; }

/*void Rect::set_all(int left, int right, int top, int bottom) {
    this->left   = left;
    this->right  = right;
    this->top    = top;
    this->bottom = bottom;
}
*/
void Rect::set_all(int left, int right, int top, int bottom) {
    this->left   = left;
    this->top    = top;
    this->width  = right - left;
    this->height = bottom - top;
}



void Rect::inflate(int amount) {
    inflate(amount, amount, amount, amount);
}
/**void Rect::inflate(int amount) {
    left   -= amount;
    right  += amount;
    top    -= amount;
    bottom += amount;
}
*/

/*void Rect::inflate(int dw, int dh) {
    left   -= dw;
    right  += dw;
    top    -= dh;
    bottom += dh;
}
*/
void Rect::inflate(int dw, int dh) {
    inflate(dw, dw, dh, dh);
}
/*void Rect::inflate(int d_left, int d_right, int d_top, int d_bottom) {
    left   -= d_left;
    right  += d_right;
    top    -= d_top;
    bottom += d_bottom;
}
*/
void Rect::inflate(int d_left, int d_right, int d_top, int d_bottom) {
    left   -= d_left;
    width  += d_left + d_right;
    top    -= d_top;
    height += d_top + d_bottom;
}
/*void Rect::move(int dx, int dy) {
    left   += dx;
    right  += dx;
    top    += dy;
    bottom += dy;
}
*/
void Rect::move(int dx, int dy) {
    left += dx;
    top  += dy;
}

/*int Rect::get_width()  const { return right - left; }
int Rect::get_height() const { return bottom - top; }
int Rect::get_square() const { return get_width() * get_height(); }
*/

int Rect::get_width()  const { return width; }
int Rect::get_height() const { return height; }
int Rect::get_square() const { return width * height; }

/*void Rect::set_width(int width)   { right  = left + width; }
void Rect::set_height(int height) { bottom = top + height; }
*/
void Rect::set_width(int w)  { width = w; }
void Rect::set_height(int h) { height = h; }

Rect bounding_rect(const Rect& r1, const Rect& r2)  {
    Rect result;
    result.set_all(
        r1.get_left()   < r2.get_left()   ? r1.get_left()   : r2.get_left(),
        r1.get_right()  > r2.get_right()  ? r1.get_right()  : r2.get_right(),
        r1.get_top()    < r2.get_top()    ? r1.get_top()    : r2.get_top(),
        r1.get_bottom() > r2.get_bottom() ? r1.get_bottom() : r2.get_bottom()
    );
    return result;
}


void print_rect(const Rect &r) {
    int width  = r.get_width();
    int height = r.get_height();

    std::cout << std::endl;
    std::cout << "width: "  << width  << std::endl;
    std::cout << "height: " << height << std::endl;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}