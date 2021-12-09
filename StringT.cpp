#pragma once
#include "StringT.h"

#include<iostream>


StringT::StringT(){
	size_t stringSize = 0;
	this->stringCapacity = 20;
	this->array = (char*)calloc(this->stringCapacity, 1);
		//std::cout << this->array;
}
StringT::~StringT() {
	if (this->array)
		delete[] array;
}
StringT::StringT(const char* charArray) {
	this->stringSize = std::strlen(charArray);
	this->stringCapacity = this->stringSize + 1 + 20;
	this->array = (char*)std::calloc(this->stringCapacity, 1);
	std::memcpy(this->array, charArray, this->stringSize + 1);
}
StringT::StringT(const StringT& string) {
	this->stringSize = string.stringSize;
	this->stringCapacity = string.stringCapacity;
	if (this->array)
		delete[] this->array;
	if (this->stringCapacity > 0) 
		this->array = (char*)calloc(this->stringCapacity, 1);
	if (this->stringSize > 0) 
		std::memcpy(this->array, string.array, this->stringSize + 1);

}
const char* StringT::data() {
	return this->array;
}
size_t StringT::size()
{
	return this->stringSize;
}
size_t StringT::length()
{
	return this->stringSize;
}
size_t StringT::capacity()
{
	return this->stringCapacity;
}
void StringT::clear()
{
	this->stringSize = 0;
	this->stringCapacity = 20;
	delete[] this->array;
	this->array = (char*)calloc(this->stringCapacity, 1);
}
bool StringT::empty()
{
	if (this->stringSize == 0)
		return true;
	return false;
}
char& StringT::back()
{
	return (this->array[this->stringSize - 1]);
}
char& StringT::front()
{
	return this->array[0];
}
char&  StringT::operator[](int position)
{
	if (position >= 0 && position < this->stringSize)
		return this->array[position];
	else
		throw std::out_of_range("Index out of range");
}
StringT StringT::operator+(const char character) {
	StringT r = *this;

	if (r.stringSize + 2 > r.stringCapacity) {
		r.stringCapacity = r.stringCapacity + 20;
		char* newArray = (char*)std::calloc(r.stringCapacity, 1);
		std::memcpy(newArray, r.array, r.stringSize + 1);
		newArray[r.stringSize] = character;
		newArray[r.stringSize + 1] = '\0';
		delete[] r.array;
		r.array = newArray;
		r.stringSize++;
	}
	else {
		r.array[r.stringSize] = character;
		r.array[r.stringSize + 1] = '\0';
		r.stringSize++;
	}
	return r;
}
StringT StringT::operator+(const char* characterArray) {
	StringT r = *this;

	if (r.stringSize + 1 + std::strlen(characterArray) > r.stringCapacity) {
		r.stringCapacity = r.stringCapacity + 20 + std::strlen(characterArray);
		char* newArray = (char*)std::calloc(r.stringCapacity, 1);
		std::memcpy(newArray, r.array, r.stringSize);
		std::memcpy(&newArray[r.stringSize], characterArray, 1 + std::strlen(characterArray));
		newArray[r.stringSize + 1 + std::strlen(characterArray)] = '\0';
		delete[] r.array;
		r.array = newArray;
		r.stringSize = r.stringSize + std::strlen(characterArray);
	}
	else {
		std::memcpy(&r.array[r.stringSize], characterArray, 1 + std::strlen(characterArray));
		r.array[r.stringSize + 1 + std::strlen(characterArray)] = '\0';
		r.stringSize = r.stringSize + std::strlen(characterArray);
	}
	return r;
}

StringT StringT::operator+(const StringT string) {
	return *this + string.array;
}
StringT& StringT::operator=(const StringT& string) {
	if (this != &string) {
		this->stringSize = string.stringSize;
		this->stringCapacity = string.stringCapacity;
		if (this->array)
			delete[] array;
		if (this->stringCapacity > 0) 
			this->array = (char*)calloc(this->stringCapacity, 1);
		if (this->stringSize > 0)
			std::memcpy(this->array, string.array, this->stringSize + 1);
	}
	return *this;
}
StringT& StringT::operator=(const char* characterArray)
{
	this->stringSize = std::strlen(characterArray);
	this->stringCapacity = this->stringSize + 20;
	if (this->array)
		delete[] array;
	if (this->stringSize > 0) {
		this->array = (char*)calloc(this->stringCapacity, 1);
		std::memcpy(this->array, characterArray, this->stringSize + 1);
	}
	else
		this->array = NULL;

	return *this;
}
StringT& StringT::append(const char *s) {
	try {
		*this = *this + s;
		return *this;
	}
	catch (std::exception e) {
		std::cerr << e.what();
		return *this;
	}
}
StringT& StringT::append(const char* s, size_t n)
{
	
	if (strlen(s) >= n) {
		for (int i = 0; i < n; i++)
			*this = *this + s[i];
	}
	else {
		for (int i = 0; i < strlen(s); i++)
			*this = *this + s[i];
	}
	return *this;
}
StringT& StringT::append(size_t n, char c)
{
	for (int i = 0; i < n; i++) {
		*this = *this + c;
	}
	return *this;
}
StringT& StringT::append(const StringT& string) {
	try {
		*this = *this + string;
		return *this;
	}
	catch (std::exception e) {
		std::cerr << e.what();
		
	}
}
bool StringT::contains(const char character) {
	if (strchr(this->array, character) != NULL)
		return true;
	else
		return false;
}
StringT& StringT::append(const StringT& str, size_t subpos, size_t sublen)
{
	if (subpos < str.stringSize)
	{
		if (subpos + sublen <= str.stringSize) {
			for (int i = subpos; i < subpos + sublen; i++)
				*this = *this + str.array[i];
		}
		else {
			for (int i = subpos; i < str.stringSize; i++)
				*this = *this + str.array[i];
		}
	}

	return *this;
}
std::ostream& operator<<(std::ostream& out, StringT string)
{
	if (string.size() > 0)
		out << string.data();
	return out;
}


