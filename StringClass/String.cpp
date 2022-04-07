#include<iostream>
#include<cstring>
#include "String.h"


String::String()
{
	mLength = NULL_LENGTH;
	mpString = new char[mLength]{};
}

String::String(const String& string)
{
	mLength = string.mLength;
	mpString = new char[mLength + 1];
	strcpy_s(mpString, mLength + 1, string.mpString);
}

String::String(const char* string)
{
	int stringSize;
	stringSize = strlen(string);
	char* pString = new char[stringSize + 1];

	strcpy_s(pString, stringSize + 1, string);
	mpString = pString;
	mLength = stringSize;
}

String::~String()
{
	delete[] mpString;
	mpString = nullptr;
}

int String::GetLength()
{
	return mLength;
}

char* String::GetString()
{
	return mpString;
}

void String::Print()
{
	std::cout << mpString << std::endl;
}

char* String::operator+(const String& string)
{
	int stringLength{ this->mLength + string.mLength };
	char* plusString = new char[stringLength + 1];
	for (int i = 0; i <= this->mLength; i++)
	{
		plusString[i] = this->mpString[i];
	}
	for (int i = 0; i <= string.mLength+1; i++)
	{
		plusString[i + (this->mLength)] = string.mpString[i];
	}
	return plusString;
}

String& String::operator+=(const String& string)
{

	// TODO: 여기에 return 문을 삽입합니다.
}

String& String::operator=(const String& string)
{

	// TODO: 여기에 return 문을 삽입합니다.
}

String& String::operator[](const String& string)
{
	// TODO: 여기에 return 문을 삽입합니다.
}

std::ostream& operator<<(const std::ostream& os, const String& string)
{

}
