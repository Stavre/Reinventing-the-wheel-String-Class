// StringClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma once
#include <iostream>
#include "StringT.h"

int main()
{
    //StringT(const char* charArray);
    StringT b = StringT("Hell");
    StringT c("What a wonderful");
    
    //StringT& operator=(const char* characterArray);
    StringT d = " world!";
    
    
    //friend std::ostream& operator<<(std::ostream & out, StringT string);
    std::cout << b << std::endl;

    // char& back();
    std::cout << std::endl << b.back() << std::endl;

    //char& front();
    std::cout << std::endl << b.front() << std::endl;

    //StringT operator+(const char* characterArray);
    std::cout << std::endl<< b + "o!" << std::endl;

    //StringT operator+(const StringT string);
    std::cout << std::endl << c + d << std::endl;


    //StringT operator+(const char character);
    std::cout << std::endl << b + 'o' << std::endl;

    // StringT& append(const char* s);
    std::cout << std::endl << b.append("o!") << std::endl;
    std::cout << std::endl << b << std::endl;

    //StringT& append(const char* s, size_t n);
    std::cout << std::endl << b.append("What a wonderful world!", 13) << std::endl;
    std::cout << std::endl << b << std::endl;

    //StringT& append(size_t n, char c); 
    std::cout << std::endl << b.append(6, '.') << std::endl;
    std::cout << std::endl << b << std::endl;

    //StringT& append(const StringT & str, size_t subpos, size_t sublen);
    std::cout << std::endl << b.append(c, 0, 23) << std::endl;
    std::cout << std::endl << b << std::endl;

    //StringT& append(const StringT& str);
    std::cout << std::endl << b.append(d) << std::endl;
    std::cout << std::endl << b << std::endl;

    //bool contains(const char character);
    std::cout << std::endl << b.contains('4') << std::endl;
    std::cout << std::endl << b << std::endl;

    // size_t size();
    std::cout << std::endl << b.size() << std::endl;
    
    //size_t length();
    std::cout << std::endl << b.length() << std::endl;

    //size_t capacity();
    std::cout << std::endl << b.capacity() << std::endl;


    std::cout << std::endl << b.back() << std::endl;
    std::cout << std::endl << b.front() << std::endl;
    std::cout << std::endl << b.data() << std::endl;

    //bool empty();
    std::cout << std::endl << "is empty? "<< b.empty() << std::endl;

    //void clear();
    b.clear();


    std::cout << std::endl << b << std::endl;
    std::cout << std::endl << b.data() << std::endl;
    std::cout << std::endl << b.size() << std::endl;
    std::cout << std::endl << b.capacity() << std::endl;
    std::cout << std::endl << b.back() << std::endl;
    std::cout << std::endl << b.front() << std::endl;


    std::cout << std::endl << b + "o!" << std::endl;
    std::cout << std::endl << b + 'o' << std::endl;


}

