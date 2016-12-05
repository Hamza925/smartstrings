#include "StringBuffer.h"
#include "String.h"
#include <memory>
#include <iostream>

using namespace std;
//default constructor

String::String() {
    this->_str = new StringBuffer();
    this->_prev=this;
    this->_next=this;
}
//destructor

String::~String() {

    // if the length is equal to one delete the object
	if (this->_next==this && this->_prev == this)
	{
        delete  this->_str;
	}
	else
	{
		this->_next->_prev=this->_prev;
		this->_prev->_next=this->_next;
		this->_next=NULL;
		this->_prev=NULL;
		this->_str=NULL;
	}

	// remove this node from the list .



}

//copy a const String into this string

String::String(const String& newString) {

    this->_str = newString._str;
    this->_next= newString._next;
    this->_prev= newString._next->_prev;
    this->_next->_prev=this;
    this->_prev->_next=this;


}

//copy a char* into your string

String::String(char* newString, int length) {
    this->_str = new StringBuffer(newString, length);
    this->_prev=this;
    this->_next=this;
}

void String::append(char c) {

	//copy the new character at the end of this string
	// if there is a single node in loop then don't create a new string
	if (this->_next==this && this->_prev==this)
	{
		// a single node
		// no need to create another string
		this->_str->reserve(this->_str->length() + 1);
		this->_str->append(c);

	}
	else
	{
		// create a string
		StringBuffer * newdata(new StringBuffer);
		newdata->reserve(this->_str->length()+1);
		newdata->smartCopy(this->_str);
		newdata->append(c);
		this->_str=newdata;

		// remove this node from the list
		this->_next->_prev=this->_prev;
		this->_prev->_next=this->_next;
		this->_next=this;
		this->_prev=this;
	}

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
