#include "text_wrapper.hpp"
#include <cstring>
#include <cstdlib>
#include <iostream>


TextWrapper::TextWrapper(const MyString& input, int width) {  
    line_width = width;   // save the max line width into the member variable
    word_lenght = strlen(input.get_cstr());   //keeps the total number of characters of the string

    int len = word_lenght + 1; // holds the length of the text plus the null terminator 
    words = new char[len];  //dynamic allocation of memory on the heap for the string 
    strcpy(words, input.get_cstr());          
    charIndex = 0;
}



//destructor
TextWrapper::~TextWrapper() {
    delete[] words;
    words = nullptr;
    std::cout << "memory succesfuly released for my text wrapper" << std::endl;
}

// check if word is longer than line width
bool TextWrapper::word_length_check() const {  //first helper method. It checks whether the text is longer than the line width
    if (strlen(words) > (size_t)line_width)
        return true;
    else
        return false;
}

// main method — decides short or long word
void TextWrapper::print_wrapped() {
    if (word_length_check()) {
        long_word(); //called when line is too long ,uses charIndex
    } else {
        short_word();
    }
}

// print word that fits on one line
void TextWrapper::short_word() const {
    for (int i = 0; i < word_lenght; i++) {
        std::cout << words[i];
    }
    std::cout << std::endl; // move to new line after looping finishes
}

// TODO: splitting by words: do not break words

// print word that is too long — split across lines
/*void TextWrapper::long_word() {
    charIndex = 0; // ensures start to from the beginning of the line (resets the cursor back to the beginning of the text)

    // keep looping until every character has been printed
    // each iteration of this loop = one line of output
    while (charIndex < word_lenght) {
        int charsPrinted = 0;  // tracks how many characters have been printed on the CURRENT line

          // print one line worth of characters, stop when line is full OR text runs out
        for (; charsPrinted < line_width && charIndex < word_lenght; charsPrinted++) {
            std::cout << words[charIndex];  // print the character at the current position in words
            charIndex++;
        }

        // current line is full (or text ended) — move to the next line
        // then while loop starts again for the next line
        std::cout << std::endl;
    }*/ 
   void TextWrapper::long_word() {
    charIndex = 0;

    while (charIndex < word_lenght) {
        int charsOnLine = 0;

        // Keep adding words as long as they fit on the current line
        while (charIndex < word_lenght) {
            // Find the end of the next word
            int wordStart = charIndex;
            while (charIndex < word_lenght && words[charIndex] != ' ') {
                charIndex++;
            }
            int wordLen = charIndex - wordStart;

            // Check if the word fits on the current line
            // If line is empty, print the word even if it's too long (no choice)
            if (charsOnLine == 0) {
                // Print the word character by character
                for (int i = wordStart; i < wordStart + wordLen; i++) {
                    std::cout << words[i];
                }
                charsOnLine += wordLen;
            } else if (charsOnLine + 1 + wordLen <= line_width) {
                // Word fits with a space before it
                std::cout << ' ';
                for (int i = wordStart; i < wordStart + wordLen; i++) {
                    std::cout << words[i];
                }
                charsOnLine += 1 + wordLen;
            } else {
                // Word doesn't fit — put charIndex back to wordStart and break to next line
                charIndex = wordStart;
                break;
            }

            // Skip the space between words (if any)
            if (charIndex < word_lenght && words[charIndex] == ' ') {
                charIndex++;
            }
        }

        std::cout << std::endl;
    }
}

