#ifndef MY_STRING_HPP
#define MY_STRING_HPP


class MyString {
public:
  MyString();                // Default constructor
  MyString(const char *str); // Constructor from C-string

  const char* get_cstr() const;  //gets the string from mystring 

  MyString(const MyString &other);
  MyString &operator=(const MyString &other);
  ~MyString();

  char get(int i) const; // get character at position i
  void set(int i, char c); // set character at position i
  void set_new_string(const char *str); // replace current string
  void print() const; // print to console
  void read_line(); // read from console

  int length() const;

private:
  char *data; // Pointer pointer that points to the first character of the string on the heap
  int len; // stores the length of the string

 
  
};



#endif 
