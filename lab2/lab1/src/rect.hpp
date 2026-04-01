#ifndef RECT_HPP
#define RECT_HPP


class Rect {
private:
    int left;
    int right;
    int top;
    int bottom;

  
   public:
   Rect(); //  i added a default constructor,to fix the error caused by the default constructor
   Rect(int left, int right, int top, int bottom); // Parameterized constructor — accepts 4 coordinates
   Rect(const Rect &other); // Creates a copy of another rectangle
   ~Rect();  // Called when rectangle is destroyed(when it goes out the scoop)


  //getter
  int get_left() const;
  int get_right() const;
  int get_top() const;
  int get_bottom() const;

  void set_all(int left, int right, int top, int bottom); //Sets ALL four coordinates of the rectangle at once.

  // Behavior: Methods that calculate or manipulate the state.
  void inflate(int amount);//Expands the rectangle by the same amount on all 4 sides
  void inflate(int dw, int dh);//Expands by different amounts horizontally and vertically
  void inflate(int d_left, int d_right, int d_top, int d_bottom);//

  void move(int dx, int dy = 0);

  int get_width() const; //Changes the width by moving only right, keeping left fixed.
  int get_height() const;//Changes the height by moving only bottom, keeping top fixed.
  int get_square() const;//Expands each side independently

  // Setter
  void set_width(int width);
  void set_height(int height);


};
 
void print_rect( const Rect &r);
Rect bounding_rect(const Rect& r1, const Rect& r2);
   
#endif // RECT_HPP
