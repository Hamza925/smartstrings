#include <cstdlib>
#include <iostream>
#include<cstring>
#include "StringBuffer.h"
#include "String.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //create a smart string
//    String ss;
    //create a smart string with const char*
     char* hello = "hello";
    
    
    
    String ss2(hello,5);
    std::cout<<"ss2 length = "<<ss2.length()<<std::endl;
    cout<<hello<<endl;
    //multiple references
    String ss(ss2);
    cout<<hello<<endl;
    //output statements
    std::cout<<"ss length = "<<ss.length()<<std::endl;
    std::cout<<"new ss charAt 0 = "<<ss.charAt(0)<<std::endl;
    
    //append a character
    ss2.append('w');
    
    //cout<<hello<<endl;
    //hello = "bye";
    
    std::cout<<"new ss length = "<<ss.length()<<std::endl;
    std::cout<<"new ss2 length = "<<ss2.length()<<std::endl;
	getchar();
    return 0;
}
