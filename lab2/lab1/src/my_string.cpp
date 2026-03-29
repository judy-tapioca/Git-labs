#include "my_string.hpp"
#include <cstring>
#include <iostream>

// TODO: make sure that you do not allocate dynamic memory for empty string 

MyString::MyString() : data(nullptr), len(0) {
  data = new char[1];
  data[0] = '\0';
}

MyString::MyString(const char *str) {
  if (str) {  //checks if str is not null
    len = std::strlen(str);
    data = new char[len + 1];
    std::strcpy(data, str);
  } else {
    len = 0;
    data = new char[1];
    data[0] = '\0';
  }
}

MyString::MyString(const MyString &other) : len(other.len) {
  data = new char[len + 1];
  std::strcpy(data, other.data);
}

MyString &MyString::operator=(const MyString &other) {
  if (this != &other) {
    delete[] data;
    len = other.len;
    data = new char[len + 1];
    std::strcpy(data, other.data);
  }
  return *this;
}

MyString::~MyString() { delete[] data; }

char MyString::get(int i) const {
  if (i < 0 || i >= len)
    return '\0';
  return data[i];
}

void MyString::set(int i, char c) {
  if (i >= 0 && i < len)
    data[i] = c;
}

void MyString::set_new_string(const char *str) {
  delete[] data;
  if (str) {
    len = std::strlen(str);
    data = new char[len + 1];
    std::strcpy(data, str);
  } else {
    len = 0;
    data = new char[1];
    data[0] = '\0';
  }
}

void MyString::print() const {
  if (data)
    std::cout << data << std::endl;
}

void MyString::read_line() {
  delete[] data;
  char buffer[1024]; // Simple buffer for reading
  if (std::cin.getline(buffer, 1024)) { // reads a full line from the console into buffer
    len = std::strlen(buffer);
    data = new char[len + 1];
    std::strcpy(data, buffer);
  } else {
    len = 0;
    data = new char[1];
    data[0] = '\0';
  }
}

int MyString::length() const { return len; }


const char* MyString::get_cstr() const {
    return data;  //returns the raw C-string stored inside the object
}
