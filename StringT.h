#pragma once
#include <iostream>


class StringT
{
private:
	size_t stringSize;
	size_t stringCapacity;
	char* array = nullptr;
public:
	//constructors
	StringT();
	StringT(const char* charArray);
	StringT(const StringT& string);

	const char* data();

	//destructors
	~StringT();

	//capacity and size
	size_t size();
	size_t length();
	size_t capacity();
	void clear();
	bool empty();

	//Element access
	char& back();
	char& front();
	char& operator[](int position);


	//append methods
	StringT& append(const StringT& str);
	
	StringT& append(const StringT& str, size_t subpos, size_t sublen);
	StringT& append(const char* s);
	StringT& append(const char* s, size_t n);
	StringT& append(size_t n, char c);



	StringT operator+(const char character);
	StringT operator+(const char* characterArray);
	StringT operator+(const StringT string);
	StringT& operator=(const StringT& string);
	StringT& operator=(const char* characterArray);
	
	
	friend std::ostream& operator<<(std::ostream & out, StringT string);

	bool contains(const char character);

};

