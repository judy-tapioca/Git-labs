#ifndef TEXT_WRAPPER_HPP
#define TEXT_WRAPPER_HPP

#include <cstring>
#include <iostream>
#include "my_string.hpp"


class TextWrapper {
private:
    int line_width;        // maximum line width
    char* words;           // copy of input text
    int word_lenght;       // length of input text
    int charIndex;         // current position when printing long word

    // condition methods
    bool word_length_check() const;

    // action methods
    void short_word() const;
    void long_word();

public:
    TextWrapper(const MyString& input, int width);
    ~TextWrapper();

    void print_wrapped();
};


#endif ghj