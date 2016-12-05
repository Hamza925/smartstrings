#include "StringBuffer.h"
#include "String.h"
#include <memory>
#include <iostream>

using namespace std;
//default constructor

String::String() {
    this->_str = new StringBuffer();
}
//destructor

String::~String() {

    // free the memory only if the owned pointer is set

    if (this->owned) {
        delete  this->_str;
    }
}

//copy a const String into this string

String::String(const String& newString) {
	newString.owned=false;
    this->_str = newString._str;
    this->owned=true;
}

//copy a char* into your string

String::String(char* newString, int length) {
    this->_str = new StringBuffer(newString, length);
    //increment the refcount by 1
    this->owned=true;

}

void String::append(char c) {

	   //copy the new character at the end of this string
    this->_str->reserve(this->_str->length() + 1);
    this->_str->append(c);

}

void String::release() {
    this->owned=false;

}


//get length of the string

int String::length() const {
    return this->_str->length();
}

//get character at index if it is less than length

char String::charAt(int index) const {
    if (index < this->_str->length()) {
        return this->_str->charAt(index);
    } else {
        //throw new IndexOutOfBoundException();

    }
}
