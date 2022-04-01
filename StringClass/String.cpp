#include<iostream>
#include<cstring>
#include "String.h"


String::String(const char* string)
{
	int stringSize;
	stringSize = strlen(string);
	char* pString = new char[stringSize + 1];

	strcpy_s(pString, stringSize + 1, string);
	pmString = pString;
}

String::~String()
{
	delete[] pmString;
	pmString = nullptr;
}

void String::Print()
{
	std::cout << pmString << std::endl;
}
